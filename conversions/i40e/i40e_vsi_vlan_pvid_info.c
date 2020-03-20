
struct i40e_vsi_vlan_pvid_info
{
	uint16_t on;            /* Enable or disable pvid */
	union
	{
		uint16_t pvid;  /* Valid in case 'on' is set to set pvid */
		struct
		{
		/*  Valid in case 'on' is cleared. 'tagged' will reject tagged packets,
		 *  while 'untagged' will reject untagged packets.
		 */
			uint8_t tagged;
			uint8_t untagged;
		} reject;
	} config;
};
