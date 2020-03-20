#define I40E_MAX_PKT_TYPE  256
#define I40E_FLOW_TYPE_MAX 64

struct i40e_adapter;

/*
 * Structure to store private data for each PF/VF instance.
 */
struct i40e_adapter
{
	/* Common for both PF and VF */
	struct i40e_hw hw;
	struct rte_eth_dev *eth_dev;

	/* Specific for PF or VF */
	union {
		struct i40e_pf pf;
		struct i40e_vf vf;
	};

	/* For vector PMD */
	bool rx_bulk_alloc_allowed;
	bool rx_vec_allowed;
	bool tx_simple_allowed;
	bool tx_vec_allowed;

	/* For PTP */
	struct rte_timecounter systime_tc;
	struct rte_timecounter rx_tstamp_tc;
	struct rte_timecounter tx_tstamp_tc;

	/* ptype mapping table */
	uint32_t ptype_tbl[I40E_MAX_PKT_TYPE] __rte_cache_min_aligned;
	/* flow type to pctype mapping table */
	uint64_t pctypes_tbl[I40E_FLOW_TYPE_MAX] __rte_cache_min_aligned;
	uint64_t flow_types_mask;
	uint64_t pctypes_mask;

	/* For devargs */
	uint8_t use_latest_vec;

	/* For RSS reta table update */
	uint8_t rss_reta_updated;
};

static inline struct i40e_vsi * i40e_get_vsi_from_adapter(struct i40e_adapter *adapter)
{
	struct i40e_hw *hw;

	if (!adapter)
	{
		return NULL;
	}
	
	hw = I40E_DEV_PRIVATE_TO_HW(adapter);
	if (hw->mac.type == I40E_MAC_VF || hw->mac.type == I40E_MAC_X722_VF)
	{
		struct i40e_vf *vf = I40EVF_DEV_PRIVATE_TO_VF(adapter);
		return &vf->vsi;
	}
	else
	{
		struct i40e_pf *pf = I40E_DEV_PRIVATE_TO_PF(adapter);
		return pf->main_vsi;
	}
}

uint64_t i40e_config_hena(const struct i40e_adapter *adapter, uint64_t flags);
uint64_t i40e_parse_hena(const struct i40e_adapter *adapter, uint64_t flags);
enum i40e_filter_pctype i40e_flowtype_to_pctype(const struct i40e_adapter *adapter, uint16_t flow_type);
uint16_t i40e_pctype_to_flowtype(const struct i40e_adapter *adapter, enum i40e_filter_pctype pctype);

/* I40E_DEV_PRIVATE_TO */
#define I40E_DEV_PRIVATE_TO_PF(adapter) \
	(&((struct i40e_adapter *)adapter)->pf)
#define I40E_DEV_PRIVATE_TO_HW(adapter) \
	(&((struct i40e_adapter *)adapter)->hw)
#define I40E_DEV_PRIVATE_TO_ADAPTER(adapter) \
	((struct i40e_adapter *)adapter)

/* I40EVF_DEV_PRIVATE_TO */
#define I40EVF_DEV_PRIVATE_TO_VF(adapter) \
	(&((struct i40e_adapter *)adapter)->vf)

#define I40E_DEV_PRIVATE_TO_MAIN_VSI(adapter) \
	i40e_get_vsi_from_adapter((struct i40e_adapter *)adapter)
