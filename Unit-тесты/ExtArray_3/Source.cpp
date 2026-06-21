#include <cassert>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "Header.h"

using namespace std;

void test_checkSum()
{
	cout << "=== Testing checkSum ===" << endl;

	// 1. Проверка типа

	// bool - работает
	ExtArray<bool> b = { true, false, true };
	try {
		cout << "  bool array: " << b.checkSum() << " (should work)" << endl;
	}
	catch (...) {
		cout << "  bool array: FAIL" << endl;
	}

	// int - работает
	ExtArray<int> i = { 1, 0, 1 };
	try {
		cout << "  int array: " << i.checkSum() << " (should work)" << endl;
	}
	catch (...) {
		cout << "  int array: FAIL" << endl;
	}

	// double - ошибка
	ExtArray<double> d = { 1.0, 0.0 };
	try {
		d.checkSum();
		cout << "  double array: FAIL (should throw)" << endl;
	}
	catch (bad_typeid&) {
		cout << "  double array: PASS (caught bad_typeid)" << endl;
	}

	// char - ошибка
	ExtArray<char> c = { '1', '0' };
	try {
		c.checkSum();
		cout << "  char array: FAIL (should throw)" << endl;
	}
	catch (bad_typeid&) {
		cout << "  char array: PASS (caught bad_typeid)" << endl;
	}

	cout << endl;

	// 2. Проверка содержимого

	// int с 0 и 1 - работает
	ExtArray<int> good = { 0, 1, 0, 1, 1 };
	try {
		int res = good.checkSum();
		cout << "  [0,1,0,1,1]: " << res << " (should be 3)" << endl;
		assert(res == 3);
	}
	catch (...) {
		cout << "  [0,1,0,1,1]: FAIL" << endl;
	}

	// int с 2 - ошибка
	ExtArray<int> bad1 = { 0, 1, 2, 1 };
	try {
		bad1.checkSum();
		cout << "  [0,1,2,1]: FAIL (should throw)" << endl;
	}
	catch (logic_error&) {
		cout << "  [0,1,2,1]: PASS (caught logic_error)" << endl;
	}

	// int с -1 - ошибка
	ExtArray<int> bad2 = { 0, 1, -1, 1 };
	try {
		bad2.checkSum();
		cout << "  [0,1,-1,1]: FAIL (should throw)" << endl;
	}
	catch (logic_error&) {
		cout << "  [0,1,-1,1]: PASS (caught logic_error)" << endl;
	}

	// int с 5 - ошибка
	ExtArray<int> bad3 = { 0, 1, 5, 1 };
	try {
		bad3.checkSum();
		cout << "  [0,1,5,1]: FAIL (should throw)" << endl;
	}
	catch (logic_error&) {
		cout << "  [0,1,5,1]: PASS (caught logic_error)" << endl;
	}

	cout << endl;

	// 3. Проверка правильности результата

	// Все единицы
	ExtArray<int> all_ones = { 1, 1, 1, 1 };
	size_t res1 = all_ones.checkSum();
	cout << "  all ones: " << res1 << " (should be 4)" << endl;
	assert(res1 == 4);

	// Все нули
	ExtArray<int> all_zeros = { 0, 0, 0, 0 };
	size_t res2 = all_zeros.checkSum();
	cout << "  all zeros: " << res2 << " (should be 0)" << endl;
	assert(res2 == 0);

	// Смешанные bool
	ExtArray<bool> mixed = { true, false, true, false, true };
	size_t res3 = mixed.checkSum();
	cout << "  [T,F,T,F,T]: " << res3 << " (should be 3)" << endl;
	assert(res3 == 3);

	// Пустой массив
	ExtArray<int> empty = {};
	size_t res4 = empty.checkSum();
	cout << "  empty: " << res4 << " (should be 0)" << endl;
	assert(res4 == 0);

	// int массив с 0 и 1
	ExtArray<int> mixed_int = { 0, 1, 1, 0, 1, 0 };
	size_t res5 = mixed_int.checkSum();
	cout << "  [0,1,1,0,1,0]: " << res5 << " (should be 3)" << endl;
	assert(res5 == 3);

	cout << endl << "=== ALL TESTS PASSED ===" << endl;
}

int main()
{
	try {
		test_checkSum();
	}
	catch (const exception& e) {
		cerr << "Test failed: " << e.what() << endl;
		return 1;
	}
	return 0;
}