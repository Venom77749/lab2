#include <iostream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "rus");

    int n{};
    std::cout << "Введите размер вектора: ";
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int>::iterator iter;

    for (int i{}; i < n; ++i)
    {
        std::cout << i + 1 << ": ";
        std::cin >> vec[i];
    }

    for (iter = vec.begin(); iter != vec.end(); ++iter)
    {
        iter = vec.insert(++iter, 1);
    }

    for (int i{}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    return EXIT_SUCCESS;
}
