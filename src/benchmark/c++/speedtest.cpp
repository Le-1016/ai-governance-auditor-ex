#include <iostream>
#include <chrono>

int main() {
    const long long N = 100000000;

    auto start = std::chrono::high_resolution_clock::now();

    volatile long long s = 0;

    for(long long i = 0; i < N; i++) {
        s += i;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << s << std::endl;
    std::cout << "time = "
              << std::chrono::duration<double>(end-start).count()
              << " s"
              << std::endl;
}