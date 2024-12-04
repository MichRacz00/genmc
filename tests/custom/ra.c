#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int x;
atomic_int y;
atomic_int z;

void *thread_one(void *arg)
{
	atomic_load_explicit(&x, memory_order_acquire);
	atomic_store_explicit(&x, 1, memory_order_release);
	return NULL;
}

void *thread_two(void *arg)
{
	atomic_load_explicit(&y, memory_order_acquire);
	atomic_store_explicit(&y, 1, memory_order_release);
	return NULL;
}

void *thread_three(void *arg)
{
	atomic_load_explicit(&z, memory_order_relaxed);
	atomic_store_explicit(&z, 1, memory_order_relaxed);
	return NULL;
}

int main()
{
	pthread_t t1, t2, t3;

	if (pthread_create(&t1, NULL, thread_one, NULL))
		abort();

	if (pthread_create(&t2, NULL, thread_two, NULL))
		abort();

	if (pthread_create(&t3, NULL, thread_three, NULL))
		abort();

	return 0;
}