/*
 * Struct to store flow created.
 */
struct rte_flow
{
	TAILQ_ENTRY(rte_flow) node;
	enum rte_filter_type filter_type;
	void *rule;
};
