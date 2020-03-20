/* Tunnel filter struct */
struct i40e_tunnel_filter_input
{
	uint8_t outer_mac[6];    /* Outer mac address to match */
	uint8_t inner_mac[6];    /* Inner mac address to match */
	uint16_t inner_vlan;     /* Inner vlan address to match */
	enum i40e_tunnel_iptype ip_type;
	uint16_t flags;          /* Filter type flag */
	uint32_t tenant_id;      /* Tenant id to match */
	uint16_t general_fields[32];  /* Big buffer */
};