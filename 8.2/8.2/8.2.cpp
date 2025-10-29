#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <iterator>

int main() {
    std::vector<std::string> L = { "ABC", "DEF", "KLM", "XYZ" };
    std::deque<std::string> D;

    std::adjacent_difference(
        L.begin(), L.end(),
        std::back_inserter(D),
        [](const std::string& right, const std::string& left) {
            return std::string(1, left[0]) + right.back();
        }
    );

    D.erase(D.begin());

    for (const auto& s : D) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}