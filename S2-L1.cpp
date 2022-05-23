// ������������ ������ �1 (������ �������) ������� �2 
//
// ������� ��������� ��������� � ������, ������� � ������ ������. 
// ����������� ��������� ����� ������ ���������. ���������������� ���. 
// ���������� �������� ����� ������ (�������������� ������� Timer) � �������� � ���������.
// 
// ���� � ����� ������ � ������� �� ���������. �������, ��� 0 < N <= 10000.
// 
// ���� ������������������ �� N �����. ��������� ���������� ������� �����.

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

// C�������� ���������:
//  � ������ ������  - O(n)
//  � ������� ������ - O(n)
//  � ������ ������  - O(n)