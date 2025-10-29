#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> L = { 3, 4, 6, 7, 5, 8, 10, 11 };
    auto half = L.size() / 2;

    auto mid = L.begin();
    std::advance(mid, half);

    // В первой половине: четные вначале
    std::stable_partition(L.begin(), mid, [](int x) { return x % 2 == 0; });

    // Во второй половине: четные вначале
    std::stable_partition(mid, L.end(), [](int x) { return x % 2 == 0; });

    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
