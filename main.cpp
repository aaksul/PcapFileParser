#include <stdio.h>
#include <pcap.h>
#include<iterator_source.h>
#include<source.h>
#include<collection.h>

int main(int argc, char **argv)
{  

        Packet_collection col1=Packet_collection();
        auto x=Pcap_File(argv[1]);
        auto y=x.Create_Iterator();
        auto z=y->Get_Next_Packet_Info();
        col1.Add_Packet(z);
        int i{0};
        while (i!= 1000)
        {
                z=y->Get_Next_Packet_Info();
                col1.Add_Packet(z);
                i++;
        }

        col1.List_Packet();
        
         
                
}