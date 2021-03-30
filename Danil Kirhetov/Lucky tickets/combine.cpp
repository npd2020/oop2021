#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

//ѕоиск ответа с применением комбинаторики

//ƒл€ решени€ задачи использовались свойства модульной арифметики
// (a + b) mod c = (a mod c + b mod c) mod c
// (a * b) mod c = (a mod c * b mod c) mod c
//ќднако проблема состоит в том, что при умножении и при суммировании а и b, где а и b < c
//произведение и сумма могут быть больше с и переменна€ будет переполнена до вычислени€ остатка


long double mod = 18446744073709551616.0;					//ограничение по модулю


long double Combine(int n, int l) {							//вычисление биномиальных коэфициентов (сочетаний)
	vector<long double> C;

	for (int i = 0; i <= l+1; i++) {
		C.push_back(0);
	}

	C[0] = 1; 
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, l); j > 0; j--)
			C[j] = fmodl(fmodl(C[j], mod) + fmodl(C[j - 1], mod), mod);
	}
	return C[l];
}

int main() {
	
	int p, k;
	cin >> p >> k;
	
	int K = 2 * k - 1;
	int n = k * (p - 1) + K;

	long double Integral = 0;

	for (int i = 0; i < k; i++) {
		Integral = fmodl(Integral + pow(-1, i) * fmodl(fmodl(Combine(n - (i * p), K), mod) * fmodl(Combine(2 * k, i), mod), mod), mod);
	}

	//ƒл€ вычислени€ была выведена формула, котора€ предоставлена в файле формула.pdf

	// ак было сказано выше, в данной програме страдает точность ответа
	//ѕри введении числа k (1/2 разр€дности числа счастливых билетиков) 
	//врем€ подсчета превышает 2 секунды, когда требуемое врем€ вычислени€
    //не более 500 мс

	cout << setprecision(45) << Integral << endl;

	return 0;
}