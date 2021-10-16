


#ifndef MY_SOURCE_H
#define MY_SOURCE_H


#include<pcap.h>
class iterator;
class PcapFile_It;
class Isource
{
public:
    virtual iterator* Create_Iterator()=0;
    //
};


class source: public Isource
{
private:
    virtual iterator* Create_Iterator()=0;
public:
    //source(/* args */);
    //~source();
};

class Pcap_File: public source
{
private:
    pcap_t* fp;
public:
    Pcap_File(const char*);
    //~Pcap_File();
    virtual PcapFile_It* Create_Iterator() override;
};




#endif