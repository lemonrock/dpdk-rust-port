/**
 * Tunnel type.
 */
enum i40e_tunnel_type
{
	I40E_TUNNEL_TYPE_NONE = 0,
	I40E_TUNNEL_TYPE_VXLAN,
	I40E_TUNNEL_TYPE_GENEVE,
	I40E_TUNNEL_TYPE_TEREDO,
	I40E_TUNNEL_TYPE_NVGRE,
	I40E_TUNNEL_TYPE_IP_IN_GRE,
	I40E_L2_TUNNEL_TYPE_E_TAG,
	I40E_TUNNEL_TYPE_MPLSoUDP,
	I40E_TUNNEL_TYPE_MPLSoGRE,
	I40E_TUNNEL_TYPE_QINQ,
	I40E_TUNNEL_TYPE_GTPC,
	I40E_TUNNEL_TYPE_GTPU,
	I40E_TUNNEL_TYPE_ESPoUDP,
	I40E_TUNNEL_TYPE_ESPoIP,
	I40E_TUNNEL_TYPE_MAX,
};
