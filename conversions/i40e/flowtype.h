
#define I40E_VALID_FLOW(flow_type) \
	((flow_type) == RTE_ETH_FLOW_FRAG_IPV4 || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV4_TCP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV4_UDP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV4_SCTP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV4_OTHER || \
	(flow_type) == RTE_ETH_FLOW_FRAG_IPV6 || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV6_TCP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV6_UDP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV6_SCTP || \
	(flow_type) == RTE_ETH_FLOW_NONFRAG_IPV6_OTHER || \
	(flow_type) == RTE_ETH_FLOW_L2_PAYLOAD)
