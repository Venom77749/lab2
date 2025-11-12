#include <iostream>
#include <vector>
#include <map>
#include <limits> 

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    std::cout << "Введите количество элементов вектора: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Ошибка: введите положительное целое число.\nВведите количество элементов вектора: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> V;
    std::cout << "Введите элементы (целые числа):\n";
    for (int i = 0; i < n; ++i) {
        int val;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите целое число.\nВведите элемент #" << i + 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        V.push_back(val);
    }

    std::multimap<int, int> M;

    for (auto it = V.begin(); it != V.end(); ++it) {
        int key = (*it) % 10;
        M.insert(std::make_pair(key, *it));
    }

    std::cout << "Результат группировки по последней цифре:\n";
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << "Ключ: " << it->first << ", Значение: " << it->second << std::endl;
    }

    return EXIT_SUCCESS;
}
