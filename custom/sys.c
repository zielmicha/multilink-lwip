#include <lwip/sys.h>
#include <time.h>

u32_t sys_now (void)
{
    struct timespec spec;
    if(clock_gettime(CLOCK_MONOTONIC, &spec) != 0)
        abort();
    unsigned long long t = spec.tv_sec * 1000ull + spec.tv_nsec / 1000000ull;
    // FIXME: overflow every 50 days
    return (u32_t) t;
}
