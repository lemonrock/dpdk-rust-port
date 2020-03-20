struct pool_entry
{
	LIST_ENTRY(pool_entry) next;
	uint16_t base;
	uint16_t len;
};