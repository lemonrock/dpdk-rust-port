#ifndef _RTE_SPINLOCK_H_
#define _RTE_SPINLOCK_H_

/**
 * The rte_spinlock_t type.
 */
typedef struct {
	volatile int locked; /**< lock status 0 = unlocked, 1 = locked */
} rte_spinlock_t;

/**
 * A static spinlock initializer.
 */
#define RTE_SPINLOCK_INITIALIZER { 0 }

/**
 * Initialize the spinlock to an unlocked state.
 *
 * @param sl
 *   A pointer to the spinlock.
 */
static inline void
rte_spinlock_init(rte_spinlock_t *sl)
{
	sl->locked = 0;
}

static inline void
rte_spinlock_lock(rte_spinlock_t *sl)
{
	int lock_val = 1;
	asm volatile (
			"1:\n"
			"xchg %[locked], %[lv]\n"
			"test %[lv], %[lv]\n"
			"jz 3f\n"
			"2:\n"
			"pause\n"
			"cmpl $0, %[locked]\n"
			"jnz 2b\n"
			"jmp 1b\n"
			"3:\n"
			: [locked] "=m" (sl->locked), [lv] "=q" (lock_val)
			: "[lv]" (lock_val)
			: "memory");
}

static inline void
rte_spinlock_unlock (rte_spinlock_t *sl)
{
	int unlock_val = 0;
	asm volatile (
			"xchg %[locked], %[ulv]\n"
			: [locked] "=m" (sl->locked), [ulv] "=q" (unlock_val)
			: "[ulv]" (unlock_val)
			: "memory");
}

static inline int
rte_spinlock_trylock (rte_spinlock_t *sl)
{
	int lockval = 1;

	asm volatile (
			"xchg %[locked], %[lockval]"
			: [locked] "=m" (sl->locked), [lockval] "=q" (lockval)
			: "[lockval]" (lockval)
			: "memory");

	return lockval == 0;
}

#endif
