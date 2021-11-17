#include<iterator_source.h>
#include<pcap_file.h>
#include<source.h>
#include<pcap.h>

Pcap_File::Pcap_File(const char* filename)
{
    
    char errbuf[PCAP_ERRBUF_SIZE];
    this->fp=pcap_open_offline(filename,errbuf);

}

PcapFile_It* Pcap_File::Create_Iterator()
{
    return new PcapFile_It(this,this->fp);
}