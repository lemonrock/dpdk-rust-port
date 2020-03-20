static inline int i40e_align_floor(int n)
{
	if (n == 0)
	{
		return 0;
	}
	
	return 1 << (sizeof(n) * CHAR_BIT - 1 - __builtin_clz(n));
}

static inline uint16_t i40e_calc_itr_interval(bool is_pf, bool is_multi_drv)
{
	uint16_t interval = 0;

	if (is_multi_drv)
	{
		interval = I40E_QUEUE_ITR_INTERVAL_MAX;
	}
	else
	{
		if (is_pf)
		{
			interval = I40E_QUEUE_ITR_INTERVAL_DEFAULT;
		}
		else
		{
			interval = I40E_VF_QUEUE_ITR_INTERVAL_DEFAULT;
		}
	}

	/* Convert to hardware count, as writing each 1 represents 2 us */
	return interval / 2;
}

int i40e_generate_inset_mask_reg(uint64_t inset, uint32_t *mask, uint8_t nb_elem);

uint64_t i40e_get_default_input_set(uint16_t pctype);

extern const struct rte_flow_ops i40e_flow_ops;

const struct rte_memzone *i40e_memzone_reserve(const char *name, uint32_t len, int socket_id);

#define I40E_DEV_TO_PCI(eth_dev) \
	RTE_DEV_TO_PCI((eth_dev)->device)

#define I40E_VLAN_TAG_SIZE        4

#define I40E_AQ_LEN               32
#define I40E_AQ_BUF_SZ            4096
/* Number of queues per TC should be one of 1, 2, 4, 8, 16, 32, 64 */
#define I40E_MAX_Q_PER_TC         64
#define I40E_NUM_DESC_DEFAULT     512
#define I40E_NUM_DESC_ALIGN       32
#define I40E_BUF_SIZE_MIN         1024
#define I40E_FRAME_SIZE_MAX       9728
#define I40E_TSO_FRAME_SIZE_MAX   262144
#define I40E_QUEUE_BASE_ADDR_UNIT 128
/* number of VSIs and queue default setting */
#define I40E_MAX_QP_NUM_PER_VF    16
#define I40E_DEFAULT_QP_NUM_FDIR  1
#define I40E_UINT32_BIT_SIZE      (CHAR_BIT * sizeof(uint32_t))
#define I40E_VFTA_SIZE            (4096 / I40E_UINT32_BIT_SIZE)
/* Maximun number of MAC addresses */
#define I40E_NUM_MACADDR_MAX       64
/* Maximum number of VFs */
#define I40E_MAX_VF               128
/*flag of no loopback*/
#define I40E_AQ_LB_MODE_NONE	  0x0
/*
 * vlan_id is a 12 bit number.
 * The VFTA array is actually a 4096 bit array, 128 of 32bit elements.
 * 2^5 = 32. The val of lower 5 bits specifies the bit in the 32bit element.
 * The higher 7 bit val specifies VFTA array index.
 */
#define I40E_VFTA_BIT(vlan_id)    (1 << ((vlan_id) & 0x1F))
#define I40E_VFTA_IDX(vlan_id)    ((vlan_id) >> 5)

/* Default TC traffic in case DCB is not enabled */
#define I40E_DEFAULT_TCMAP        0x1
#define I40E_FDIR_QUEUE_ID        0

/* Always assign pool 0 to main VSI, VMDQ will start from 1 */
#define I40E_VMDQ_POOL_BASE       1

#define I40E_DEFAULT_RX_FREE_THRESH  32
#define I40E_DEFAULT_RX_PTHRESH      8
#define I40E_DEFAULT_RX_HTHRESH      8
#define I40E_DEFAULT_RX_WTHRESH      0

#define I40E_DEFAULT_TX_FREE_THRESH  32
#define I40E_DEFAULT_TX_PTHRESH      32
#define I40E_DEFAULT_TX_HTHRESH      0
#define I40E_DEFAULT_TX_WTHRESH      0
#define I40E_DEFAULT_TX_RSBIT_THRESH 32

/* Bit shift and mask */
#define I40E_4_BIT_WIDTH  (CHAR_BIT / 2)
#define I40E_4_BIT_MASK   RTE_LEN2MASK(I40E_4_BIT_WIDTH, uint8_t)
#define I40E_8_BIT_WIDTH  CHAR_BIT
#define I40E_8_BIT_MASK   UINT8_MAX
#define I40E_16_BIT_WIDTH (CHAR_BIT * 2)
#define I40E_16_BIT_MASK  UINT16_MAX
#define I40E_32_BIT_WIDTH (CHAR_BIT * 4)
#define I40E_32_BIT_MASK  UINT32_MAX
#define I40E_48_BIT_WIDTH (CHAR_BIT * 6)
#define I40E_48_BIT_MASK  RTE_LEN2MASK(I40E_48_BIT_WIDTH, uint64_t)

#define I40E_WRITE_GLB_REG(hw, reg, value)				\
	do {								\
		uint32_t ori_val;					\
		struct rte_eth_dev *dev;				\
		ori_val = I40E_READ_REG((hw), (reg));			\
		dev = ((struct i40e_adapter *)hw->back)->eth_dev;	\
		I40E_PCI_REG_WRITE(I40E_PCI_REG_ADDR((hw),		\
						     (reg)), (value));	\
		if (ori_val != value)					\
			PMD_DRV_LOG(WARNING,				\
				    "i40e device %s changed global "	\
				    "register [0x%08x]. original: 0x%08x, " \
				    "new: 0x%08x ",			\
				    (dev->device->name), (reg),		\
				    (ori_val), (value));		\
	} while (0)



#define I40E_MISC_VEC_ID                RTE_INTR_VEC_ZERO_OFFSET
#define I40E_RX_VEC_START               RTE_INTR_VEC_RXTX_OFFSET

/* Default queue interrupt throttling time in microseconds */
#define I40E_ITR_INDEX_DEFAULT          0
#define I40E_ITR_INDEX_NONE             3
#define I40E_QUEUE_ITR_INTERVAL_DEFAULT 32 /* 32 us */
#define I40E_QUEUE_ITR_INTERVAL_MAX     8160 /* 8160 us */
#define I40E_VF_QUEUE_ITR_INTERVAL_DEFAULT 32 /* 32 us */

#define I40E_GL_SWT_L2TAGCTRL(_i)             (0x001C0A70 + ((_i) * 4))
#define I40E_GL_SWT_L2TAGCTRL_ETHERTYPE_SHIFT 16
#define I40E_GL_SWT_L2TAGCTRL_ETHERTYPE_MASK  \
	I40E_MASK(0xFFFF, I40E_GL_SWT_L2TAGCTRL_ETHERTYPE_SHIFT)


#define I40E_MAX_PERCENT            100
#define I40E_DEFAULT_DCB_APP_NUM    1
#define I40E_DEFAULT_DCB_APP_PRIO   3

/**
 * The overhead from MTU to max frame size.
 * Considering QinQ packet, the VLAN tag needs to be counted twice.
 */
#define I40E_ETH_OVERHEAD \
	(RTE_ETHER_HDR_LEN + RTE_ETHER_CRC_LEN + I40E_VLAN_TAG_SIZE * 2)
