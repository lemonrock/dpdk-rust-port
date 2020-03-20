
/* A structure used to define an action when match FDIR packet filter. */
struct i40e_fdir_action
{
	uint16_t rx_queue;        /* Queue assigned to if FDIR match. */
	enum i40e_fdir_behavior behavior;     /* Behavior will be taken */
	enum i40e_fdir_status report_status;  /* Status report option */
	/* If report_status is I40E_FDIR_REPORT_ID_FLEX_4 or
	 * I40E_FDIR_REPORT_FLEX_8, flex_off specifies where the reported
	 * flex bytes start from in flexible payload.
	 */
	uint8_t flex_off;
};
