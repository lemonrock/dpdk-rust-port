/**
 * Tunneling Packet filter configuration.
 */
struct i40e_tunnel_filter_conf
{
	struct rte_ether_addr outer_mac;    /**< Outer MAC address to match. */
	struct rte_ether_addr inner_mac;    /**< Inner MAC address to match. */
	uint16_t inner_vlan;            /**< Inner VLAN to match. */
	uint32_t outer_vlan;            /**< Outer VLAN to match */
	enum i40e_tunnel_iptype ip_type; /**< IP address type. */
	/**
	 * Outer destination IP address to match if ETH_TUNNEL_FILTER_OIP
	 * is set in filter_type, or inner destination IP address to match
	 * if ETH_TUNNEL_FILTER_IIP is set in filter_type.
	 */
	union {
		uint32_t ipv4_addr;     /**< IPv4 address in big endian. */
		uint32_t ipv6_addr[4];  /**< IPv6 address in big endian. */
	} ip_addr;
	/** Flags from ETH_TUNNEL_FILTER_XX - see above. */
	uint16_t filter_type;
	enum i40e_tunnel_type tunnel_type; /**< Tunnel Type. */
	uint32_t tenant_id;     /**< Tenant ID to match. VNI, GRE key... */
	uint16_t queue_id;      /**< Queue assigned to if match. */
	uint8_t is_to_vf;       /**< 0 - to PF, 1 - to VF */
	uint16_t vf_id;         /**< VF id, avaiblable when is_to_vf is 1. */
};