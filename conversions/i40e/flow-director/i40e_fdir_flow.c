/*
 * A union contains the inputs for all types of flow
 * items in flows need to be in big endian
 */
union i40e_fdir_flow
{
	struct rte_eth_l2_flow          l2_flow;
	struct rte_eth_udpv4_flow       udp4_flow;
	struct rte_eth_tcpv4_flow       tcp4_flow;
	struct rte_eth_sctpv4_flow      sctp4_flow;
	struct rte_eth_ipv4_flow        ip4_flow;
	struct rte_eth_udpv6_flow       udp6_flow;
	struct rte_eth_tcpv6_flow       tcp6_flow;
	struct rte_eth_sctpv6_flow      sctp6_flow;
	struct rte_eth_ipv6_flow        ipv6_flow;
	struct i40e_gtp_flow            gtp_flow;
	struct i40e_gtp_ipv4_flow       gtp_ipv4_flow;
	struct i40e_gtp_ipv6_flow       gtp_ipv6_flow;
	struct i40e_raw_flow            raw_flow;
	struct i40e_ipv4_l2tpv3oip_flow ip4_l2tpv3oip_flow;
	struct i40e_ipv6_l2tpv3oip_flow ip6_l2tpv3oip_flow;
	struct i40e_esp_ipv4_flow       esp_ipv4_flow;
	struct i40e_esp_ipv6_flow       esp_ipv6_flow;
	struct i40e_esp_ipv4_udp_flow   esp_ipv4_udp_flow;
	struct i40e_esp_ipv6_udp_flow   esp_ipv6_udp_flow;
};

/* A structure used to define the input for GTP flow */
struct i40e_gtp_flow
{
	struct rte_eth_udpv4_flow udp; /* IPv4 UDP fields to match. */
	uint8_t msg_type;              /* Message type. */
	uint32_t teid;                 /* TEID in big endian. */
};

/* A structure used to define the input for GTP IPV4 flow */
struct i40e_gtp_ipv4_flow
{
	struct i40e_gtp_flow gtp;
	struct rte_eth_ipv4_flow ip4;
};

/* A structure used to define the input for GTP IPV6 flow */
struct i40e_gtp_ipv6_flow
{
	struct i40e_gtp_flow gtp;
	struct rte_eth_ipv6_flow ip6;
};

/* A structure used to define the input for ESP IPV4 flow */
struct i40e_esp_ipv4_flow
{
	struct rte_eth_ipv4_flow ipv4;
	uint32_t spi;	/* SPI in big endian. */
};

/* A structure used to define the input for ESP IPV6 flow */
struct i40e_esp_ipv6_flow
{
	struct rte_eth_ipv6_flow ipv6;
	uint32_t spi;	/* SPI in big endian. */
};

/* A structure used to define the input for ESP IPV4 UDP flow */
struct i40e_esp_ipv4_udp_flow
{
	struct rte_eth_udpv4_flow udp;
	uint32_t spi;	/* SPI in big endian. */
};

/* A structure used to define the input for ESP IPV6 UDP flow */
struct i40e_esp_ipv6_udp_flow
{
	struct rte_eth_udpv6_flow udp;
	uint32_t spi;	/* SPI in big endian. */
};

/* A structure used to define the input for raw type flow */
struct i40e_raw_flow
{
	uint16_t pctype;
	void *packet;
	uint32_t length;
};

/* A structure used to define the input for L2TPv3 over IPv4 flow */
struct i40e_ipv4_l2tpv3oip_flow
{
	struct rte_eth_ipv4_flow ip4;
	uint32_t session_id; /* Session ID in big endian. */
};

/* A structure used to define the input for L2TPv3 over IPv6 flow */
struct i40e_ipv6_l2tpv3oip_flow
{
	struct rte_eth_ipv6_flow ip6;
	uint32_t session_id; /* Session ID in big endian. */
};
