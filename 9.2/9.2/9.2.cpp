#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "rus");

    std::vector<int> V0 = { 2, 3, 3 };
    int N = 3;
    std::vector<std::vector<int>> vectors = {
        {1, 2, 3, 3, 4},
        {2, 3},
        {2, 3, 3, 3, 5}
    };

    std::multiset<int> msV0(V0.begin(), V0.end());

    int count = 0;
    for (int i = 0; i < N; ++i) {
        std::multiset<int> msVI(vectors[i].begin(), vectors[i].end());

        if (std::includes(msVI.begin(), msVI.end(), msV0.begin(), msV0.end())) {
            ++count;
        }
    }

    std::cout << "Количество векторов, содержащих все элементы V0: " << count << std::endl;

    return 0;
}
