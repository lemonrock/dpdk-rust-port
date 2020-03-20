struct i40e_tunnel_filter
{
	TAILQ_ENTRY(i40e_tunnel_filter) rules;
	struct i40e_tunnel_filter_input input;
	uint8_t is_to_vf; /* 0 - to PF, 1 - to VF */
	uint16_t vf_id;   /* VF id, avaiblable when is_to_vf is 1. */
	uint16_t queue; /* Queue assigned to when match */
};
