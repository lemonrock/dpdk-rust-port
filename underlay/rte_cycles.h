#ifndef _RTE_CYCLES_H_
#define _RTE_CYCLES_H_

/**
 * Wait at least us microseconds.
 * This function can be replaced with user-defined function.
 * @see rte_delay_us_callback_register
 *
 * @param us
 *   The number of microseconds to wait.
 */
// Initial value is rte_delay_us_block
extern void
(*rte_delay_us)(unsigned int us);

void
rte_delay_us_sleep(unsigned int us);

#endif
