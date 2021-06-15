template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };

  ~LinkedList();

  void PushFront(const T& value);

  void InsertAfter(Node* node, const T& value);

  void RemoveAfter(Node* node);

  void PopFront();

  Node* GetHead() { 
    return head; 
  }

  const Node* GetHead() const { 
    return head; 
  }

private:
  Node* head = nullptr;
};

template <typename T>
LinkedList::~LinkedList() {
  // Прибираємо перший елемент поки не дійдемо до
  // нульового вказівника.
  while(head != nullptr) {
    PopFront();
}

template <typename T>
LinkedList::PushFront(const T& value) {
  // Створюємо новий вузол який буде мати в собі вказівник на старий,
  // та замінюємо старий на новий.
  Node* nd = new Node{value, head};
  head = nd;
}

template <typename T>
LinkedList::InsertAfter(Node* node, const T& value) {
  // Якщо вузол нульовий додаємо перший елемент,
  // викликаємо метод PushFront.
  if (node == nullptr)
    PushFront(value);
  else {
    // Якщо не пустий, то створюємо новий вузол,
    // та вставляємо його після наданого вузла.
    Node* nd = new Node{value, nullptr};
    nd->next = node->next;
    node->next = nd;
  }
}

template <typename T>
LinkedList::RemoveAfter(Node* node){
  // Якщо вузол це нульовий вказівник, видаляємо перший елемент.
  if (node == nullptr) 
    PopFront();
  // Якщо вказівник на наступний вузол - не нульовий,
  // видаляємо наступний елемент, та замінюємо вказівник. 
  else if (node->next != nullptr) {
    auto temp = node->next;
    node->next = (node->next)->next;
    delete temp;
  }
}

template <typename T>
LinkedList::PopFront() {
  // Якщо head нульовий, то нічого не робимо.
  if (head == nullptr) 
    return;
  // В інших випадках, видаляємо перший елемент
  // та робимо першим елементом елемент що знаходиться попереду.
  auto old_head = head;
  head = head->next;
  delete old_head; 
}
