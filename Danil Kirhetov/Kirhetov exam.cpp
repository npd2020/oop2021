#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<typeinfo>
#include<algorithm>
#include<string>

//Екзаменаційна робота Кіргетова Данііла. 
//			Білет №1

using namespace std;

int main() {
	//ключове слово auto

	auto charact = 'c';
	auto integ = 152;
	auto floating = 5.2;
	auto str = "String";
	auto intlong = 3000000000;
	
	cout << typeid(charact).name() << endl;
	cout << typeid(integ).name() << endl;
	cout << typeid(floating).name() << endl;
	cout << typeid(str).name() << endl;
	cout << typeid(intlong).name() << endl << endl;

	//лямбда-вираз
	vector<int> vec(3, 2);
	for_each(vec.begin(), vec.end(), [](int x) {cout << x << endl; });
	cout << endl;
	// інструкція for each

	vector<int> example(5);
	for (int i = 0; i < example.size(); i++) {
		example[i] = i;
	}

	for (auto item : example) {
		cout << item << endl;
	}cout << endl;
	
	//список-масив

	example.push_back(5);
	example.push_back(6);
	for (auto item : example) {
		cout << item << endl;
	}cout << endl;
	example.pop_back();
	for (auto item : example) {
		cout << item << endl;
	}cout << endl;

	example.insert(example.begin() + 4, vec.begin(), vec.end());
	for (auto item : example) {
		cout << item << endl;
	}cout << endl;

	//зв'язаний список
	
	list<int> exmpl;
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0) {
			exmpl.push_back(i);
		}
		else {
			exmpl.push_front(i);					//додаємо всі парні числа в кінець, а непарні в початок
		}
	}
	for (auto item : exmpl) {
		cout << item << endl;
	}cout << endl;

	exmpl.push_back(17);
	exmpl.push_front(22);
	for (auto item : exmpl) {
		cout << item << endl;
	}cout << endl;

	exmpl.pop_back();
	exmpl.pop_front();
	exmpl.insert(++(++exmpl.begin()), 2, 0);

	for (auto item : exmpl) {
		cout << item << endl;
	}cout << endl;
	return 0;
}
