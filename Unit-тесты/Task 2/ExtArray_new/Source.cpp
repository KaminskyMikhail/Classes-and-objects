#include <cassert>
#include <iostream>
#include <stdexcept>
#include "Header.h"

void test_mean_range() {
    std::cout << "Testing mean(start, end)... " << std::endl;

    // Тест 1: Обычный случай с целыми числами
    {
        ExtArray<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        double result = arr.mean(2, 6); // Диапазон: 3, 4, 5, 6
        assert(result == 4.5);
        std::cout << "  Test 1 (integers, range [2,6)): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 2: Диапазон с начала массива
    {
        ExtArray<int> arr = { 10, 20, 30, 40, 50 };
        double result = arr.mean(0, 3); // Диапазон: 10, 20, 30
        assert(result == 20.0);
        std::cout << "  Test 2 (range [0,3)): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 3: Диапазон до конца массива
    {
        ExtArray<int> arr = { 1, 3, 5, 7, 9, 11 };
        double result = arr.mean(3, 6); // Диапазон: 7, 9, 11
        assert(result == 9.0);
        std::cout << "  Test 3 (range [3,6)): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 4: Диапазон из одного элемента
    {
        ExtArray<int> arr = { 100, 200, 300, 400 };
        double result = arr.mean(2, 3); // Диапазон: 300
        assert(result == 300.0);
        std::cout << "  Test 4 (single element): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 5: Числа с плавающей точкой
    {
        ExtArray<double> arr = { 1.5, 2.5, 3.5, 4.5, 5.5 };
        double result = arr.mean(1, 4); // Диапазон: 2.5, 3.5, 4.5
        assert(result == 3.5);
        std::cout << "  Test 5 (floating point): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 6: Пустой массив
    {
        ExtArray<int> arr = {};
        double result = arr.mean(0, 0);
        assert(result == 0.0);
        std::cout << "  Test 6 (empty array): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 7: Отрицательные числа
    {
        ExtArray<int> arr = { -10, -5, 0, 5, 10, 15 };
        double result = arr.mean(1, 5); // Диапазон: -5, 0, 5, 10
        assert(result == 2.5);
        std::cout << "  Test 7 (negative numbers): PASSED (result = " << result << ")" << std::endl;
    }

    std::cout << "  All range mean tests PASSED" << std::endl;
}

void test_mean_range_exceptions() {
    std::cout << "Testing mean(start, end) exceptions... " << std::endl;

    ExtArray<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Тест 1: start >= end
    {
        try {
            arr.mean(5, 3);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 1 (start >= end): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    // Тест 2: start == end
    {
        try {
            arr.mean(3, 3);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 2 (start == end): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    // Тест 3: start >= size
    {
        try {
            arr.mean(10, 12);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 3 (start >= size): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    // Тест 4: end > size
    {
        try {
            arr.mean(2, 11);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 4 (end > size): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    // Тест 5: start > size
    {
        try {
            arr.mean(15, 20);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 5 (start > size): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    // Тест 6: Пустой массив с некорректным диапазоном
    {
        ExtArray<int> empty = {};
        try {
            empty.mean(1, 2);
            assert(false && "Expected std::invalid_argument exception");
        }
        catch (const std::invalid_argument& e) {
            std::cout << "  Test 6 (empty array with invalid range): PASSED - " << e.what() << std::endl;
        }
        catch (...) {
            assert(false && "Unexpected exception type");
        }
    }

    std::cout << "  All exception tests PASSED" << std::endl;
}

void test_original_mean() {
    std::cout << "Testing original mean()... " << std::endl;

    // Тест 1: Обычный массив
    {
        ExtArray<int> arr = { 1, 2, 3, 4, 5 };
        double result = arr.mean();
        assert(result == 3.0);
        std::cout << "  Test 1 (regular array): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 2: Пустой массив
    {
        ExtArray<int> arr = {};
        double result = arr.mean();
        assert(result == 0.0);
        std::cout << "  Test 2 (empty array): PASSED (result = " << result << ")" << std::endl;
    }

    // Тест 3: Один элемент
    {
        ExtArray<int> arr = { 42 };
        double result = arr.mean();
        assert(result == 42.0);
        std::cout << "  Test 3 (single element): PASSED (result = " << result << ")" << std::endl;
    }

    std::cout << "  Original mean tests PASSED" << std::endl;
}

void test_comparison_between_means() {
    std::cout << "Testing comparison between mean() and mean(start, end)... " << std::endl;

    ExtArray<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Тест 1: mean(0, size) должно быть равно mean()
    {
        double full_range = arr.mean(0, arr.size());
        double full_array = arr.mean();
        assert(full_range == full_array);
        std::cout << "  Test 1 (mean(0, size) == mean()): PASSED (both = " << full_range << ")" << std::endl;
    }

    // Тест 2: Проверка, что range mean корректно вычисляет среднее для подмножества
    {
        ExtArray<int> subset = { 4, 5, 6, 7, 8 }; // элементы с индексами 3-7
        double subset_mean = subset.mean();
        double range_mean = arr.mean(3, 8);
        assert(subset_mean == range_mean);
        std::cout << "  Test 2 (range mean matches subset mean): PASSED (both = " << subset_mean << ")" << std::endl;
    }

    std::cout << "  Comparison tests PASSED" << std::endl;
}

int main() {
    std::cout << "=== Testing ExtArray Class (Mean Overload) ===" << std::endl;
    std::cout << std::endl;

    try {
        test_original_mean();
        std::cout << std::endl;

        test_mean_range();
        std::cout << std::endl;

        test_mean_range_exceptions();
        std::cout << std::endl;

        test_comparison_between_means();
        std::cout << std::endl;

        std::cout << "=== ALL TESTS PASSED ===" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "TEST FAILED: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}