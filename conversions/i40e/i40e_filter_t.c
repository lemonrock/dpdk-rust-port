
union i40e_filter_t
{
	struct rte_eth_ethertype_filter ethertype_filter;
	struct i40e_fdir_filter_conf fdir_filter;
	struct rte_eth_tunnel_filter_conf tunnel_filter;
	struct i40e_tunnel_filter_conf consistent_tunnel_filter;
	struct i40e_rte_flow_rss_conf rss_conf;
};