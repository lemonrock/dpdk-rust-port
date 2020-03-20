/* VSI list structure */
struct i40e_vsi_list
{
	TAILQ_ENTRY(i40e_vsi_list) list;
	struct i40e_vsi *vsi;
};