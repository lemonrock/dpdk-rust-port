static int i40e_get_cap(struct i40e_hw *hw);
static void i40e_stat_update_32(struct i40e_hw *hw, uint32_t reg, bool offset_loaded, uint64_t *offset, uint64_t *stat);
static void i40e_stat_update_48(struct i40e_hw *hw, uint32_t hireg, uint32_t loreg, bool offset_loaded, uint64_t *offset, uint64_t *stat);
static void i40e_pf_config_irq0(struct i40e_hw *hw, bool no_queue);
static int i40e_dev_sync_phy_type(struct i40e_hw *hw);
static void i40e_configure_registers(struct i40e_hw *hw);
static int i40e_config_qinq(struct i40e_hw *hw, struct i40e_vsi *vsi);
static enum i40e_status_code i40e_aq_del_mirror_rule(struct i40e_hw *hw, uint16_t seid, uint16_t rule_type, uint16_t *entries, uint16_t count, uint16_t rule_id);

void i40e_check_write_reg(struct i40e_hw *hw, uint32_t addr, uint32_t val);
void i40e_check_write_global_reg(struct i40e_hw *hw, uint32_t addr, uint32_t val);
void i40e_flex_payload_reg_set_default(struct i40e_hw *hw);
int i40e_switch_rx_queue(struct i40e_hw *hw, uint16_t q_idx, bool on);
int i40e_switch_tx_queue(struct i40e_hw *hw, uint16_t q_idx, bool on);
void i40e_pf_disable_irq0(struct i40e_hw *hw);
void i40e_pf_enable_irq0(struct i40e_hw *hw);
int i40e_select_filter_input_set(struct i40e_hw *hw, struct rte_eth_input_set_conf *conf, enum rte_filter_type filter);
int i40e_hash_filter_inset_select(struct i40e_hw *hw, struct rte_eth_input_set_conf *conf);

static inline void i40e_init_adminq_parameter(struct i40e_hw *hw)
{
	hw->aq.num_arq_entries = I40E_AQ_LEN;
	hw->aq.num_asq_entries = I40E_AQ_LEN;
	hw->aq.arq_buf_size = I40E_AQ_BUF_SZ;
	hw->aq.asq_buf_size = I40E_AQ_BUF_SZ;
}
