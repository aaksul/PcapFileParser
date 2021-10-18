#include<iostream>
#include<collection.h>
#include<ip_header.h>
#include<string.h>
#include<math.h>

Packet_collection::Packet_collection(): size{0}, packets{}{

}

void Packet_collection::Add_Packet(const struct ip_header* my_ip){

        auto begin{ std::begin(packets) };
        auto end{ std::end(packets) };
        auto packet = packets.find(my_ip->SOURCE_IP_ADRESS);
        bool find=false;
        for (auto ptr{begin}; ptr != end && find !=true ; ptr++)
        {
            auto source=ptr->first;//source ip address
            for (size_t i = 0; i < 4 && source[i] == my_ip->SOURCE_IP_ADRESS[i] ; i++)
            {
                if(i==3)
                {
                    find=true;
                }
                
            }
            if (find)
            {
                ptr->second.push_back(my_ip);
            }
            
        }
        if(!find)
        {
            packets[my_ip->SOURCE_IP_ADRESS].push_back(my_ip);
        }
            
        
        this->size++;
}

void Packet_collection::Filter(const char* ip_adress){
    
    int offset{0};
    int ip_addr[4]={0,0,0,0};
    int ip_off{0};
    for (size_t i = 0; i < strlen(ip_adress); i++)
    {
        if(ip_adress[i]==46 || i == strlen(ip_adress)-1)
        {
            if(i == strlen(ip_adress)-1)
            {
                i++;
                offset++;
            }
            while (offset!=0)
            {
                int int_rep = (ip_adress[i-offset]-48);
                ip_addr[ip_off]+=int_rep*(pow(10,offset-1));    
                offset--;
            }

            ip_off++;                
        }
        else
        {
            offset++;
        }
    }
    auto begin{ std::begin(packets) };
    auto end{ std::end(packets) };
        
    for (auto ptr{begin}; ptr != end ; ptr++)
    {
        if(ptr->first[0]==ip_addr[0] && ptr->first[1]==ip_addr[1] && ptr->first[2]==ip_addr[2] && ptr->first[3]==ip_addr[3])
            std::cout << ptr->first[0] <<"."<< ptr->first[1] <<"."<< ptr->first[2] <<"."<< ptr->first[3] << "\t has sent " << ptr->second.size() <<" packet" <<"\n" ;         
        
    }
    
    
}

void Packet_collection::List_Packet(){
    
    auto begin{ std::begin(packets) };
    auto end{ std::end(packets) };
        
    for (auto ptr{begin}; ptr != end ; ptr++)
    {
        std::cout << ptr->first[0] <<"."<< ptr->first[1] <<"."<< ptr->first[2] <<"."<< ptr->first[3] << "\t has sent " << ptr->second.size() <<" packet" <<"\n" ;         
        
    }
    
    
    
}