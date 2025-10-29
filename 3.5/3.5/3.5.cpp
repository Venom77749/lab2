// Даны списки L1 и L2; список L1 имеет нечетное количество элементов.
// Переместить средний элемент списка L1 в конец списка L2.
// Использовать один вызов функции - члена splice.

#include <iostream>
#include <list>

int main()
{
    setlocale(LC_ALL, "rus");

    int size1{}, size2{};
    std::list<int>L1(size1);
    std::list<int>L2(size2);

    std::cout << "Введите нечетный размер первого листа: ";
    std::cin >> size1;
    while (size1 % 2 == 0)
    {
        std::cout << "Неверный ввод." << std::endl;
        std::cout << "Введите нечетный размер первого листа: ";
        std::cin >> size1;
    }

    std::cout << "Введите размер второго листа: ";
    std::cin >> size2;
    
    std::cout << "Введите элементы первого листа: ";
    for (int i{}; i < size1; ++i)
    {
        int val{}; std::cin >> val;
        L1.push_back(val);
    }

    std::cout << "Введите элементы второго листа: ";
    for (int i{}; i < size1; ++i)
    {
        int val{}; std::cin >> val;
        L2.push_back(val);
    }

    std::list<int>::iterator it = L1.begin();
    std::advance(it, size1 / 2);

    L2.splice(L2.end(), L1, it);

    std::cout << "L1 после изменений: ";
    for (std::list<int>::iterator it = L1.begin(); it != L1.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nL2 после изменений: ";
    for (std::list<int>::iterator it = L2.begin(); it != L2.end(); ++it)
        std::cout << *it << " ";
}
