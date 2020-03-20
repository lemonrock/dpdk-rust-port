/*
 * Structure to store private data specific for PF instance.
 */
struct i40e_pf
{
	struct i40e_adapter *adapter; /* The adapter this PF associate to */
	struct i40e_vsi *main_vsi; /* pointer to main VSI structure */
	uint16_t mac_seid; /* The seid of the MAC of this PF */
	uint16_t main_vsi_seid; /* The seid of the main VSI */
	uint16_t max_num_vsi;
	struct i40e_res_pool_info qp_pool;    /*Queue pair pool */
	struct i40e_res_pool_info msix_pool;  /* MSIX interrupt pool */

	struct i40e_hw_port_stats stats_offset;
	struct i40e_hw_port_stats stats;
	/* internal packet statistics, it should be excluded from the total */
	struct i40e_eth_stats internal_stats_offset;
	struct i40e_eth_stats internal_stats;
	bool offset_loaded;

	struct rte_eth_dev_data *dev_data; /* Pointer to the device data */
	struct rte_ether_addr dev_addr; /* PF device mac address */
	uint64_t flags; /* PF feature flags */
	/* All kinds of queue pair setting for different VSIs */
	struct i40e_pf_vf *vfs;
	uint16_t vf_num;
	/* Each of below queue pairs should be power of 2 since it's the
	   precondition after TC configuration applied */
	uint16_t lan_nb_qp_max;
	uint16_t lan_nb_qps; /* The number of queue pairs of LAN */
	uint16_t lan_qp_offset;
	uint16_t vmdq_nb_qp_max;
	uint16_t vmdq_nb_qps; /* The number of queue pairs of VMDq */
	uint16_t vmdq_qp_offset;
	uint16_t vf_nb_qp_max;
	uint16_t vf_nb_qps; /* The number of queue pairs of VF */
	uint16_t vf_qp_offset;
	uint16_t fdir_nb_qps; /* The number of queue pairs of Flow Director */
	uint16_t fdir_qp_offset;

	uint16_t hash_lut_size; /* The size of hash lookup table */
	/* input set bits for each pctype */
	uint64_t hash_input_set[I40E_FILTER_PCTYPE_MAX];
	/* store VXLAN UDP ports */
	uint16_t vxlan_ports[I40E_MAX_PF_UDP_OFFLOAD_PORTS];
	uint16_t vxlan_bitmap; /* Vxlan bit mask */

	/* VMDQ related info */
	uint16_t max_nb_vmdq_vsi; /* Max number of VMDQ VSIs supported */
	uint16_t nb_cfg_vmdq_vsi; /* number of VMDQ VSIs configured */
	struct i40e_vmdq_info *vmdq;

	struct i40e_fdir_info fdir; /* flow director info */
	struct i40e_ethertype_rule ethertype; /* Ethertype filter rule */
	struct i40e_tunnel_rule tunnel; /* Tunnel filter rule */
	struct i40e_rte_flow_rss_conf rss_info; /* rss info */
	struct i40e_queue_regions queue_region; /* queue region info */
	struct i40e_fc_conf fc_conf; /* Flow control conf */
	struct i40e_mirror_rule_list mirror_list;
	uint16_t nb_mirror_rule;   /* The number of mirror rules */
	bool floating_veb; /* The flag to use the floating VEB */
	/* The floating enable flag for the specific VF */
	bool floating_veb_list[I40E_MAX_VF];
	struct i40e_flow_list flow_list;
	bool mpls_replace_flag;  /* 1 - MPLS filter replace is done */
	bool gtp_replace_flag;   /* 1 - GTP-C/U filter replace is done */
	bool qinq_replace_flag;  /* QINQ filter replace is done */
	struct i40e_tm_conf tm_conf;
	bool support_multi_driver; /* 1 - support multiple driver */

	/* Dynamic Device Personalization */
	bool gtp_support; /* 1 - support GTP-C and GTP-U */
	bool esp_support; /* 1 - support ESP SPI */
	/* customer customized pctype */
	struct i40e_customized_pctype customized_pctype[I40E_CUSTOMIZED_MAX];
	/* Switch Domain Id */
	uint16_t switch_domain_id;

	struct i40e_vf_msg_cfg vf_msg_cfg;
};

static int i40e_pf_setup(struct i40e_pf *pf);
static int i40e_dev_rxtx_init(struct i40e_pf *pf);
static struct i40e_veb *i40e_veb_setup(struct i40e_pf *pf,struct i40e_vsi *vsi);
static int i40e_pf_config_mq_rx(struct i40e_pf *pf);
static void i40e_filter_input_set_init(struct i40e_pf *pf);
static void i40e_read_stats_registers(struct i40e_pf *pf, struct i40e_hw *hw);
static void i40e_ethertype_filter_restore(struct i40e_pf *pf);
static void i40e_tunnel_filter_restore(struct i40e_pf *pf);
static void i40e_filter_restore(struct i40e_pf *pf);
static int i40e_sw_ethertype_filter_insert(struct i40e_pf *pf, struct i40e_ethertype_filter *filter);
static int i40e_sw_tunnel_filter_insert(struct i40e_pf *pf, struct i40e_tunnel_filter *tunnel_filter);
static int i40e_cloud_filter_qinq_create(struct i40e_pf *pf);

struct i40e_customized_pctype* i40e_find_customized_pctype(struct i40e_pf *pf, uint8_t index);
int i40e_config_rss_filter(struct i40e_pf *pf, struct i40e_rte_flow_rss_conf *conf, bool add);
int i40e_dev_switch_queues(struct i40e_pf *pf, bool on);
struct i40e_vsi *i40e_vsi_setup(struct i40e_pf *pf, enum i40e_vsi_type type, struct i40e_vsi *uplink_vsi, uint16_t user_param);
enum i40e_status_code i40e_fdir_setup_tx_resources(struct i40e_pf *pf);
enum i40e_status_code i40e_fdir_setup_rx_resources(struct i40e_pf *pf);
int i40e_fdir_setup(struct i40e_pf *pf);
void i40e_fdir_teardown(struct i40e_pf *pf);
void i40e_fdir_filter_restore(struct i40e_pf *pf);
int i40e_fdir_filter_inset_select(struct i40e_pf *pf, struct rte_eth_input_set_conf *conf);
int i40e_sw_fdir_filter_del(struct i40e_pf *pf, struct i40e_fdir_input *input);
int i40e_sw_tunnel_filter_del(struct i40e_pf *pf, struct i40e_tunnel_filter_input *input);
int i40e_ethertype_filter_set(struct i40e_pf *pf, struct rte_eth_ethertype_filter *filter, bool add);
int i40e_dev_tunnel_filter_set(struct i40e_pf *pf, struct rte_eth_tunnel_filter_conf *tunnel_filter, uint8_t add);
int i40e_dev_consistent_tunnel_filter_set(struct i40e_pf *pf, struct i40e_tunnel_filter_conf *tunnel_filter, uint8_t add);

/* I40E_PF_TO */
#define I40E_PF_TO_HW(pf) \
	(&(((struct i40e_pf *)pf)->adapter->hw))
#define I40E_PF_TO_ADAPTER(pf) \
	((struct i40e_adapter *)pf->adapter)
