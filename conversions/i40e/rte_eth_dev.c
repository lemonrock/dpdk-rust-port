

struct eth_dev_ops {
	eth_dev_configure_t        dev_configure; /**< Configure device. */
	eth_dev_start_t            dev_start;     /**< Start device. */
	eth_dev_stop_t             dev_stop;      /**< Stop device. */
	eth_dev_set_link_up_t      dev_set_link_up;   /**< Device link up. */
	eth_dev_set_link_down_t    dev_set_link_down; /**< Device link down. */
	eth_dev_close_t            dev_close;     /**< Close device. */
	eth_dev_reset_t		   dev_reset;	  /**< Reset device. */
	eth_link_update_t          link_update;   /**< Get device link state. */
	eth_is_removed_t           is_removed;
	/**< Check if the device was physically removed. */

	eth_promiscuous_enable_t   promiscuous_enable; /**< Promiscuous ON. */
	eth_promiscuous_disable_t  promiscuous_disable;/**< Promiscuous OFF. */
	eth_allmulticast_enable_t  allmulticast_enable;/**< RX multicast ON. */
	eth_allmulticast_disable_t allmulticast_disable;/**< RX multicast OFF. */
	eth_mac_addr_remove_t      mac_addr_remove; /**< Remove MAC address. */
	eth_mac_addr_add_t         mac_addr_add;  /**< Add a MAC address. */
	eth_mac_addr_set_t         mac_addr_set;  /**< Set a MAC address. */
	eth_set_mc_addr_list_t     set_mc_addr_list; /**< set list of mcast addrs. */
	mtu_set_t                  mtu_set;       /**< Set MTU. */

	eth_stats_get_t            stats_get;     /**< Get generic device statistics. */
	eth_stats_reset_t          stats_reset;   /**< Reset generic device statistics. */
	eth_xstats_get_t           xstats_get;    /**< Get extended device statistics. */
	eth_xstats_reset_t         xstats_reset;  /**< Reset extended device statistics. */
	eth_xstats_get_names_t     xstats_get_names;
	/**< Get names of extended statistics. */
	eth_queue_stats_mapping_set_t queue_stats_mapping_set;
	/**< Configure per queue stat counter mapping. */

	eth_dev_infos_get_t        dev_infos_get; /**< Get device info. */
	eth_rxq_info_get_t         rxq_info_get; /**< retrieve RX queue information. */
	eth_txq_info_get_t         txq_info_get; /**< retrieve TX queue information. */
	eth_burst_mode_get_t       rx_burst_mode_get; /**< Get RX burst mode */
	eth_burst_mode_get_t       tx_burst_mode_get; /**< Get TX burst mode */
	eth_fw_version_get_t       fw_version_get; /**< Get firmware version. */
	eth_dev_supported_ptypes_get_t dev_supported_ptypes_get;
	/**< Get packet types supported and identified by device. */
	eth_dev_ptypes_set_t dev_ptypes_set;
	/**< Inform Ethernet device about reduced range of packet types to handle. */

	vlan_filter_set_t          vlan_filter_set; /**< Filter VLAN Setup. */
	vlan_tpid_set_t            vlan_tpid_set; /**< Outer/Inner VLAN TPID Setup. */
	vlan_strip_queue_set_t     vlan_strip_queue_set; /**< VLAN Stripping on queue. */
	vlan_offload_set_t         vlan_offload_set; /**< Set VLAN Offload. */
	vlan_pvid_set_t            vlan_pvid_set; /**< Set port based TX VLAN insertion. */

