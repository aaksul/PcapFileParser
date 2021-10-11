#include <stdio.h>
#include <pcap.h>
#include<collection.h>


int main(int argc, char **argv)
{
pcap_t *fp;
char errbuf[PCAP_ERRBUF_SIZE];
char source[PCAP_BUF_SIZE];
char* Fn;
    if(argc != 2){

        printf("usage: %s filename", argv[0]);
        return -1;

    }

Fn=argv[1];
auto x = pcap_open_offline(Fn,errbuf);

if (x==NULL)
{
    printf("Couldnt open file %s\n",Fn);
    return -1;
}


}