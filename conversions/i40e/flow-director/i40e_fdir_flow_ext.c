/* A structure used to contain extend input of flow */
struct i40e_fdir_flow_ext
{
	uint16_t vlan_tci;
	uint8_t flexbytes[RTE_ETH_FDIR_MAX_FLEXLEN];
	/* It is filled by the flexible payload to match. */
	uint8_t is_vf;   /* 1 for VF, 0 for port dev */
	uint16_t dst_id; /* VF ID, available when is_vf is 1*/
	bool inner_ip;   /* If there is inner ip */
	enum i40e_fdir_ip_type iip_type; /* ip type for inner ip */
	enum i40e_fdir_ip_type oip_type; /* ip type for outer ip */
	bool customized_pctype; /* If customized pctype is used */
	bool pkt_template; /* If raw packet template is used */
	bool is_udp; /* ipv4|ipv6 udp flow */
};
