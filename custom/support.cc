#include <random>

std::random_device rand_device;
std::uniform_int_distribution<uint32_t> rand_dist(0, std::numeric_limits<uint32_t>::max());

extern "C" uint32_t lwip_support_rand() {
    return rand_dist();
}
