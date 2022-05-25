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
#include <chrono>
#define N_Max 1000

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

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
	Timer t;
	std::cout << NumberOfPrimes(mas, N_Max) << std::endl;
	std::cout << "Time elapsed: " << t.elapsed() << std::endl;
}

// C�������� ���������:
//  � ������ ������  - O(n)
//  � ������� ������ - O(n)
//  � ������ ������  - O(n)