	eth_queue_start_t          rx_queue_start;/**< Start RX for a queue. */
	eth_queue_stop_t           rx_queue_stop; /**< Stop RX for a queue. */
	eth_queue_start_t          tx_queue_start;/**< Start TX for a queue. */
	eth_queue_stop_t           tx_queue_stop; /**< Stop TX for a queue. */
	eth_rx_queue_setup_t       rx_queue_setup;/**< Set up device RX queue. */
	eth_queue_release_t        rx_queue_release; /**< Release RX queue. */
	eth_rx_queue_count_t       rx_queue_count;
	/**< Get the number of used RX descriptors. */
	eth_rx_descriptor_done_t   rx_descriptor_done; /**< Check rxd DD bit. */
	eth_rx_descriptor_status_t rx_descriptor_status;
	/**< Check the status of a Rx descriptor. */
	eth_tx_descriptor_status_t tx_descriptor_status;
	/**< Check the status of a Tx descriptor. */
	/*
	 * Static inline functions use functions ABOVE this comment.
	 * New dev_ops functions should be added BELOW to avoid breaking ABI.
	 */
	eth_rx_enable_intr_t       rx_queue_intr_enable;  /**< Enable Rx queue interrupt. */
	eth_rx_disable_intr_t      rx_queue_intr_disable; /**< Disable Rx queue interrupt. */
	eth_tx_queue_setup_t       tx_queue_setup;/**< Set up device TX queue. */
	eth_queue_release_t        tx_queue_release; /**< Release TX queue. */
	eth_tx_done_cleanup_t      tx_done_cleanup;/**< Free tx ring mbufs */

	eth_dev_led_on_t           dev_led_on;    /**< Turn on LED. */
	eth_dev_led_off_t          dev_led_off;   /**< Turn off LED. */

	flow_ctrl_get_t            flow_ctrl_get; /**< Get flow control. */
	flow_ctrl_set_t            flow_ctrl_set; /**< Setup flow control. */
	priority_flow_ctrl_set_t   priority_flow_ctrl_set; /**< Setup priority flow control. */

	eth_uc_hash_table_set_t    uc_hash_table_set; /**< Set Unicast Table Array. */
	eth_uc_all_hash_table_set_t uc_all_hash_table_set; /**< Set Unicast hash bitmap. */

	eth_mirror_rule_set_t	   mirror_rule_set; /**< Add a traffic mirror rule. */
	eth_mirror_rule_reset_t	   mirror_rule_reset; /**< reset a traffic mirror rule. */

	eth_udp_tunnel_port_add_t  udp_tunnel_port_add; /** Add UDP tunnel port. */
	eth_udp_tunnel_port_del_t  udp_tunnel_port_del; /** Del UDP tunnel port. */
	eth_l2_tunnel_eth_type_conf_t l2_tunnel_eth_type_conf;
	/** Config ether type of l2 tunnel. */
	eth_l2_tunnel_offload_set_t   l2_tunnel_offload_set;
	/** Enable/disable l2 tunnel offload functions. */

	eth_set_queue_rate_limit_t set_queue_rate_limit; /**< Set queue rate limit. */

	rss_hash_update_t          rss_hash_update; /** Configure RSS hash protocols. */
	rss_hash_conf_get_t        rss_hash_conf_get; /** Get current RSS hash configuration. */
	reta_update_t              reta_update;   /** Update redirection table. */
	reta_query_t               reta_query;    /** Query redirection table. */

	eth_get_reg_t              get_reg;           /**< Get registers. */
	eth_get_eeprom_length_t    get_eeprom_length; /**< Get eeprom length. */
	eth_get_eeprom_t           get_eeprom;        /**< Get eeprom data. */
	eth_set_eeprom_t           set_eeprom;        /**< Set eeprom. */

	eth_get_module_info_t      get_module_info;
	/** Get plugin module eeprom attribute. */
	eth_get_module_eeprom_t    get_module_eeprom;
	/** Get plugin module eeprom data. */

	eth_filter_ctrl_t          filter_ctrl; /**< common filter control. */

	eth_get_dcb_info           get_dcb_info; /** Get DCB information. */

