#define I40E_FILTER_PCTYPE_INVALID     0
struct i40e_customized_pctype
{
	enum i40e_new_pctype index;  /* Indicate which customized pctype */
	uint8_t pctype;   /* New pctype value */
	bool valid;   /* Check if it's valid */
};
