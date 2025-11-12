#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits> 

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    std::cout << "Введите количество элементов: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Ошибка: введите положительное целое число.\nВведите количество элементов: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> L;
    std::cout << "Введите элементы (целые числа):\n";
    for (int i = 0; i < n; ++i) {
        int val;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите целое число.\nВведите элемент #" << i + 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        L.push_back(val);
    }

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

    std::cout << "Результат:\n";
    for (int x : L) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
