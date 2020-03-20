/* The max queue region index is 7. */
#define I40E_REGION_MAX_INDEX 7

struct i40e_queue_regions
{
	/* the total number of queue region for this port */
	uint16_t queue_region_number;
	struct i40e_queue_region_info region[I40E_REGION_MAX_INDEX + 1];
};