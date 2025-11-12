#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

int main() {
    setlocale(LC_ALL, "rus");

    int nV0;
    std::cout << "Введите количество элементов вектора V0: ";
    while (!(std::cin >> nV0) || nV0 <= 0) {
        std::cout << "Ошибка: введите положительное целое число.\nВведите количество элементов вектора V0: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> V0;
    std::cout << "Введите элементы вектора V0 (целые числа):\n";
    for (int i = 0; i < nV0; ++i) {
        int val;
        while (!(std::cin >> val)) {
            std::cout << "Ошибка: введите целое число.\nВведите элемент #" << i + 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        V0.push_back(val);
    }

    int N;
    std::cout << "Введите количество проверяемых векторов: ";
    while (!(std::cin >> N) || N <= 0) {
        std::cout << "Ошибка: введите положительное целое число.\nВведите количество проверяемых векторов: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<std::vector<int>> vectors(N);
    for (int i = 0; i < N; ++i) {
        int sizeVec;
        std::cout << "Введите количество элементов вектора #" << i + 1 << ": ";
        while (!(std::cin >> sizeVec) || sizeVec < 0) {
            std::cout << "Ошибка: введите неотрицательное целое число.\nВведите количество элементов вектора #" << i + 1 << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Введите элементы вектора #" << i + 1 << " (целые числа):\n";
        vectors[i].resize(sizeVec);
        for (int j = 0; j < sizeVec; ++j) {
            while (!(std::cin >> vectors[i][j])) {
                std::cout << "Ошибка: введите целое число.\nВведите элемент #" << j + 1 << " вектора #" << i + 1 << ": ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    std::multiset<int> msV0(V0.begin(), V0.end());

    int count = 0;
    for (int i = 0; i < N; ++i) {
        std::multiset<int> msVI(vectors[i].begin(), vectors[i].end());

        if (std::includes(msVI.begin(), msVI.end(), msV0.begin(), msV0.end())) {
            ++count;
        }
    }

    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;

    return EXIT_SUCCESS;
}
