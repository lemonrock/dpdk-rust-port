struct i40e_rte_flow_rss_conf
{
	struct rte_flow_action_rss conf; /**< RSS parameters. */
	uint16_t queue_region_conf; /**< Queue region config flag */
	uint8_t key[(I40E_VFQF_HKEY_MAX_INDEX > I40E_PFQF_HKEY_MAX_INDEX ? I40E_VFQF_HKEY_MAX_INDEX : I40E_PFQF_HKEY_MAX_INDEX + 1) *  sizeof(uint32_t)]; /* Hash key. */
	uint16_t queue[I40E_MAX_Q_PER_TC]; /**< Queues indices to use. */
};

int i40e_rss_conf_init(struct i40e_rte_flow_rss_conf *out, const struct rte_flow_action_rss *in);