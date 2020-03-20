/* The max bandwidth of i40e is 40Gbps. */
#define I40E_QOS_BW_MAX 40000
/* The bandwidth should be the multiple of 50Mbps. */
#define I40E_QOS_BW_GRANULARITY 50
/* The min bandwidth weight is 1. */
#define I40E_QOS_BW_WEIGHT_MIN 1
/* The max bandwidth weight is 127. */
#define I40E_QOS_BW_WEIGHT_MAX 127

/* Bandwidth limit information */
struct i40e_bw_info
{
	uint16_t bw_limit;      /* BW Limit (0 = disabled) */
	uint8_t  bw_max;        /* Max BW limit if enabled */

	/* Relative credits within same TC with respect to other VSIs or Comps */
	uint8_t  bw_ets_share_credits[I40E_MAX_TRAFFIC_CLASS];
	/* Bandwidth limit per TC */
	uint16_t bw_ets_credits[I40E_MAX_TRAFFIC_CLASS];
	/* Max bandwidth limit per TC */
	uint8_t  bw_ets_max[I40E_MAX_TRAFFIC_CLASS];
};