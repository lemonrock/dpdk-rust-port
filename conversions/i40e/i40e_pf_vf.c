/*
 * Structure to store private data for PF host.
 */
struct i40e_pf_vf
{
	struct i40e_pf *pf;
	struct i40e_vsi *vsi;
	enum I40E_VF_STATE state; /* The number of queue pairs available */
	uint16_t vf_idx; /* VF index in pf->vfs */
	uint16_t lan_nb_qps; /* Actual queues allocated */
	uint16_t reset_cnt; /* Total vf reset times */
	struct rte_ether_addr mac_addr;  /* Default MAC address */
	/* version of the virtchnl from VF */
	struct virtchnl_version_info version;
	uint32_t request_caps; /* offload caps requested from VF */
	uint64_t num_mdd_events; /* num of mdd events detected */

	/*
	 * Variables for store the arrival timestamp of VF messages.
	 * If the timestamp of latest message stored at
	 * `msg_timestamps[index % max]` then the timestamp of
	 * earliest message stored at `msg_time[(index + 1) % max]`.
	 * When a new message come, the timestamp of this message
	 * will be stored at `msg_timestamps[(index + 1) % max]` and the
	 * earliest message timestamp is at
	 * `msg_timestamps[(index + 2) % max]` now...
	 */
	uint32_t msg_index;
	uint64_t *msg_timestamps;

	/* cycle of stop ignoring VF message */
	uint64_t ignore_end_cycle;
};

int i40e_pf_host_send_msg_to_vf(struct i40e_pf_vf *vf, uint32_t opcode, uint32_t retval, uint8_t *msg, uint16_t msglen);