	eth_timesync_enable_t      timesync_enable;
	/** Turn IEEE1588/802.1AS timestamping on. */
	eth_timesync_disable_t     timesync_disable;
	/** Turn IEEE1588/802.1AS timestamping off. */
	eth_timesync_read_rx_timestamp_t timesync_read_rx_timestamp;
	/** Read the IEEE1588/802.1AS RX timestamp. */
	eth_timesync_read_tx_timestamp_t timesync_read_tx_timestamp;
	/** Read the IEEE1588/802.1AS TX timestamp. */
	eth_timesync_adjust_time   timesync_adjust_time; /** Adjust the device clock. */
	eth_timesync_read_time     timesync_read_time; /** Get the device clock time. */
	eth_timesync_write_time    timesync_write_time; /** Set the device clock time. */

	eth_read_clock             read_clock;

	eth_xstats_get_by_id_t     xstats_get_by_id;
	/**< Get extended device statistic values by ID. */
	eth_xstats_get_names_by_id_t xstats_get_names_by_id;
	/**< Get name of extended device statistics by ID. */

	eth_tm_ops_get_t tm_ops_get;
	/**< Get Traffic Management (TM) operations. */

	eth_mtr_ops_get_t mtr_ops_get;
	/**< Get Traffic Metering and Policing (MTR) operations. */

	eth_pool_ops_supported_t pool_ops_supported;
	/**< Test if a port supports specific mempool ops */

	eth_hairpin_cap_get_t hairpin_cap_get;
	/**< Returns the hairpin capabilities. */
	eth_rx_hairpin_queue_setup_t rx_hairpin_queue_setup;
	/**< Set up device RX hairpin queue. */
	eth_tx_hairpin_queue_setup_t tx_hairpin_queue_setup;
	/**< Set up device TX hairpin queue. */
};

