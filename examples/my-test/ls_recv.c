
/*********************************************
 * 使用tap/tun 虚拟接口，支持网卡多队列
 * 
 * export RTE_SDK=/home/wilsonhong/dpdk_study/share/dpdk/dpdk-stable8.2
 * export export RTE_TARGET=x86_64-native-linux-gcc
********************************************/

#define NUM_BUFS 1024
#define NB_REVD      8 
#define NB_SEND      8

#define BUF_SIZE    32
int gDpdkPortId = 0;   //eth0


static const struct rte_eth_conf port_conf_default = {
    .rxmode = {.max_rx_pkt_len = RTE_ETHER_MAX_LEN}
};




static void port_init(struct rte_mempool *mbuf_pool)
{
    //
    const int nb_rx_queues = NB_REVD;
    const int nb_tx_queues = NB_REVD;

    struct  rte_eth_conf port_conf = port_conf_default;

    rte_eth_dev_configure(gDpdkPortId, nb_rx_queues,nb_tx_queues,&port_conf);
    rte_eth_rx_eueue_setup(gDpdkPortId, 0, RX_RING_SIZE, rte_eth_ev_sockid(gDpdkPortId),mbuf_pool );

    rtrte_eth_dev_start(gDpdkPortId);

    rte_eth_promiscuous_enable(gDpdkPortId);

}



int main(int argc ,char *argv[])
{
    if(rte_eal_init(argc, argv) < 0 )
    {
        rte_exit(EXIT_FAILURE,"rte_eal_init failed\n");  //初始化环境参数，检查内存、巨页、网卡驱动
    }


    struct rte_mempool *pktmbuf_pool = rte_pktmbuf_pool_create("mbuf_pool",NB_MBUF,
                        MEMPOOL_CACHE_SZ, 0 , MBUF_DATA_SZ,,rte_socket_id());
    if(!pktmbuf_pool)
    {
        rte_exit(EXIT_FAILURE,"rte_pktmbuf_pool_create failed\n");
    }


    while (1)
    {
        struct rte_mbuf *mbuf[BUF_SIZE];
        
       unsigned num_revd =  rte_eth_rx_burst(gDpdkPortId, 0 , mbuf, BUF_SIZE);

        unsigned i = 0;
        for(i = 0;i < num_revd; i++)
        {
           struct  rte_ether_hdr *ehdr = rte_pktmbuf_mtod(mbuf[i],struct rte_ether_hdr*);          

           //协议解析  0.vxlan  1.arp 协议实现   icmp    2. ip/ udp:协议本省、sendto/recvfrom              3. igmp 4. tcp
        }
    }
    

}