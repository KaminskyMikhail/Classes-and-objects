#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <typeinfo>

template <typename T>
class ExtArray
{
private:
	std::vector<T> arr;
	size_t n;  // Переименовал size в n

public:
	ExtArray(std::initializer_list<T> l) : arr(l)
	{
		n = l.size();
	}

	ExtArray(int size) : n(size)
	{
		arr.resize(n);
	}

	T& operator[](size_t i)
	{
		return arr[i];
	}

	size_t size()  // Теперь метод не конфликтует с переменной
	{
		return n;
	}

	// Среднее для всего массива
	double mean()
	{
		if (n == 0) return 0;

		double sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];
		return sum / n;
	}

	// Среднее для диапазона
	double mean(size_t start, size_t end)
	{
		if (start >= end)
			throw std::invalid_argument("start >= end");
		if (start >= n)
			throw std::invalid_argument("start out of range");
		if (end > n)
			throw std::invalid_argument("end out of range");
		if (n == 0) return 0;

		double sum = 0;
		for (int i = start; i < end; i++)
			sum += arr[i];
		return sum / (end - start);
	}

	// Медиана
	double median()
	{
		if (n == 0) return 0;

		std::vector<T> temp = arr;
		std::sort(temp.begin(), temp.end());

		if (n % 2 == 1)
			return temp[n / 2];
		else
			return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
	}

	// Мода
	std::pair<T, int> mode()
	{
		if (n == 0) return std::pair<T, int>(T(), 0);

		T max_val = arr[0];
		int max_count = 0;

		for (int i = 0; i < n; i++)
		{
			int count = 0;
			for (int j = i; j < n; j++)
			{
				if (arr[j] == arr[i])
					count++;
			}
			if (count > max_count)
			{
				max_count = count;
				max_val = arr[i];
			}
		}
		return std::pair<T, int>(max_val, max_count);
	}

	// Контрольная сумма для битовых массивов
	size_t checkSum()
	{
		// Проверяем тип
		if (typeid(T) != typeid(bool) && typeid(T) != typeid(int))
			throw std::bad_typeid();

		if (n == 0) return 0;

		int count = 0;

		// Для int проверяем что только 0 и 1
		if (typeid(T) == typeid(int))
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] != 0 && arr[i] != 1)
					throw std::logic_error("not 0 or 1");
				if (arr[i] == 1)
					count++;
			}
		}
		else // для bool
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] == true)
					count++;
			}
		}

		return count;
	}
};