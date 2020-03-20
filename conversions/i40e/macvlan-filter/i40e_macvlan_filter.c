/* i40e MACVLAN filter structure */
struct i40e_macvlan_filter
{
	struct rte_ether_addr macaddr;
	enum rte_mac_filter_type filter_type;
	uint16_t vlan_id;
};