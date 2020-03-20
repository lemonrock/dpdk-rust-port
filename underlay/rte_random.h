#ifndef _RTE_RANDOM_H_
#define _RTE_RANDOM_H_

#include <stdint.h>

/**
 * Get a pseudo-random value.
 *
 * The generator is not cryptographically secure.
 *
 * If called from lcore threads, this function is thread-safe.
 *
 * @return
 *   A pseudo-random value between 0 and (1<<64)-1.
 */
uint64_t
rte_rand(void);

#endif
