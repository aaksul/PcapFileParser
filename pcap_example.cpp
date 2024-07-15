#include <stdio.h>
#include <pcap.h>


int main(int argc, char **argv)
{
pcap_t *fp;
char errbuf[PCAP_ERRBUF_SIZE];
char source[PCAP_BUF_SIZE];
char* Fn;
const u_char* data;
struct pcap_pkthdr* header; 
u_int packetCount = 0;
/*
    if(argc != 2){

        printf("usage: %s filename", argv[0]);
        return -1;

    }
*/

Fn="/mnt/c/Users/alper/ubuntu/My_Project/data/smallFlows.pcap";
fp = pcap_open_offline(Fn,errbuf);

if (fp==NULL)
{
    printf("Couldnt open file %s\n",Fn);
    return -1;
}
int i = 0;

    while (int returnValue = pcap_next_ex(fp, &header, &data) >= 0)
    {

        // Show the packet number
        printf("Packet # %i\n", ++packetCount);
 
        // Show the size in bytes of the packet
        printf("Packet size: %d bytes\n", header->len);
 
        // Show a warning if the length captured is different
        if (header->len != header->caplen)
            printf("Warning! Capture size different than packet size: %ld bytes\n", header->len);
 
        // Show Epoch Time
        printf("Epoch Time: %d:%d seconds\n", header->ts.tv_sec, header->ts.tv_usec);
 
        // loop through the packet and print it as hexidecimal representations of octets
        // We also have a function that does this similarly below: PrintData()
        for (u_int i=0; (i < 1 ) ; i++)
        {
            printf("Dest Mac Adress:");    
            for (size_t x = 0; x < 6; x++)
            {
                // Print each octet as hex (x), make sure there is always two characters (.2).
                printf("%.2x ", data[x]);
            }
            printf("Host Mac Adress:");    
            for (size_t x = 6; x < 12; x++)
            {
                // Print each octet as hex (x), make sure there is always two characters (.2).
                printf("%.2x ", data[x]);
            }
            printf("TYPE:");
            for (size_t x = 12; x < 14; x++)
            {
                printf("%.2x ",data[x]);
            }
            printf("Source IP:");
            for (size_t i = 26; i < 30; i++)
            {
                printf(".%d",data[i]);
                /* code */
            }
            printf("Dest IP:");
            for (size_t i = 30; i < 34; i++)
            {
                printf(".%d",data[i]);
                /* code */
            }
        }
 
        // Add two lines between packets
        printf("\n\n");
    }


}
