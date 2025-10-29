#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <limits>

int main()
{
    setlocale(LC_ALL, "rus");

    std::string name{ "in.txt" };
    int k{};

    std::cout << "Введите количество символов K(>0): ";
    while (true) {
        std::cin >> k;
        if (std::cin.fail() || k <= 0) {
            std::cout << "Неверный ввод! Введите целое число больше 0: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else break;
    }

    std::ofstream file(name);
    if (file.is_open())
    {
        std::fill_n(std::ostream_iterator<char>(file), k, '*');
        std::cout << "Файл успешно записан: " << name << std::endl;
    }
    else
    {
        std::cout << "Не удалось открыть файл: " << name << std::endl;
    }
    return 0;
}
