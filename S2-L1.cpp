// Лабораторная работа №1 (Второй семестр) Вариант №2 
//
// Оцените сложность алгоритма в лучшем, среднем и худшем случае. 
// Рассчитайте примерное время работы алгоритма. Запрограммируйте его. 
// Определите реальное время работы (воспользуйтесь классом Timer) и сравните с расчетным.
// 
// Ввод и вывод данных в расчете не учитывать. Считать, что 0 < N <= 10000.
// 
// Дана последовательность из N чисел. Посчитать количество простых чисел.

#include <iostream>
#define N_Max 1000

int NumberOfPrimes(int arr[N_Max], int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int number = arr[i];
		if (number <= 1) continue;
		bool isPrime = true;
		for (int j = 2; j <= sqrt(number); j++) {
			if (number % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (!isPrime) continue;
		counter++;
	}
	return counter;
}

int main()
{
	srand(time(0));
	int mas[N_Max];
	for (int i = 0; i < N_Max; i++)
		mas[i] = rand();
	std::cout << NumberOfPrimes(mas, N_Max) << std::endl;
}

// Cложность алгоритма:
//  в лучшем случае  - O(n)
//  в среднем случае - O(n)
//  в худшем случае  - O(n)