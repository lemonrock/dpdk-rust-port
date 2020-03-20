
struct i40e_fdir_flex_mask
{
	uint8_t word_mask;  /**< Bit i enables word i of flexible payload */
	uint8_t nb_bitmask;
	struct
	{
		uint8_t offset;
		uint16_t mask;
	} bitmask[I40E_FDIR_BITMASK_NUM_WORD];
};
