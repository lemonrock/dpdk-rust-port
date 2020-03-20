/*
 * Structure to store private data for flow control.
 */
struct i40e_fc_conf
{
	uint16_t pause_time; /* Flow control pause timer */
	/* FC high water 0-7 for pfc and 8 for lfc unit:kilobytes */
	uint32_t high_water[I40E_MAX_TRAFFIC_CLASS + 1];
	/* FC low water  0-7 for pfc and 8 for lfc unit:kilobytes */
	uint32_t low_water[I40E_MAX_TRAFFIC_CLASS + 1];
};