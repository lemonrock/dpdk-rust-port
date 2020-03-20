/* Structure that defines a VEB */
struct i40e_veb
{
	struct i40e_vsi_list_head head;
	struct i40e_vsi *associate_vsi; /* Associate VSI who owns the VEB */
	struct i40e_pf *associate_pf; /* Associate PF who owns the VEB */
	uint16_t seid; /* The seid of VEB itself */
	uint16_t uplink_seid; /* The uplink seid of this VEB */
	uint16_t stats_idx;
	struct i40e_eth_stats stats;
	uint8_t enabled_tc;   /* The traffic class enabled */
	uint8_t strict_prio_tc; /* bit map of TCs set to strict priority mode */
	struct i40e_bw_info bw_info; /* VEB bandwidth information */
};

static int i40e_veb_release(struct i40e_veb *veb);

/* Special FW support this floating VEB feature */
#define FLOATING_VEB_SUPPORTED_FW_MAJ 5
#define FLOATING_VEB_SUPPORTED_FW_MIN 0
