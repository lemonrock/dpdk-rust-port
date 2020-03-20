#ifndef _RTE_COMMON_H_
#define _RTE_COMMON_H_

#define __rte_always_inline inline __attribute__((always_inline))

/** C extension macro for environments lacking C11 features. */
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
#define RTE_STD_C11 __extension__
#else
#define RTE_STD_C11
#endif

/**
 * Macro to return the minimum of two numbers
 */
#define RTE_MIN(a, b) \
	__extension__ ({ \
		typeof (a) _a = (a); \
		typeof (b) _b = (b); \
		_a < _b ? _a : _b; \
	})

/**
* Macro to return the maximum of two numbers
*/
#define RTE_MAX(a, b) \
__extension__ ({ \
	typeof (a) _a = (a); \
	typeof (b) _b = (b); \
	_a > _b ? _a : _b; \
})

#ifndef offsetof
/** Return the offset of a field in a structure. */
#define offsetof(TYPE, MEMBER)  __builtin_offsetof (TYPE, MEMBER)
#endif

/**
* Return pointer to the wrapping struct instance.
*
* Example:
*
*  struct wrapper {
*      ...
*      struct child c;
*      ...
*  };
*
*  struct child *x = obtain(...);
*  struct wrapper *w = container_of(x, struct wrapper, c);
*/
#ifndef container_of
#define container_of(ptr, type, member)	__extension__ ({		\
		const typeof(((type *)0)->member) *_ptr = (ptr); \
		__attribute__((unused)) type *_target_ptr =	\
			(type *)(ptr);				\
		(type *)(((uintptr_t)_ptr) - offsetof(type, member)); \
	})
#endif

/**
* Get the size of a field in a structure.
*
* @param type
*   The type of the structure.
* @param field
*   The field in the structure.
* @return
*   The size of the field in the structure, in bytes.
*/
#define RTE_SIZEOF_FIELD(type, field) (sizeof(((type *)0)->field))

/** Number of elements in the array. */
#define	RTE_DIM(a)	(sizeof (a) / sizeof ((a)[0]))

/** Physical address */
typedef uint64_t phys_addr_t;
#define RTE_BAD_PHYS_ADDR ((phys_addr_t)-1)

/**
 * IO virtual address type.
 * When the physical addressing mode (IOVA as PA) is in use,
 * the translation from an IO virtual address (IOVA) to a physical address
 * is a direct mapping, i.e. the same value.
 * Otherwise, in virtual mode (IOVA as VA), an IOMMU may do the translation.
 */
typedef uint64_t rte_iova_t;
#define RTE_BAD_IOVA ((rte_iova_t)-1)

#endif
		