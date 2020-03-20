/* Struct to store Traffic Manager shaper profile. */
struct i40e_tm_shaper_profile
{
	TAILQ_ENTRY(i40e_tm_shaper_profile) node;
	uint32_t shaper_profile_id;
	uint32_t reference_count;
	struct rte_tm_shaper_params profile;
};
