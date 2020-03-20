/**
 * Strucute to store private data for each VF representor instance
 */
struct i40e_vf_representor
{
	uint16_t switch_domain_id;
	/**< Virtual Function ID */
	uint16_t vf_id;
	/**< Virtual Function ID */
	struct i40e_adapter *adapter;
	/**< Private data store of assocaiated physical function */
	struct i40e_eth_stats stats_offset;
	/**< Zero-point of VF statistics*/
};
