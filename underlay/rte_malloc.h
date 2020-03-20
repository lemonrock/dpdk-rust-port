#ifndef _RTE_MALLOC_H_
#define _RTE_MALLOC_H_

/**
 * This function allocates memory from the huge-page area of memory. The memory
 * is not cleared. In NUMA systems, the memory allocated resides on the same
 * NUMA socket as the core that calls this function.
 *
 * @param type
 *   A string identifying the type of allocated objects (useful for debug
 *   purposes, such as identifying the cause of a memory leak). Can be NULL.
 * @param size
 *   Size (in bytes) to be allocated.
 * @param align
 *   If 0, the return is a pointer that is suitably aligned for any kind of
 *   variable (in the same manner as malloc()).
 *   Otherwise, the return is a pointer that is a multiple of *align*. In
 *   this case, it must be a power of two. (Minimum alignment is the
 *   cacheline size, i.e. 64-bytes)
 * @return
 *   - NULL on error. Not enough memory, or invalid arguments (size is 0,
 *     align is not a power of two).
 *   - Otherwise, the pointer to the allocated object.
 */
void *
rte_malloc(const char *type, size_t size, unsigned align);

/**
 * Allocate zero'ed memory from the heap.
 *
 * Equivalent to rte_malloc() except that the memory zone is
 * initialised with zeros. In NUMA systems, the memory allocated resides on the
 * same NUMA socket as the core that calls this function.
 *
 * @param type
 *   A string identifying the type of allocated objects (useful for debug
 *   purposes, such as identifying the cause of a memory leak). Can be NULL.
 * @param size
 *   Size (in bytes) to be allocated.
 * @param align
 *   If 0, the return is a pointer that is suitably aligned for any kind of
 *   variable (in the same manner as malloc()).
 *   Otherwise, the return is a pointer that is a multiple of *align*. In
 *   this case, it must obviously be a power of two. (Minimum alignment is the
 *   cacheline size, i.e. 64-bytes)
 * @return
 *   - NULL on error. Not enough memory, or invalid arguments (size is 0,
 *     align is not a power of two).
 *   - Otherwise, the pointer to the allocated object.
 */
void *
rte_zmalloc(const char *type, size_t size, unsigned align);

/**
 * Replacement function for calloc(), using huge-page memory. Memory area is
 * initialised with zeros. In NUMA systems, the memory allocated resides on the
 * same NUMA socket as the core that calls this function.
 *
 * @param type
 *   A string identifying the type of allocated objects (useful for debug
 *   purposes, such as identifying the cause of a memory leak). Can be NULL.
 * @param num
 *   Number of elements to be allocated.
 * @param size
 *   Size (in bytes) of a single element.
 * @param align
 *   If 0, the return is a pointer that is suitably aligned for any kind of
 *   variable (in the same manner as malloc()).
 *   Otherwise, the return is a pointer that is a multiple of *align*. In
 *   this case, it must obviously be a power of two. (Minimum alignment is the
 *   cacheline size, i.e. 64-bytes)
 * @return
 *   - NULL on error. Not enough memory, or invalid arguments (size is 0,
 *     align is not a power of two).
 *   - Otherwise, the pointer to the allocated object.
 */
void *
rte_calloc(const char *type, size_t num, size_t size, unsigned align);

/**
 * Replacement function for realloc(), using huge-page memory. Reserved area
 * memory is resized, preserving contents. In NUMA systems, the new area
 * may not reside on the same NUMA node as the old one.
 *
 * @param ptr
 *   Pointer to already allocated memory
 * @param size
 *   Size (in bytes) of new area. If this is 0, memory is freed.
 * @param align
 *   If 0, the return is a pointer that is suitably aligned for any kind of
 *   variable (in the same manner as malloc()).
 *   Otherwise, the return is a pointer that is a multiple of *align*. In
 *   this case, it must obviously be a power of two. (Minimum alignment is the
 *   cacheline size, i.e. 64-bytes)
 * @return
 *   - NULL on error. Not enough memory, or invalid arguments (size is 0,
 *     align is not a power of two).
 *   - Otherwise, the pointer to the reallocated memory.
 */
void *
rte_realloc(void *ptr, size_t size, unsigned int align);

/**
 * Frees the memory space pointed to by the provided pointer.
 *
 * This pointer must have been returned by a previous call to
 * rte_malloc(), rte_zmalloc(), rte_calloc() or rte_realloc(). The behaviour of
 * rte_free() is undefined if the pointer does not match this requirement.
 *
 * If the pointer is NULL, the function does nothing.
 *
 * @param ptr
 *   The pointer to memory to be freed.
 */
void
rte_free(void *ptr);

#endif
