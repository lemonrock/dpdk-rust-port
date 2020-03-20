/* queue region info */
struct i40e_queue_region_info
{
	/* the region id for this configuration */
	uint8_t region_id;
	/* the start queue index for this region */
	uint8_t queue_start_index;
	/* the total queue number of this queue region */
	uint8_t queue_num;
	/* the total number of user priority for this region */
	uint8_t user_priority_num;
	/* the packet's user priority for this region */
	uint8_t user_priority[I40E_MAX_USER_PRIORITY];
	/* the total number of flowtype for this region */
	uint8_t flowtype_num;
	/**
	 * the pctype or hardware flowtype of packet,
	 * the specific index for each type has been defined
	 * in file i40e_type.h as enum i40e_filter_pctype.
	 */
	uint8_t hw_flowtype[I40E_FILTER_PCTYPE_MAX];
};
