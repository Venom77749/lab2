#include <iostream>
#include <vector>
#include <map>

int main() {
    setlocale(LC_ALL, "rus");

    std::vector<int> V = { 123, 47, 158, 22, 97, 85, 42, 28 };

    std::multimap<int, int> M;

    for (auto it = V.begin(); it != V.end(); ++it) {
        int key = (*it) % 10;
        M.insert(std::make_pair(key, *it));
    }

    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << "Ключ: " << it->first << ", Значение: " << it->second << std::endl;
    }

    return 0;
}
