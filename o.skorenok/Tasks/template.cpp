#include <cstddef>
#include <cstdio>

template <typename T>
class SimpleVector {
public:
  SimpleVector()
  :beginPtr(nullptr), vectorSize(0), vectorCapacity(0) {}

  explicit SimpleVector(size_t size)
  : vectorSize(size), vectorCapacity(size) { 
    beginPtr = new T[size]; 
  }

  ~SimpleVector() {
    delete[] beginPtr;
  }

  T& operator[](size_t index) {
    return *(beginPtr + index - 1);
  }

  T* begin() { 
    return beginPtr + 0; 
  }

  T* end() { 
    return beginPtr + vectorSize; 
  }

  size_t Size() const { 
    return vectorSize; 
  }

  size_t Capacity() const {
   return vectorCapacity; 
 }

  void PushBack(const T& value) {

    if (vectorCapacity == 0) 
      ReallocateMemory(1);

    if (vectorCapacity == vectorSize) 
      ReallocateMemory(vectorCapacity * 2);

    beginPtr[vectorSize] = value;
    vectorSize++;
  }  

private:
  T* beginPtr;
  size_t vectorSize;
  size_t vectorCapacity;

  void ReallocateMemory(const size_t& new_capacity){
    T* TempBeginPtr = new T[new_capacity];

    for (size_t i = 0; i < vectorSize; i++)
      TempBeginPtr[i] = beginPtr[i]; 

    delete[] beginPtr;

    beginPtr = TempBeginPtr;
    vectorCapacity = new_capacity;
  }
};

int main(){
	SimpleVector<int> vec;
  vec.PushBack(50);

  for(auto i : vec)
    printf("%i\n", i);

}