#ifndef _RTE_ATOMIC_H_
#define _RTE_ATOMIC_H_

#include <emmintrin.h>

#define	rte_compiler_barrier() do {		\
	asm volatile ("" : : : "memory");	\
} while(0)

#define rte_io_rmb() rte_compiler_barrier()
	
#define rte_io_wmb() rte_compiler_barrier()

#define	rte_rmb() _mm_lfence()

#define	rte_wmb() _mm_sfence()
	
#endif
