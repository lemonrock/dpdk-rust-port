
/*
 * Structure to store flex pit for flow diretor.
 */
struct i40e_fdir_flex_pit
{
	uint8_t src_offset;    /* offset in words from the beginning of payload */
	uint8_t size;          /* size in words */
	uint8_t dst_offset;    /* offset in words of flexible payload */
};
