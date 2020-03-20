/*
 * Structure that defines a VSI, associated with a adapter.
 */
struct i40e_vsi
{
	struct i40e_adapter *adapter; /* Backreference to associated adapter */
	struct i40e_aqc_vsi_properties_data info; /* VSI properties */

	struct i40e_eth_stats eth_stats_offset;
	struct i40e_eth_stats eth_stats;
	/*
	 * When drivers loaded, only a default main VSI exists. In case new VSI
	 * needs to add, HW needs to know the layout that VSIs are organized.
	 * Besides that, VSI isan element and can't switch packets, which needs
	 * to add new component VEB to perform switching. So, a new VSI needs
	 * to specify the uplink VSI (Parent VSI) before created. The
	 * uplink VSI will check whether it had a VEB to switch packets. If no,
	 * it will try to create one. Then, uplink VSI will move the new VSI
	 * into its' sib_vsi_list to manage all the downlink VSI.
	 *  sib_vsi_list: the VSI list that shared the same uplink VSI.
	 *  parent_vsi  : the uplink VSI. It's NULL for main VSI.
	 *  veb         : the VEB associates with the VSI.
	 */
	struct i40e_vsi_list sib_vsi_list; /* sibling vsi list */
	struct i40e_vsi *parent_vsi;
	struct i40e_veb *veb;    /* Associated veb, could be null */
	struct i40e_veb *floating_veb; /* Associated floating veb */
	bool offset_loaded;
	enum i40e_vsi_type type; /* VSI types */
	uint16_t vlan_num;       /* Total VLAN number */
	uint16_t mac_num;        /* Total mac number */
	uint32_t vfta[I40E_VFTA_SIZE];        /* VLAN bitmap */
	struct i40e_mac_filter_list mac_list; /* macvlan filter list */
	/* specific VSI-defined parameters, SRIOV stored the vf_id */
	uint32_t user_param;
	uint16_t seid;           /* The seid of VSI itself */
	uint16_t uplink_seid;    /* The uplink seid of this VSI */
	uint16_t nb_qps;         /* Number of queue pairs VSI can occupy */
	uint16_t nb_used_qps;    /* Number of queue pairs VSI uses */
	uint16_t max_macaddrs;   /* Maximum number of MAC addresses */
	uint16_t base_queue;     /* The first queue index of this VSI */
	/*
	 * The offset to visit VSI related register, assigned by HW when
	 * creating VSI
	 */
	uint16_t vsi_id;
	uint16_t msix_intr; /* The MSIX interrupt binds to VSI */
	uint16_t nb_msix;   /* The max number of msix vector */
	uint8_t enabled_tc; /* The traffic class enabled */
	uint8_t vlan_anti_spoof_on; /* The VLAN anti-spoofing enabled */
	uint8_t vlan_filter_on; /* The VLAN filter enabled */
	struct i40e_bw_info bw_info; /* VSI bandwidth information */
};

static int i40e_vsi_config_double_vlan(struct i40e_vsi *vsi, int on);
static inline int i40e_find_all_mac_for_vlan(struct i40e_vsi *vsi, struct i40e_macvlan_filter *mv_f, int num, uint16_t vlan);
static int i40e_vsi_remove_all_macvlan_filter(struct i40e_vsi *vsi);

void i40e_set_vlan_filter(struct i40e_vsi *vsi, uint16_t vlan_id, bool on);
int i40e_add_macvlan_filters(struct i40e_vsi *vsi, struct i40e_macvlan_filter *filter, int total);
int i40e_set_rss_key(struct i40e_vsi *vsi, uint8_t *key, uint8_t key_len);
int i40e_set_rss_lut(struct i40e_vsi *vsi, uint8_t *lut, uint16_t lut_size);
int i40e_vsi_release(struct i40e_vsi *vsi);
int i40e_vsi_add_vlan(struct i40e_vsi *vsi, uint16_t vlan);
int i40e_vsi_delete_vlan(struct i40e_vsi *vsi, uint16_t vlan);
int i40e_vsi_add_mac(struct i40e_vsi *vsi, struct i40e_mac_filter_info *filter);
int i40e_vsi_delete_mac(struct i40e_vsi *vsi, struct rte_ether_addr *addr);
void i40e_update_vsi_stats(struct i40e_vsi *vsi);
void i40e_vsi_queues_bind_intr(struct i40e_vsi *vsi, uint16_t itr_idx);
void i40e_vsi_queues_unbind_intr(struct i40e_vsi *vsi);
int i40e_vsi_vlan_pvid_set(struct i40e_vsi *vsi, struct i40e_vsi_vlan_pvid_info *info);
int i40e_vsi_config_vlan_stripping(struct i40e_vsi *vsi, bool on);
int i40e_vsi_config_vlan_filter(struct i40e_vsi *vsi, bool on);
int i40e_find_all_vlan_for_mac(struct i40e_vsi *vsi, struct i40e_macvlan_filter *mv_f, int num, struct rte_ether_addr *addr);
int i40e_remove_macvlan_filters(struct i40e_vsi *vsi, struct i40e_macvlan_filter *filter, int total);

/* I40E_VSI_TO */
#define I40E_VSI_TO_HW(vsi) \
	(&(((struct i40e_vsi *)vsi)->adapter->hw))
#define I40E_VSI_TO_PF(vsi) \
	(&(((struct i40e_vsi *)vsi)->adapter->pf))
#define I40E_VSI_TO_VF(vsi) \
	(&(((struct i40e_vsi *)vsi)->adapter->vf))
#define I40E_VSI_TO_DEV_DATA(vsi) \
	(((struct i40e_vsi *)vsi)->adapter->pf.dev_data)
#define I40E_VSI_TO_ETH_DEV(vsi) \
	(((struct i40e_vsi *)vsi)->adapter->eth_dev)
