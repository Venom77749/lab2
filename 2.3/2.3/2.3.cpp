#include <iostream>
#include <vector>

int main()
{
    setlocale(LC_ALL, "rus");

    int n{};
    while (true)
    {
        std::cout << "Введите четное количество элементов в векторе: ";
        std::cin >> n;
        if (n % 2 == 0)
        {
            break;
        }
        else
        {
            std::cout << "Введите верное значение!" << std::endl;
        }
    }

    std::vector<int> vec(n);

    for (int i{}; i < n; ++i)
    {
        std::cout << i + 1 << ": ";
        std::cin >> vec[i];
    }

    for (int i{n / 2}; i < n; ++i)
    {
        std::cout << vec[i] << " ";
    }

    for (int i{}; i < n / 2; ++i)
    {
        std::cout << vec[i] << " ";
    }

    return EXIT_SUCCESS;
}
