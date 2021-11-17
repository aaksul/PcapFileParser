#ifndef PCAP_FILE_SOURCE
#define PCAP_FILE_SOURCE

#include<source.h>
#include<iterator_source.h>

class PcapFile_It;

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