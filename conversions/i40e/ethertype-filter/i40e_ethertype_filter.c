/* Ethertype filter number HW supports */
#define I40E_MAX_ETHERTYPE_FILTER_NUM 768

struct i40e_ethertype_filter
{
	TAILQ_ENTRY(i40e_ethertype_filter) rules;
	struct i40e_ethertype_filter_input input;
	uint16_t flags;              /* Flags from RTE_ETHTYPE_FLAGS_* */
	uint16_t queue;              /* Queue assigned to when match */
};
