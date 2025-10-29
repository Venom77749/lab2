#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::deque<int> D = { 1, 0, 2, 0, 3 };

    auto r = std::find(D.rbegin(), D.rend(), 0); 

    if (r != D.rend()) {
        D.erase(--r.base());
    }


    for (int x : D)
        std::cout << x << " ";
    std::cout << std::endl;
}
