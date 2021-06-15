#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std::chrono;

int binpow0(int a, int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return a;
  else
    return a * binpow0(a, n - 1);
}

int binpow1 (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow1 (a, n-1) * a;
	else {
		int b = binpow1 (a, n/2);
		return b * b;
	}
}

int binpow2(int a, int n) {
	int result = 1;
	while (n)
		if (n & 1) {
			result *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return result;
}

int binpow3 (int a, int n) {
	int result = 1;
	while (n) {
		if (n & 1)
			result *= a;
		a *= a;
		n >>= 1;
  }
  return result;
}

void TestBinPower(int test_number, int (*func)(int, int)) {

    printf("4^15 = %d\n", func(4, 15));
    
    std::vector<double> total;  
    
    for (int i = 0; i < test_number; i++){

      auto start = steady_clock::now();
      
      for (int i = 0; i < 10'000'000; i++)
        func(4, 15);
      
      auto finish = steady_clock::now();

      auto duration = finish - start;
      double time = duration_cast<milliseconds>(duration).count();
      
      total.push_back(time);
    }
    
    auto average = 
      std::accumulate(total.begin(), total.end(), 0.) / test_number;

    double std = 0;

    for (auto i : total)
      std += (i - average) * (i - average);

    std = std::sqrt(std / (test_number - 1));

    printf("\033[1;31mTime: %.2f +- %.2f ms \033[0m\n", average, std);

}

int main() {
  
  printf("Not binary power:\n");
  TestBinPower(20, &binpow0);

  printf("First version of binary power:\n");
  TestBinPower(20, &binpow1);
  
  printf("Second version of binary power:\n");
  TestBinPower(20, &binpow2);

  printf("Third version of binary power:\n");
  TestBinPower(20, &binpow3);

}
