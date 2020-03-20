/*
 * Structure to store private data specific for VF instance.
 */
struct i40e_vf
{
	struct i40e_adapter *adapter; /* The adapter this VF associate to */
	struct rte_eth_dev_data *dev_data; /* Pointer to the device data */
	uint16_t num_queue_pairs;
	uint16_t max_pkt_len; /* Maximum packet length */
	bool promisc_unicast_enabled;
	bool promisc_multicast_enabled;

	uint32_t version_major; /* Major version number */
	uint32_t version_minor; /* Minor version number */
	uint16_t promisc_flags; /* Promiscuous setting */
	uint32_t vlan[I40E_VFTA_SIZE]; /* VLAN bit map */

	/* Multicast addrs */
	struct rte_ether_addr mc_addrs[I40E_NUM_MACADDR_MAX];
	uint16_t mc_addrs_num;   /* Multicast mac addresses number */

	/* Event from pf */
	bool dev_closed;
	bool link_up;
	enum virtchnl_link_speed link_speed;
	bool vf_reset;
	volatile uint32_t pend_cmd; /* pending command not finished yet */
	int32_t cmd_retval; /* return value of the cmd response from PF */
	u16 pend_msg; /* flags indicates events from pf not handled yet */
	uint8_t *aq_resp; /* buffer to store the adminq response from PF */

	/* VSI info */
	struct virtchnl_vf_resource *vf_res; /* All VSIs */
	struct virtchnl_vsi_resource *vsi_res; /* LAN VSI */
	struct i40e_vsi vsi;
	uint64_t flags;
};

/* I40E_VF_TO */
#define I40E_VF_TO_HW(vf) \
	(&(((struct i40e_vf *)vf)->adapter->hw))

/* Linux PF host with virtchnl version 1.1 */
#define PF_IS_V11(vf) \
	(((vf)->version_major == VIRTCHNL_VERSION_MAJOR) && \
	((vf)->version_minor == 1))
