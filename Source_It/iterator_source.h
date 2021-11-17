#ifndef ITERATOR_SOURCE
#define ITERATOR_SOURCE

#include<iostream>
#include<ip_header.h>

typedef struct pcap pcap_t;

class Iiterator
{
public:
    virtual ip_header* Get_Next_Packet_Info()=0;
};



class iterator: public Iiterator
{
private:
    /* data */
public:
    virtual ip_header* Get_Next_Packet_Info()=0;
    //iterator();
    //~iterator();
};


class PcapFile_It: public iterator
{
private:
    class Pcap_File* source;
    pcap_t* fp;
public:
    PcapFile_It(Pcap_File*,pcap_t*);
    //~PcapFile_It();
    virtual ip_header* Get_Next_Packet_Info();
};



#endif