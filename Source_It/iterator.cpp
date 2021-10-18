#include<iterator_source.h>
#include<source.h>
#include<iostream>
#include<ip_header.h>

PcapFile_It::PcapFile_It(Pcap_File* source,pcap_t* fp):source{source},fp{fp}
{
    
}


ip_header* PcapFile_It::Get_Next_Packet_Info()
{
    pcap_pkthdr* head;
    const u_char* data;
    struct ip_header* my_ip{new ip_header()};
    
    auto ret=pcap_next_ex(fp,&head,&data);
    if (ret != 1)//if it is no more packet to read, return 0
    {
        my_ip->SOURCE_IP_ADRESS[0]=0;
        return my_ip;
    }

    for (size_t i = 0; i < 4; i++)
    {
        my_ip->SOURCE_IP_ADRESS[i]=static_cast<int>(data[i+PACKET_SIZE]);
    }
    
    for (size_t i = 0; i < 4; i++)
    {
        my_ip->DEST_IP_ADRESS[i]=static_cast<int>(data[i+PACKET_SIZE+4]);
    }
    
    return my_ip;
    
}