
/* A structure used to define the flow director filter entry by filter_ctrl API
 * It supports RTE_ETH_FILTER_FDIR with RTE_ETH_FILTER_ADD and
 * RTE_ETH_FILTER_DELETE operations.
 */
struct i40e_fdir_filter_conf
{
	uint32_t soft_id;
	/* ID, an unique value is required when deal with FDIR entry */
	struct i40e_fdir_input input;    /* Input set */
	struct i40e_fdir_action action;  /* Action taken when match */
};
