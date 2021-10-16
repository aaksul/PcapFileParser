#include<iostream>
#include<collection.h>
#include<ip_header.h>


Packet_collection::Packet_collection(): size{0}, packets{}{

}

void Packet_collection::Add_Packet(const struct ip_header* my_ip){

        auto begin{ std::begin(packets) };
        auto end{ std::end(packets) };
        auto packet = packets.find(my_ip->SOURCE_IP_ADRESS);
        bool find=false;
        for (auto ptr{begin}; ptr != end && find !=true ; ptr++)
        {
            auto source=ptr->first;
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

void Packet_collection::Filter(const u_char&){

}

void Packet_collection::List_Packet(){
    
    auto begin{ std::begin(packets) };
    auto end{ std::end(packets) };
        
    for (auto ptr{begin}; ptr != end ; ptr++)
    {
        std::cout << ptr->first[0] <<"."<< ptr->first[1] <<"."<< ptr->first[2] <<"."<< ptr->first[3] << "\t has sent " << ptr->second.size() <<" packet" <<"\n" ;         
        
    }
    
    
    
}