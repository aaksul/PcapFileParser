#include <stdio.h>
#include<pcap_file.h>
#include<iterator_source.h>
#include<collection.h>

int main(int argc, char **argv)
{  
        if(argv[1] ==NULL)
        {
                printf("usage %s filename [IP_ADRRESS]<OPT>\n",argv[0]);
                return 0;
        }
        Packet_collection collect=Packet_collection();
        auto file=Pcap_File(argv[1]);
        auto Iter_file=file.Create_Iterator();
        auto packet=Iter_file->Get_Next_Packet_Info();
        
        while (packet->SOURCE_IP_ADRESS[0] != 0)  
        {
                collect.Add_Packet(packet);
                packet=Iter_file->Get_Next_Packet_Info();
        }
        
        if (argv[2] == NULL)
        {
                collect.List_Packet();
        }
        else
        {
                collect.Filter(argv[2]);
        }

        
        
         
                
}