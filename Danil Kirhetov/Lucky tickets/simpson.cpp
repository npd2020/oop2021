#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

//Поиск ответа методом численного интегрирования
//Метод Симпсона

const long double mod = 18446744073709551616.0;			//ответ должен вычислятся как остаток от деления на это число

double func(int p, int k, double x) {
	return pow(sin(p * x) / sin(x), 2 * k) / M_PI;		//подынтегральное выражение
}

int main() {
	double st = 0.000000785;							//количество разбиений интеграла

	double n = 1 / st;
	int p, k;
	cin >> p >> k;
	const double width = (M_PI) / st;
	double a = -M_PI / 2, b = M_PI / 2;					//пределы интегрирования

	long double Integral = 0;

	Integral = fmod(st * (func(p, k, a) + func(p, k, b)) / 6.0, mod);
	int i, j;

	for (i = 1; i <= width; i++) {
		Integral = fmod(Integral + fmod(4.0 / 6.0 * st * func(p, k, a + st * (i - 0.5)), mod), mod);
	}

	for (j = 1; j <= width - 1; j++) {
		Integral = fmod(Integral + fmod(2.0 / 6.0 * st * func(p, k, a + st * j), mod), mod);
	}

	//используется свойство модульной арифметики
	// (a + b) mod c = (a mod c + b mod c) mod c

	unsigned long long int res = round(Integral);
	cout << res << endl;
	return 0;
}