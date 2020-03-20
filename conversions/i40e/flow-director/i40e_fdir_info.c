/*
 *  A structure used to define fields of a FDIR related info.
 */
struct i40e_fdir_info
{
	struct i40e_vsi *fdir_vsi;     /* pointer to fdir VSI structure */
	uint16_t match_counter_index;  /* Statistic counter index used for fdir*/
	struct i40e_tx_queue *txq;
	struct i40e_rx_queue *rxq;
	void *prg_pkt;                 /* memory for fdir program packet */
	uint64_t dma_addr;             /* physic address of packet memory*/
	/* input set bits for each pctype */
	uint64_t input_set[I40E_FILTER_PCTYPE_MAX];
	/*
	 * the rule how bytes stream is extracted as flexible payload
	 * for each payload layer, the setting can up to three elements
	 */
	struct i40e_fdir_flex_pit flex_set[I40E_MAX_FLXPLD_LAYER * I40E_MAX_FLXPLD_FIED];
	struct i40e_fdir_flex_mask flex_mask[I40E_FILTER_PCTYPE_MAX];

	struct i40e_fdir_filter_list fdir_list;
	struct i40e_fdir_filter **hash_map;
	struct rte_hash *hash_table;

	/* Mark if flex pit and mask is set */
	bool flex_pit_flag[I40E_MAX_FLXPLD_LAYER];
	bool flex_mask_flag[I40E_FILTER_PCTYPE_MAX];

	bool inset_flag[I40E_FILTER_PCTYPE_MAX]; /* Mark if input set is set */
};