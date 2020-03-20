/**
 * MAC filter structure
 */
struct i40e_mac_filter_info
{
	enum rte_mac_filter_type filter_type;
	struct rte_ether_addr mac_addr;
};