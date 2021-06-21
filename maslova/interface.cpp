#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Container {

public:
       void virtual Print() = 0;
};


class MyVector : Container {

public:

      MyVector(vector<string> some_vector) :
           my_vector(some_vector) {}


      void virtual Print() override {
            for (int i=0; i < my_vector.size(); i++){
            cout << "The element number " << i << " is " << my_vector[i] << " ";
            cout << endl;
        }
      }

private:
     vector<string> my_vector;
};



class MyMap : Container {

public:

      MyMap(map<int, string> some_map) :
           my_map(some_map) {}

      void virtual Print() override {
            for (auto& item : my_map){
            cout << "Cell number " << item.first << " corresponds to " << item.second;
            cout << endl;}
      }

private:
     map<int, string> my_map;
};


int main () {

      vector<string> vec1 = {"apple", "banana", "orange", "kiwi"};
      MyVector MyVec1(vec1);
      MyVec1.Print();

      map<int, string> map1 = {{1, "apple"}, {2, "banana"}, {3, "orange"}, {4, "kiwi"} };
      MyMap MyMap1(map1);
      MyMap1.Print();



return 0;
}












