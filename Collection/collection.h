#include<iostream>
#include<iterator>
#include<map>
#include<vector>


class Icollection
{
public:
    virtual void Add_Packet(const struct ip_header*)=0; 
    virtual void Filter(const char*)=0; 
};


class collection:Icollection
{
private:
    /* data */
public:
    virtual void Add_Packet(const struct ip_header*)=0;
    virtual void Filter(const char*)=0; 
};


class Packet_collection:collection
{
private:
    std::map<const int*,std::vector<const struct ip_header*>> packets;
    int size;
public:
    Packet_collection(/* args */);
    virtual void Add_Packet(const struct ip_header*);
    virtual void Filter(const char*); 
    void List_Packet();
};

