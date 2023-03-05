#include<stdio.h>
#include<sys/poll.h>

#define NETMAP_WITH_LIBS


#pragma pack(1)

#define HWADDR_LRNGHTH 14 
#define PROTO_IP                    0X0800
#define PROTO_UDP                   17
struct nty_ethhdr
{
    unsigned char dst_addr[HWADDR_LRNGHTH];
    unsigned char src_addr[HWADDR_LRNGHTH];
    unsigned short type;
};

struct nty_iphdr
{
    unsigned char version:4;
    unsigned char hdrlen:4;
    
    unsigned char tos;
    unsigned short totlen;

    unsigned short id;
    
    unsigned short flag_offset;

    unsigned short ttl;

    unsigned char proto;

    unsigned short checksum;

    unsigned int sip;
    unsigned int dip;
};


struct nty_udphdr
{
    unsigned short sport;
    unsigned short dport;
    unsigned short length;
    unsigned short checksum;
};


struct nty_tcp
{
    unsigned int tmp;
};


//sizeof(struct nty_udppkt)
struct nty_udppkt
{
    struct nty_ethhdr eh;
    struct nty_iphdr ip;
    struct nty_udphdr udp;
    unsigned char data[0];         //零长数组/柔性数组  1.不确定长度 2.内存已经分配好了     内存池的使用：
};

//dpdk
//pf_ring
//raw_socket



