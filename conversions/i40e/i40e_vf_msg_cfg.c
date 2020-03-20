struct i40e_vf_msg_cfg
{
	/* maximal VF message during a statistic period */
	uint32_t max_msg;

	/* statistic period, in second */
	uint32_t period;
	/*
	 * If message statistics from a VF exceed the maximal limitation,
	 * the PF will ignore any new message from that VF for
	 * 'ignor_second' time.
	 */
	uint32_t ignore_second;
};

