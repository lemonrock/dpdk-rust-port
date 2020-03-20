struct i40e_res_pool_info
{
	uint32_t base;              /* Resource start index */
	uint32_t num_alloc;         /* Allocated resource number */
	uint32_t num_free;          /* Total available resource number */
	struct res_list alloc_list; /* Allocated resource list */
	struct res_list free_list;  /* Available resource list */
};

static int i40e_res_pool_init(struct i40e_res_pool_info *pool, uint32_t base, uint32_t num);
static void i40e_res_pool_destroy(struct i40e_res_pool_info *pool);
static int i40e_res_pool_free(struct i40e_res_pool_info *pool, uint32_t base);
static int i40e_res_pool_alloc(struct i40e_res_pool_info *pool, uint16_t num);