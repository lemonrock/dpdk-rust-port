/* Ethertype filter struct */
struct i40e_ethertype_filter_input
{
	struct rte_ether_addr mac_addr;   /* Mac address to match */
	uint16_t ether_type;          /* Ether type to match */
};

int i40e_sw_ethertype_filter_del(struct i40e_pf *pf, struct i40e_ethertype_filter_input *input);