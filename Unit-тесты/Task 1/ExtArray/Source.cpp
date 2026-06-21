#include <cassert>
#include <iostream>
#include "extended_array.h"

void test_constructor_and_size() {
    std::cout << "Testing constructor and size()... ";

    ExtArray<int> arr1 = { 1, 2, 3, 4, 5 };
    assert(arr1.size() == 5);

    ExtArray<int> arr2(3);
    assert(arr2.size() == 3);

    ExtArray<int> arr3 = {};
    assert(arr3.size() == 0);

    ExtArray<int> arr4(0);
    assert(arr4.size() == 0);

    std::cout << "PASSED" << std::endl;
}

void test_operator_brackets() {
    std::cout << "Testing operator[]... ";

    ExtArray<int> arr = { 1, 2, 3, 4, 5 };
    assert(arr[0] == 1);
    assert(arr[4] == 5);
    arr[2] = 10;
    assert(arr[2] == 10);

    // Пустой массив - проверка доступа не требуется,
    // но убедимся, что он существует
    ExtArray<int> empty = {};
    assert(empty.size() == 0);

    std::cout << "PASSED" << std::endl;
}

void test_mean() {
    std::cout << "Testing mean()... ";

    ExtArray<int> arr1 = { 1, 2, 3, 4, 5 };
    assert(arr1.mean() == 3.0);

    ExtArray<int> arr2 = { 10, 20, 30, 40 };
    assert(arr2.mean() == 25.0);

    ExtArray<int> arr3 = { 5 };
    assert(arr3.mean() == 5.0);

    // Пустой массив - возвращаем 0
    ExtArray<int> arr4 = {};
    assert(arr4.mean() == 0.0);

    std::cout << "PASSED" << std::endl;
}

void test_median() {
    std::cout << "Testing median()... ";

    // Нечетное количество элементов
    ExtArray<int> arr1 = { 5, 2, 8, 1, 9 };
    assert(arr1.median() == 5.0);

    // Четное количество элементов
    ExtArray<int> arr2 = { 1, 2, 3, 4 };
    assert(arr2.median() == 2.5);

    // Один элемент
    ExtArray<int> arr3 = { 42 };
    assert(arr3.median() == 42.0);

    // Пустой массив - возвращаем 0
    ExtArray<int> arr4 = {};
    assert(arr4.median() == 0.0);

    // С плавающей точкой
    ExtArray<double> arr5 = { 1.5, 2.5, 3.5 };
    assert(arr5.median() == 2.5);

    std::cout << "PASSED" << std::endl;
}

void test_mode() {
    std::cout << "Testing mode()... ";

    // Один режим
    ExtArray<int> arr1 = { 1, 2, 2, 3, 4, 4, 4, 5 };
    auto result1 = arr1.mode();
    assert(result1.first == 4);
    assert(result1.second == 3);

    // Все элементы уникальны
    ExtArray<int> arr2 = { 1, 2, 3, 4, 5 };
    auto result2 = arr2.mode();
    assert(result2.first == 1);
    assert(result2.second == 1);

    // Один элемент
    ExtArray<int> arr3 = { 42 };
    auto result3 = arr3.mode();
    assert(result3.first == 42);
    assert(result3.second == 1);

    // Пустой массив - возвращаем (0, 0)
    ExtArray<int> arr4 = {};
    auto result4 = arr4.mode();
    assert(result4.first == 0);
    assert(result4.second == 0);

    // С плавающей точкой
    ExtArray<double> arr5 = { 1.1, 2.2, 2.2, 3.3 };
    auto result5 = arr5.mode();
    assert(result5.first == 2.2);
    assert(result5.second == 2);

    std::cout << "PASSED" << std::endl;
}

void test_edge_cases() {
    std::cout << "Testing edge cases... ";

    // Массив с отрицательными числами
    ExtArray<int> arr1 = { -5, -3, -1, -3, -2 };
    assert(arr1.mean() == -2.8);
    assert(arr1.median() == -3.0);
    auto result1 = arr1.mode();
    assert(result1.first == -3);
    assert(result1.second == 2);

    // Массив с одинаковыми элементами
    ExtArray<int> arr2 = { 7, 7, 7, 7, 7 };
    assert(arr2.mean() == 7.0);
    assert(arr2.median() == 7.0);
    auto result2 = arr2.mode();
    assert(result2.first == 7);
    assert(result2.second == 5);

    // Большой массив
    ExtArray<int> arr3(1000);
    for (int i = 0; i < 1000; i++) {
        arr3[i] = i;
    }
    assert(arr3.mean() == 499.5);

    std::cout << "PASSED" << std::endl;
}

int main() {
    std::cout << "=== Testing ExtArray Class ===" << std::endl;
    std::cout << std::endl;

    test_constructor_and_size();
    test_operator_brackets();
    test_mean();
    test_median();
    test_mode();
    test_edge_cases();

    std::cout << std::endl;
    std::cout << "=== ALL TESTS PASSED ===" << std::endl;

    return 0;
}