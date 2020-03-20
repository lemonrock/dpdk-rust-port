struct i40e_ethertype_rule
{
	struct i40e_ethertype_filter_list ethertype_list;
	struct i40e_ethertype_filter  **hash_map;
	struct rte_hash *hash_table;
};

struct i40e_ethertype_filter * i40e_sw_ethertype_filter_lookup(struct i40e_ethertype_rule *ethertype_rule, const struct i40e_ethertype_filter_input *input);