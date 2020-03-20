struct i40e_tunnel_rule
{
	struct i40e_tunnel_filter_list tunnel_list;
	struct i40e_tunnel_filter  **hash_map;
	struct rte_hash *hash_table;
};

struct i40e_tunnel_filter * i40e_sw_tunnel_filter_lookup(struct i40e_tunnel_rule *tunnel_rule, const struct i40e_tunnel_filter_input *input);
