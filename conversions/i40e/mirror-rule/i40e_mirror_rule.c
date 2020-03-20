#define I40E_MIRROR_MAX_ENTRIES_PER_RULE   64

#define I40E_MAX_MIRROR_RULES           64

/*
 * Mirror rule structure
 */
struct i40e_mirror_rule
{
	TAILQ_ENTRY(i40e_mirror_rule) rules;
	uint8_t rule_type;
	uint16_t index;          /* the sw index of mirror rule */
	uint16_t id;             /* the rule id assigned by firmware */
	uint16_t dst_vsi_seid;   /* destination vsi for this mirror rule. */
	uint16_t num_entries;
	/* the info stores depend on the rule type.
	    If type is I40E_MIRROR_TYPE_VLAN, vlan ids are stored here.
	    If type is I40E_MIRROR_TYPE_VPORT_*, vsi's seid are stored.
	 */
	uint16_t entries[I40E_MIRROR_MAX_ENTRIES_PER_RULE];
};