static int eth_i40e_dev_init(struct rte_eth_dev *eth_dev, void *init_params);
static int eth_i40e_dev_uninit(struct rte_eth_dev *eth_dev);
static int i40e_dev_configure(struct rte_eth_dev *dev);
static int i40e_dev_start(struct rte_eth_dev *dev);
static void i40e_dev_stop(struct rte_eth_dev *dev);
static void i40e_dev_close(struct rte_eth_dev *dev);
static int  i40e_dev_reset(struct rte_eth_dev *dev);
static int i40e_dev_promiscuous_enable(struct rte_eth_dev *dev);
static int i40e_dev_promiscuous_disable(struct rte_eth_dev *dev);
static int i40e_dev_allmulticast_enable(struct rte_eth_dev *dev);
static int i40e_dev_allmulticast_disable(struct rte_eth_dev *dev);
static int i40e_dev_set_link_up(struct rte_eth_dev *dev);
static int i40e_dev_set_link_down(struct rte_eth_dev *dev);
static int i40e_dev_stats_get(struct rte_eth_dev *dev, struct rte_eth_stats *stats);
static int i40e_dev_xstats_get(struct rte_eth_dev *dev, struct rte_eth_xstat *xstats, unsigned n);
static int i40e_dev_xstats_get_names(struct rte_eth_dev *dev, struct rte_eth_xstat_name *xstats_names, unsigned limit);
static int i40e_dev_stats_reset(struct rte_eth_dev *dev);
static int i40e_fw_version_get(struct rte_eth_dev *dev, char *fw_version, size_t fw_size);
static int i40e_dev_info_get(struct rte_eth_dev *dev, struct rte_eth_dev_info *dev_info);
static int i40e_vlan_filter_set(struct rte_eth_dev *dev, uint16_t vlan_id, int on);
static int i40e_vlan_tpid_set(struct rte_eth_dev *dev, enum rte_vlan_type vlan_type, uint16_t tpid);
static int i40e_vlan_offload_set(struct rte_eth_dev *dev, int mask);
static void i40e_vlan_strip_queue_set(struct rte_eth_dev *dev, uint16_t queue, int on);
static int i40e_vlan_pvid_set(struct rte_eth_dev *dev, uint16_t pvid, int on);
static int i40e_dev_led_on(struct rte_eth_dev *dev);
static int i40e_dev_led_off(struct rte_eth_dev *dev);
static int i40e_flow_ctrl_get(struct rte_eth_dev *dev, struct rte_eth_fc_conf *fc_conf);
static int i40e_flow_ctrl_set(struct rte_eth_dev *dev, struct rte_eth_fc_conf *fc_conf);
static int i40e_priority_flow_ctrl_set(struct rte_eth_dev *dev, struct rte_eth_pfc_conf *pfc_conf);
static int i40e_macaddr_add(struct rte_eth_dev *dev, struct rte_ether_addr *mac_addr, uint32_t index, uint32_t pool);
static void i40e_macaddr_remove(struct rte_eth_dev *dev, uint32_t index);
static int i40e_dev_rss_reta_update(struct rte_eth_dev *dev, struct rte_eth_rss_reta_entry64 *reta_conf, uint16_t reta_size);
static int i40e_dev_rss_reta_query(struct rte_eth_dev *dev, struct rte_eth_rss_reta_entry64 *reta_conf, uint16_t reta_size);
static int i40e_pf_parameter_init(struct rte_eth_dev *dev);
static int i40e_vmdq_setup(struct rte_eth_dev *dev);
static int i40e_dcb_setup(struct rte_eth_dev *dev);
static int i40e_dev_init_vlan(struct rte_eth_dev *dev);
static int i40e_dev_rss_hash_update(struct rte_eth_dev *dev, struct rte_eth_rss_conf *rss_conf);
static int i40e_dev_rss_hash_conf_get(struct rte_eth_dev *dev, struct rte_eth_rss_conf *rss_conf);
static int i40e_dev_udp_tunnel_port_add(struct rte_eth_dev *dev, struct rte_eth_udp_tunnel *udp_tunnel);
static int i40e_dev_udp_tunnel_port_del(struct rte_eth_dev *dev, struct rte_eth_udp_tunnel *udp_tunnel);
static int i40e_ethertype_filter_handle(struct rte_eth_dev *dev,enum rte_filter_op filter_op, void *arg);
static int i40e_dev_filter_ctrl(struct rte_eth_dev *dev, enum rte_filter_type filter_type, enum rte_filter_op filter_op, void *arg);
static int i40e_dev_get_dcb_info(struct rte_eth_dev *dev,struct rte_eth_dcb_info *dcb_info);
static void i40e_hw_init(struct rte_eth_dev *dev);
static int i40e_mirror_rule_set(struct rte_eth_dev *dev, struct rte_eth_mirror_conf *mirror_conf, uint8_t sw_id, uint8_t on);
static int i40e_mirror_rule_reset(struct rte_eth_dev *dev, uint8_t sw_id);
static int i40e_get_eeprom_length(struct rte_eth_dev *dev);
static int i40e_get_eeprom(struct rte_eth_dev *dev, struct rte_dev_eeprom_info *eeprom);
static int i40e_get_module_info(struct rte_eth_dev *dev, struct rte_eth_dev_module_info *modinfo);
static int i40e_get_module_eeprom(struct rte_eth_dev *dev, struct rte_dev_eeprom_info *info);
static int i40e_set_default_mac_addr(struct rte_eth_dev *dev, struct rte_ether_addr *mac_addr);
static int i40e_dev_mtu_set(struct rte_eth_dev *dev, uint16_t mtu);
static void i40e_notify_all_vfs_link_status(struct rte_eth_dev *dev);
static int i40e_timesync_enable(struct rte_eth_dev *dev);
static int i40e_timesync_disable(struct rte_eth_dev *dev);
static int i40e_timesync_read_rx_timestamp(struct rte_eth_dev *dev, struct timespec *timestamp, uint32_t flags);
static int i40e_timesync_read_tx_timestamp(struct rte_eth_dev *dev, struct timespec *timestamp);
static int i40e_timesync_adjust_time(struct rte_eth_dev *dev, int64_t delta);
static int i40e_timesync_read_time(struct rte_eth_dev *dev, struct timespec *timestamp);
static int i40e_timesync_write_time(struct rte_eth_dev *dev, const struct timespec *timestamp);
static int i40e_dev_rx_queue_intr_enable(struct rte_eth_dev *dev, uint16_t queue_id);
static int i40e_dev_rx_queue_intr_disable(struct rte_eth_dev *dev, uint16_t queue_id);
static int i40e_get_regs(struct rte_eth_dev *dev, struct rte_dev_reg_info *regs);

