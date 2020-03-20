#ifndef _RTE_DEBUG_H_
#define _RTE_DEBUG_H_

void __rte_panic(const char *funcname , const char *format, ...) __attribute__((cold)) __attribute__((noreturn)) __attribute__((format(printf, 2, 3)));

#define rte_panic_(func, format, ...) __rte_panic(func, format "%.0s", __VA_ARGS__)

#define rte_panic(...) rte_panic_(__func__, __VA_ARGS__, "dummy")

#define RTE_ASSERT(exp) do {} while (0)

#define	RTE_VERIFY(exp)	do {                                                  \
	if (unlikely(!(exp)))                                                           \
		rte_panic("line %d\tassert \"%s\" failed\n", __LINE__, #exp); \
} while (0)

#endif
