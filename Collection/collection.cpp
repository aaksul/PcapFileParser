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
            auto source=ptr->first;//iterate over map select ip address which has been recorded
            //Control given as parameter ip_address with selected ip address 
            for (size_t i = 0; i < 4 && source[i] == my_ip->SOURCE_IP_ADRESS[i] ; i++)
            {
                if(i==3)//be sure all bytes are equal
                {
                    find=true;
                }
                
            }
            if (find)//if it is present, not create a new key-value, push to selected key's value
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
    //convert char ip address format to int example: "192.168.1.1" to int[4]{192.168.1.1}
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
    //filter given ip_address from command line     
    for (auto ptr{begin}; ptr != end ; ptr++)
    {
        if(ptr->first[0]==ip_addr[0] && ptr->first[1]==ip_addr[1] && ptr->first[2]==ip_addr[2] && ptr->first[3]==ip_addr[3])
        {
            std::cout << ptr->first[0] <<"."<< ptr->first[1] <<"."<< ptr->first[2] <<"."<< ptr->first[3] << "\t has sent " << ptr->second.size() <<" packet" <<"\n" ;         
            return;
        }    
    }
    std::cout<<"No record for given ip\n";
    
}

void Packet_collection::List_Packet(){
    
    auto begin{ std::begin(packets) };
    auto end{ std::end(packets) };
        
    for (auto ptr{begin}; ptr != end ; ptr++)
    {
        std::cout << ptr->first[0] <<"."<< ptr->first[1] <<"."<< ptr->first[2] <<"."<< ptr->first[3] << "\t has sent " << ptr->second.size() <<" packet" <<"\n" ;         
        
    }
    
    
    
}