bool is_device_supported(struct rte_eth_dev *dev, struct rte_pci_driver *drv);
bool is_i40e_supported(struct rte_eth_dev *dev);
bool is_i40evf_supported(struct rte_eth_dev *dev);
int i40e_tm_ops_get(struct rte_eth_dev *dev, void *ops);
void i40e_tm_conf_init(struct rte_eth_dev *dev);
void i40e_tm_conf_uninit(struct rte_eth_dev *dev);
void i40e_update_customized_info(struct rte_eth_dev *dev, uint8_t *pkg, uint32_t pkg_size, enum rte_pmd_i40e_package_op op);
int i40e_dcb_init_configure(struct rte_eth_dev *dev, bool sw_dcb);
int i40e_flush_queue_region_all_conf(struct rte_eth_dev *dev, struct i40e_hw *hw, struct i40e_pf *pf, uint16_t on);
void i40e_init_queue_region_conf(struct rte_eth_dev *dev);
int i40e_vf_representor_init(struct rte_eth_dev *ethdev, void *init_params);
int i40e_vf_representor_uninit(struct rte_eth_dev *ethdev);
int i40e_dev_link_update(struct rte_eth_dev *dev, int wait_to_complete);
int i40e_fdir_configure(struct rte_eth_dev *dev);
void i40e_fdir_rx_proc_enable(struct rte_eth_dev *dev, bool on);
int i40e_fdir_ctrl_func(struct rte_eth_dev *dev, enum rte_filter_op filter_op, void *arg);
void i40e_rxq_info_get(struct rte_eth_dev *dev, uint16_t queue_id, struct rte_eth_rxq_info *qinfo);
void i40e_txq_info_get(struct rte_eth_dev *dev, uint16_t queue_id, struct rte_eth_txq_info *qinfo);
int i40e_rx_burst_mode_get(struct rte_eth_dev *dev, uint16_t queue_id, struct rte_eth_burst_mode *mode);
int i40e_tx_burst_mode_get(struct rte_eth_dev *dev, uint16_t queue_id, struct rte_eth_burst_mode *mode);
int i40e_add_del_fdir_filter(struct rte_eth_dev *dev, const struct rte_eth_fdir_filter *filter, bool add);
int i40e_flow_add_del_fdir_filter(struct rte_eth_dev *dev, const struct i40e_fdir_filter_conf *filter, bool add);
int i40e_fdir_flush(struct rte_eth_dev *dev);

typedef int (*parse_filter_t)(struct rte_eth_dev *dev, const struct rte_flow_attr *attr, const struct rte_flow_item pattern[], const struct rte_flow_action actions[], struct rte_flow_error *error, union i40e_filter_t *filter);

