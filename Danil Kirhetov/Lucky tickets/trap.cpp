#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

const long double mod = 18446744073709551616.0;

double func(int p, int k, double x) {
	return pow(sin(p * x) / sin(x), 2 * k) / M_PI;
}

int main() {
	double st = 0.000000785;
	//double st = 0.0001;
	//double st = 0.0000001;
	

	double n = 1 / st;
	int p, k;
	cin >> p >> k;
	const double width = (M_PI) / st;
	double a = -M_PI / 2, b = M_PI / 2;

	long double Integral = 0;
	
	Integral = fmod(st * (func(p, k, a) + func(p, k, b)) / 2.0, mod);
	
	int i;

	for (i = 1; i <= width - 1; i++) {
		Integral = fmod(Integral + fmod(st * func(p, k, a + st * i), mod), mod);
	}
	unsigned long long int res = round(Integral);
	cout << res << endl;
	return 0;
}