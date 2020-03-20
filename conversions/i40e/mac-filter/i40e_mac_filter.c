/* MAC filter list structure */
struct i40e_mac_filter
{
	TAILQ_ENTRY(i40e_mac_filter) next;
	struct i40e_mac_filter_info mac_info;
};