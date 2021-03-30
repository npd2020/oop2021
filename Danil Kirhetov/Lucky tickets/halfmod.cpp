#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

//Поиск ответа с применением комбинаторики

//Для решения задачи использовалось обнаруженное мной свойство модульной арифметики
// (a + b) mod c = a mod c/2 + b mod c/2
// и 
// (a * b) mod c = a mod c/2 * b mod c/2,			если a mod c/2 + b mod c/2 > c/2
// (a * b) mod c = a mod c/2 * b mod c/2 + c/2,		если a mod c/2 + b mod c/2 > c/2

//Однако проблема состоит в том, что при умножении  а и b, где а и b < c
//произведение может быть больше с и переменная будет переполнена до вычисления остатка

unsigned long long int hm = 9223372036854775808;			//ограничение по модулю разделенное на 2


unsigned long long int Combine(int n, int l) {				//вычисление биномиального коэфициента (количество сочетаний)
	vector<unsigned long long int> c;

	for (int i = 0; i <= l + 1; i++) {
		c.push_back(0);
	}

	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, l); j > 0; j--)

			c[j] = c[j] % hm + c[j - 1] % hm;
	}
	return c[l];
}

int main() {
	int p, k;
	cin >> p >> k;
	if (k * (p - 1) + 1 > 4444) {
		cout << -1;
		return 0;
	}
	int K = 2 * k - 1;
	int n = k * (p - 1) + K;

	unsigned long long int integral = 0;
	long double Integral = 0;

	for (int i = 0; i < k; i++) {
		unsigned long long int multiply = 0;
		if ((Combine(n - (i * p), K) % hm + Combine(2 * k, i) % hm) < hm) {
			multiply = (Combine(n - (i * p), K) % hm) * (Combine(2 * k, i) % hm) % hm + hm;
		}
		else {
			multiply = (Combine(n - (i * p), K) % hm) * (Combine(2 * k, i) % hm) % hm;
		}
		integral = integral + (int)pow(-1, i) * (multiply % hm);
	}

	//Для вычисления была выведена формула, которая предоставлена в файле формула.pdf

	//Как было сказано выше, при выполнении операции умножения иногда может терятся точность,
	//однако эта версия программы самая лучшая в данный момент
	
	//Ведется работа по поиску свойств модульной арифметики, типа
	// (a * b) mod c = a mod sqrt(c) * b mod sqrt(c) + n * sqrt(c)
	//где sqrt(c) - квадратный корень из с
	//В таком случае a mod sqrt(c) и b mod sqrt(c) не будут превышать sqrt(c)
	//и при умножении их произведение не будет превышать с, при этом 
	//не будет происходить переполнение переменной
	 
	//При введении числа k (1/2 разрядности числа счастливых билетиков) 
	//время подсчета превышает 2 секунды, когда требуемое время вычисления
	//не более 500 мс

	cout << integral;

	return 0;
}