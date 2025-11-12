#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <limits>
#include <iterator>
#include <numeric>

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    std::cout << "Введите количество строк: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Ошибка: введите положительное целое число.\nВведите количество строк: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> L;
    std::cout << "Введите строки (по одной на строку):\n";
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::getline(std::cin, s);
        while (s.empty()) {
            std::cout << "Ошибка: строка не может быть пустой. Введите строку #" << i + 1 << ": ";
            std::getline(std::cin, s);
        }
        L.push_back(s);
    }

    std::deque<std::string> D;

    std::adjacent_difference(
        L.begin(), L.end(),
        std::back_inserter(D),
        [](const std::string& right, const std::string& left) {
            char left_first = left.empty() ? '?' : left[0];
            char right_last = right.empty() ? '?' : right.back();
            return std::string(1, left_first) + right_last;
        }
    );

    // Удаляем первый элемент, так как создаётся элемент исходя из предыдущих данных
    if (!D.empty()) {
        D.erase(D.begin());
    }

    std::cout << "Результат:\n";
    for (const auto& s : D) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
