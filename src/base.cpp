#include "base.h"
#include "visa.h"
#include "visatype.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <vector>
#include <xerrc.h>
#include <iostream>

bool VisaConnector::connect(std::string& resour)
{
    auto ret = viOpenDefaultRM(&m_identifier);
    printf("ret code = %ld\n",ret);
    ret = viOpen(m_identifier,resour.c_str(),VI_EXCLUSIVE_LOCK,1000,&m_session);

    if(ret != VI_SUCCESS)
    {
        printf("Connect failed!");
        throw std::exception("connect failed");
    }
    
    printf("connect success~!");
    return true;
}

bool VisaConnector::acQuire(std::string &name)
{
    std::string cmd("MMEMory:DATA? ");
    cmd += "\"" + name + "\"";
    unsigned long retCnt = 0;
    std::cout << "Write command: "<<cmd <<std::endl; 
    if(viWrite(m_session, (unsigned char *)cmd.c_str(), 
        (unsigned long)cmd.size(), &retCnt) != VI_SUCCESS)
        throw std::exception("Write failed!");

    printf("Write command success!\n");
    return true;
}

void VisaConnector::readData() 
{
    unsigned char sizeBuf[2];
    unsigned long ret = 0;
    if(viRead(m_session, sizeBuf, 2, &ret) != VI_SUCCESS_MAX_CNT)
        throw std::exception("Read failed, can not get size!");

    assert(sizeBuf[0] == '#');
    unsigned long len_size = sizeBuf[1] - '0';
    unsigned char lenBuf[len_size];

    if(viRead(m_session, lenBuf, len_size, &ret) != VI_SUCCESS_MAX_CNT)
        throw std::exception("Read failed, can not get length!");

    auto size = atoi((const char*)lenBuf);
    printf("total %d bytes need to read!\n",size);

    std::vector<unsigned char> buf;
    buf.resize(size);
    auto [times, remain] = std::div(size,4096); 

    for(int i = 0; i < times; i++)
    {
        if(viRead(m_session, &buf[i*4096], 4096,&ret) != VI_SUCCESS_MAX_CNT)
         throw std::exception("Read failed, can not get binary data!");                       
    }

    //read the reamin 
    if(viRead(m_session, &buf[times*4096], remain,&ret) != VI_SUCCESS_MAX_CNT)
         throw std::exception("Read failed, can not get binary data!");                       

    printf("Read complete, total %d bytes!\n",size);
    return ;
}