/* Struct to store Traffic Manager node configuration. */
struct i40e_tm_node
{
	TAILQ_ENTRY(i40e_tm_node) node;
	uint32_t id;
	uint32_t priority;
	uint32_t weight;
	uint32_t reference_count;
	struct i40e_tm_node *parent;
	struct i40e_tm_shaper_profile *shaper_profile;
	struct rte_tm_node_params params;
};
