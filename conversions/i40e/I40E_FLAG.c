/* i40e flags */
#define I40E_FLAG_RSS                   (1ULL << 0)
#define I40E_FLAG_DCB                   (1ULL << 1)
#define I40E_FLAG_VMDQ                  (1ULL << 2)
#define I40E_FLAG_SRIOV                 (1ULL << 3)
#define I40E_FLAG_HEADER_SPLIT_DISABLED (1ULL << 4)
#define I40E_FLAG_HEADER_SPLIT_ENABLED  (1ULL << 5)
#define I40E_FLAG_FDIR                  (1ULL << 6)
#define I40E_FLAG_VXLAN                 (1ULL << 7)
#define I40E_FLAG_RSS_AQ_CAPABLE        (1ULL << 8)
#define I40E_FLAG_VF_MAC_BY_PF          (1ULL << 9)
#define I40E_FLAG_ALL (I40E_FLAG_RSS | \
		       I40E_FLAG_DCB | \
		       I40E_FLAG_VMDQ | \
		       I40E_FLAG_SRIOV | \
		       I40E_FLAG_HEADER_SPLIT_DISABLED | \
		       I40E_FLAG_HEADER_SPLIT_ENABLED | \
		       I40E_FLAG_FDIR | \
		       I40E_FLAG_VXLAN | \
		       I40E_FLAG_RSS_AQ_CAPABLE | \
		       I40E_FLAG_VF_MAC_BY_PF)