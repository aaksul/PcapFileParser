#ifndef IP_HEADER
#define IP_HEADER

#define ETHERNET_SIZE 14
#define IP_SIZE 12
#define PACKET_SIZE ETHERNET_SIZE+IP_SIZE

struct ip_header
{
    int SOURCE_IP_ADRESS[4];
    int DEST_IP_ADRESS[4];
};

#endif
