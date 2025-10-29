#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> L = { 5, -1, 2, -7, 8, 3 }; 

    auto half = L.size() / 2;

    auto mid = L.begin();
    std::advance(mid, half);

    std::replace_copy_if(
        std::make_reverse_iterator(mid),        
        std::make_reverse_iterator(L.begin()),
        std::back_inserter(L), 
        [](int x) { return x < 0; },
        0  
    );

    for (int x : L) std::cout << x << " ";

    return 0;
}
