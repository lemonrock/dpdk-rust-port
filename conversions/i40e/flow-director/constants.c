
#define I40E_MAX_FLXPLD_FIED        3  /* max number of flex payload fields */
#define I40E_FDIR_BITMASK_NUM_WORD  2  /* max number of bitmask words */
#define I40E_FDIR_MAX_FLEXWORD_NUM  8  /* max number of flexpayload words */
#define I40E_FDIR_MAX_FLEX_LEN      16 /* len in bytes of flex payload */
#define I40E_INSET_MASK_NUM_REG     2  /* number of input set mask registers */

#define I40E_FDIR_MAX_FLEXLEN      16  /**< Max length of flexbytes. */
#define I40E_MAX_FLX_SOURCE_OFF    480
#define NONUSE_FLX_PIT_DEST_OFF 63
#define NONUSE_FLX_PIT_FSIZE    1
#define I40E_FLX_OFFSET_IN_FIELD_VECTOR   50
#define MK_FLX_PIT(src_offset, fsize, dst_offset) ( \
	(((src_offset) << I40E_PRTQF_FLX_PIT_SOURCE_OFF_SHIFT) & \
		I40E_PRTQF_FLX_PIT_SOURCE_OFF_MASK) | \
	(((fsize) << I40E_PRTQF_FLX_PIT_FSIZE_SHIFT) & \
			I40E_PRTQF_FLX_PIT_FSIZE_MASK) | \
	((((dst_offset) == NONUSE_FLX_PIT_DEST_OFF ? \
			NONUSE_FLX_PIT_DEST_OFF : \
			((dst_offset) + I40E_FLX_OFFSET_IN_FIELD_VECTOR)) << \
			I40E_PRTQF_FLX_PIT_DEST_OFF_SHIFT) & \
			I40E_PRTQF_FLX_PIT_DEST_OFF_MASK))
#define I40E_WORD(hi, lo) (uint16_t)((((hi) << 8) & 0xFF00) | ((lo) & 0xFF))
#define I40E_FLEX_WORD_MASK(off) (0x80 >> (off))
#define I40E_FDIR_IPv6_TC_OFFSET	20
