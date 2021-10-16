#include<iostream>
#include<collection.h>
#include<ip_header.h>


Packet_collection::Packet_collection(): size{0}, packets{}{

}

void Packet_collection::Add_Packet(const struct ip_header* my_ip){

        /*printf("%.d.",my_ip->SOURCE_IP_ADRESS[0]);
        printf("%.d.",my_ip->SOURCE_IP_ADRESS[1]);
        printf("%.d.",my_ip->SOURCE_IP_ADRESS[2]);
        printf("%.d.",my_ip->SOURCE_IP_ADRESS[3]);
        printf("\n");*/
        packets.push_back(my_ip);
        this->size++;
}

void Packet_collection::Filter(const u_char&){

}

void Packet_collection::List_Packet(){

    for (size_t i = 0; i < this->size; i++)
    {
        std::cout<<i+1<<"-Source Ip: ";
        for (size_t x = 0; x < 4; x++)
        {
            printf(".%d",packets[i]->SOURCE_IP_ADRESS[x]);
        }
        
        std::cout<<" Dest Ip: ";
        for (size_t x = 0; x < 4; x++)
        {
            printf(".%d",packets[i]->DEST_IP_ADRESS[x]);
        }
        printf("\n");
    }
    
}