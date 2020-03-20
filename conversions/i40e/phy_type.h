
#define I40E_PHY_TYPE_SUPPORT_40G(phy_type) \
	(((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_KR4) || \
	((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_CR4_CU) || \
	((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_AOC) || \
	((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_CR4) || \
	((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_SR4) || \
	((phy_type) & I40E_CAP_PHY_TYPE_40GBASE_LR4))

#define I40E_PHY_TYPE_SUPPORT_25G(phy_type) \
	(((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_KR) || \
	((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_CR) || \
	((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_SR) || \
	((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_LR) || \
	((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_AOC) || \
	((phy_type) & I40E_CAP_PHY_TYPE_25GBASE_ACC))
