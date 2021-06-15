template<class T>
class ArrayList {
public:
    ArrayList();
  
    explicit ArrayList(int capacity);
  
    void PushBack(const T &item);
  
    void Insert(const T &item, int index);
  
    void RemoveAt(int index);
  
    T Get(int index) const;

private:
    void Resize();
  
    T* _array;
    int _capacity;
    int _size;
};


template<class T>
ArrayList<T>::ArrayList(const int capacity) :
        _array(nullptr),
        _capacity(capacity),
        _size(0) {
    // Ініціалізація всіх змінних класу
    _array = new T[_capacity];
}

template<class T>
ArrayList<T>::ArrayList() : ArrayList(10) {
    // Якщо ємність не задана, то викликаємо конструктор для ємності 10
}

template<typename T>
void ArrayList<T>::PushBack(const T &item) {
  // Перевіряємо чи достатньо місця у масиві.
  if (_size >= _capacity)
    Resize();

  // Додаємо наш елемент та збільшуємо розмір на 1.
  _array[_size++] = item;
}

template<typename T>
void ArrayList<T>::RemoveAt(const int index) {
  // Переміщуємо всі елементі починаючи з наданого
  // індекса до останнього на одну позицію вліво.
  for (int i = index; i < _size - 1; ++i)
    _array[i] = _array[i + 1];

  // Зменшуємо розмір масиву.
  --_size;
}

template<typename T>
void ArrayList<T>::Insert(const T &item, const int index) {
  // Перевіряємо чи достатньо місця у масиві.
  if (_size >= _capacity)
    Resize();

  // Збільшуємо розмір структури данних
  ++_size;

  // Зсуваємо всі елементи вправно після наданого індексу.
  for (int i = _size - 1; i > index; --i) {
    _array[i] = _array[i - 1];
  }

  // Всавляємо наданих елемент
  _array[index] = item;
}

template<typename T>
void ArrayList<T>::Resize() {
  // Створюємо новий масив з ємністю у два рази більше за попереднього 
  T* const newStorage = new T[_capacity *= 2];

  // Копіюємо всі елементи зі старого масиву до нового.
  for (int i = 0; i < _size; ++i) {
    newStorage[i] = _array[i];
  }

  // Замінюємо старий масив на новий та видаляємо старий.
  T* oldStorage = _array;
  _array = newStorage;
  delete[] oldStorage;
}

template<typename T>
T ArrayList<T>::Get(const int index) const {
  return _array[index];
}
