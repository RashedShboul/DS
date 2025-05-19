#pragma once
#include <cstddef>

namespace ds {

class List {
 private:
  struct listNode {
    int data;
    listNode* next;
    listNode* prev;
    listNode(int d, listNode* n = nullptr, listNode* p = nullptr)
        : data(d), next(n), prev(p) {}
  };

  listNode *head, *tail;
  size_t _size;

 public:
  List();
  ~List();
  List(const List& other);             // Copy constructor
  List& operator=(const List& other);  // Copy assignment
  void clear();
  size_t size() const noexcept;
  bool is_empty() const noexcept;
  int front() const;
  int back() const;
  void push_back(int value);
  bool pop_back();
  void push_front(int value);
  bool pop_front();
  void insert_at(int value, size_t index);
  void delete_at(size_t index);
  bool delete_val(int value);
  bool find(int value) const;
};

}  // namespace ds