static const struct eth_dev_ops i40e_eth_dev_ops =
{
	.dev_configure                = i40e_dev_configure,
	.dev_start                    = i40e_dev_start,
	.dev_stop                     = i40e_dev_stop,
	.dev_close                    = i40e_dev_close,
	.dev_reset		      = i40e_dev_reset,
	.promiscuous_enable           = i40e_dev_promiscuous_enable,
	.promiscuous_disable          = i40e_dev_promiscuous_disable,
	.allmulticast_enable          = i40e_dev_allmulticast_enable,
	.allmulticast_disable         = i40e_dev_allmulticast_disable,
	.dev_set_link_up              = i40e_dev_set_link_up,
	.dev_set_link_down            = i40e_dev_set_link_down,
	.link_update                  = i40e_dev_link_update,
	.stats_get                    = i40e_dev_stats_get,
	.xstats_get                   = i40e_dev_xstats_get,
	.xstats_get_names             = i40e_dev_xstats_get_names,
	.stats_reset                  = i40e_dev_stats_reset,
	.xstats_reset                 = i40e_dev_stats_reset,
	.fw_version_get               = i40e_fw_version_get,
	.dev_infos_get                = i40e_dev_info_get,
	.dev_supported_ptypes_get     = i40e_dev_supported_ptypes_get,
	.vlan_filter_set              = i40e_vlan_filter_set,
	.vlan_tpid_set                = i40e_vlan_tpid_set,
	.vlan_offload_set             = i40e_vlan_offload_set,
	.vlan_strip_queue_set         = i40e_vlan_strip_queue_set,
	.vlan_pvid_set                = i40e_vlan_pvid_set,
	.rx_queue_start               = i40e_dev_rx_queue_start,
	.rx_queue_stop                = i40e_dev_rx_queue_stop,
	.tx_queue_start               = i40e_dev_tx_queue_start,
	.tx_queue_stop                = i40e_dev_tx_queue_stop,
	.rx_queue_setup               = i40e_dev_rx_queue_setup,
	.rx_queue_intr_enable         = i40e_dev_rx_queue_intr_enable,
	.rx_queue_intr_disable        = i40e_dev_rx_queue_intr_disable,
	.rx_queue_release             = i40e_dev_rx_queue_release,
	.rx_queue_count               = i40e_dev_rx_queue_count,
	.rx_descriptor_done           = i40e_dev_rx_descriptor_done,
	.rx_descriptor_status         = i40e_dev_rx_descriptor_status,
	.tx_descriptor_status         = i40e_dev_tx_descriptor_status,
	.tx_queue_setup               = i40e_dev_tx_queue_setup,
	.tx_queue_release             = i40e_dev_tx_queue_release,
	.dev_led_on                   = i40e_dev_led_on,
	.dev_led_off                  = i40e_dev_led_off,
	.flow_ctrl_get                = i40e_flow_ctrl_get,
	.flow_ctrl_set                = i40e_flow_ctrl_set,
	.priority_flow_ctrl_set       = i40e_priority_flow_ctrl_set,
	.mac_addr_add                 = i40e_macaddr_add,
	.mac_addr_remove              = i40e_macaddr_remove,
	.reta_update                  = i40e_dev_rss_reta_update,
	.reta_query                   = i40e_dev_rss_reta_query,
	.rss_hash_update              = i40e_dev_rss_hash_update,
	.rss_hash_conf_get            = i40e_dev_rss_hash_conf_get,
	.udp_tunnel_port_add          = i40e_dev_udp_tunnel_port_add,
	.udp_tunnel_port_del          = i40e_dev_udp_tunnel_port_del,
	.filter_ctrl                  = i40e_dev_filter_ctrl,
	.rxq_info_get                 = i40e_rxq_info_get,
	.txq_info_get                 = i40e_txq_info_get,
	.rx_burst_mode_get            = i40e_rx_burst_mode_get,
	.tx_burst_mode_get            = i40e_tx_burst_mode_get,
	.mirror_rule_set              = i40e_mirror_rule_set,
	.mirror_rule_reset            = i40e_mirror_rule_reset,
	.timesync_enable              = i40e_timesync_enable,
	.timesync_disable             = i40e_timesync_disable,
	.timesync_read_rx_timestamp   = i40e_timesync_read_rx_timestamp,
	.timesync_read_tx_timestamp   = i40e_timesync_read_tx_timestamp,
	.get_dcb_info                 = i40e_dev_get_dcb_info,
	.timesync_adjust_time         = i40e_timesync_adjust_time,
	.timesync_read_time           = i40e_timesync_read_time,
	.timesync_write_time          = i40e_timesync_write_time,
	.get_reg                      = i40e_get_regs,
	.get_eeprom_length            = i40e_get_eeprom_length,
	.get_eeprom                   = i40e_get_eeprom,
	.get_module_info              = i40e_get_module_info,
	.get_module_eeprom            = i40e_get_module_eeprom,
	.mac_addr_set                 = i40e_set_default_mac_addr,
	.mtu_set                      = i40e_dev_mtu_set,
	.tm_ops_get                   = i40e_tm_ops_get,
	.tx_done_cleanup              = i40e_tx_done_cleanup,
};
