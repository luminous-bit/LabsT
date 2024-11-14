#include <cstring>
#include <iostream>
#include <unordered_set>

using namespace std;

template <typename T>
class Element {
 public:
  T data;
  Element* next;

  Element(T data) : data(data), next(nullptr) {}
};

template <typename T>
class OneList {
 public:
  class Iterator {
   private:
    Element<T>* current;

   public:
    Iterator(Element<T>* element) : current(element) {}

    T& operator*() { return current->data; }

    Iterator operator++() {
      if (current->next != nullptr) {
        current = current->next;
      }
      return *this;
    }

    Iterator operator--() {
      if (current != head) {
        Element<T>* temp = head;
        while (temp->next != current) {
          temp = temp->next;
        }
        current = temp;
      }
      return *this;
    }

    bool operator==(const Iterator& other) const {
      return current == other.current;
    }

    bool operator!=(const Iterator& other) const {
      return current != other.current;
    }
  };

  Element<T>* head;
  
  OneList() : head(nullptr) {}

  bool empty() const { return head == nullptr; }

  // Добавление элемента в начало списка
  void push_front(const T& value) {
    Element<T>* newElement = new Element<T>(value);
    newElement->next = head;
    head = newElement;
  }

  // Добавление элемента в конец списка
  void push_back(const T& value) {
    Element<T>* newElement = new Element<T>(value);
    if (head == nullptr) {
      head = newElement;
      return;
    }
    Element<T>* current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newElement;
  }

  // Удаление элемента из начала списка
  void pop_front() {
    if (head == nullptr) {
      return;
    }
    Element<T>* temp = head;
    head = head->next;
    delete temp;
  }

  // Удаление элемента из конца списка
  void pop_back() {
    if (head == nullptr) {
      return;
    }
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Element<T>* current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
  }

  Element<T>& back() {
    Element<T>* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    return *temp;
  }

   Element<T>* front() {
        return head;
    }

  // void insert(Iterator pos, T value) {
  // Element<T>* newElement = new Element<T>(value);
  // newElement->next = pos.current->next;
  // pos.current->next = newElement;
  //}

  void insert(char data, int position) {
    Element<T>* newElement = new Element(data);
    if (position == 0) {
      newElement->next = head;
      head = newElement;
      return;
    }
    Element<T>* current = head;
    for (int i = 0; i < position - 1; ++i) {
      if (!current) return;
      current = current->next;
    }
    newElement->next = current->next;
    current->next = newElement;
  }

  void remove(T value) {
    if (head == nullptr) return;

    // Удаление элементов из головы списка
    while (head != nullptr && head->data == value) {
      Element<T>* temp = head;
      head = head->next;
      delete temp;
    }

    // Удаление элементов из остальной части списка
    Element<T>* current = head;
    while (current->next != nullptr) {
      if (current->next->data == value) {
        Element<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
      } else {
        current = current->next;
      }
    }
  }

  //string toString() const {
    //string result;
    //Element<T>* current = head;
    //while (current) {
      //result += current->data;
      //current = current->next;
    //}
    //return result;
  //}

  int size() const {
    int count = 0;
    Element<T>* temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    return count;
  }      

  void print() const {
    Element<T>* temp = head;
    while (temp != nullptr) {
      cout << temp->data;
      temp = temp->next;
    }
    cout << endl;
  }

  // Очистка списка
  ~OneList() {
    Element<T>* current = head;
    while (current != nullptr) {
      Element<T>* next = current->next;
      delete current;
      current = next;
    }
  }
};

template <typename T>
void removeDuplicatesAndReplace(Element<T>* head) {
    if (!head) return;

    unordered_set<char> seen;
    Element<T>* current = head;
    Element<T>* prev = nullptr;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            Element<T>* next = current->next;
            int count = 0;
            
            // Проверяем, сколько раз символ повторяется
            while (current != nullptr && current->data == prev->data) {
                count++;
                current = current->next;
            }
            
            // Если символ повторяется менее 4 раз, удаляем его
            if (count < 3) {
                prev->next = current;
            } else {
                // Заменяем на ###
                prev->data = '#';
                prev->next = new Element('#');
                prev->next->next = new Element('#');
                prev->next->next->next = current;
            }
        } else {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

template <typename T>
void printList(Element<T>* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
  OneList<char> charList;
  char str[100];
  cin >> str;
  int n;
  n = strlen(str);
  for (int i = 0; i < n; i++) {
    charList.push_back(str[i]);
  }
  removeDuplicatesAndReplace(charList.front());
  charList.print();
}
