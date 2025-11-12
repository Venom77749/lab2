#include <iostream>
#include <vector>
#include <algorithm>
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


    std::stable_partition(L.begin(), mid, [](int x) { return x % 2 == 0; });
    std::stable_partition(mid, L.end(), [](int x) { return x % 2 == 0; });


    std::cout << "Результат:\n";
    for (int x : L) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
