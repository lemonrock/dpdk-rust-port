
#define I40E_MAX_FDIR_FILTER_NUM   (1024 * 8)

struct i40e_fdir_filter
{
	TAILQ_ENTRY(i40e_fdir_filter) rules;
	struct i40e_fdir_filter_conf fdir;
};
