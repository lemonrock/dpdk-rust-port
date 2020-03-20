/* A structure used to define the input for a flow director filter entry */
struct i40e_fdir_input
{
	enum i40e_filter_pctype pctype;
	union i40e_fdir_flow flow;
	/* Flow fields to match, dependent on flow_type */
	struct i40e_fdir_flow_ext flow_ext;
	/* Additional fields to match */
};
