#include "../include/ds/list.hpp"

#include <stdexcept>

namespace ds
{

  List::List()
  {
    head = tail = nullptr;
    _size = 0;
  }

  List::~List() { this->clear(); }

  void List::clear()
  {
    listNode *ptr = head;
    while (ptr != nullptr)
    {
      listNode *next = ptr->next;
      delete ptr;
      ptr = next;
    }
    head = tail = nullptr;
    _size = 0;
  }

  List::List(const List &other) : head(nullptr), tail(nullptr), _size(0)
  {
    listNode *ptr = other.head;
    while (ptr != nullptr)
    {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  List &List::operator=(const List &other)
  {
    if (this == &other)
      return *this; // self-assignment check

    this->clear();

    listNode *ptr = other.head;
    while (ptr != nullptr)
    {
      this->push_back(ptr->data);
      ptr = ptr->next;
    }

    return *this;
  }

  size_t List::size() const noexcept { return _size; }

  bool List::is_empty() const noexcept { return _size == 0; }

  int List::front() const
  {
    if (_size == 0)
      throw std::runtime_error("accessing empty list");
    return head->data;
  }

  int List::back() const
  {
    if (_size == 0)
      throw std::runtime_error("accessing empty list");
    return tail->data;
  }

  void List::push_front(int value)
  {
    listNode *nodeNew = new listNode(value, head);

    if (_size == 0)
      head = tail = nodeNew;

    else
    {
      nodeNew->next = head;
      head->prev = nodeNew;
      head = nodeNew;
    }
    ++_size;
  }

  void List::push_back(int value)
  {
    listNode *nodeNew = new listNode(value, nullptr, tail);

    if (_size == 0)
      head = tail = nodeNew;

    else
    {
      tail->next = nodeNew;
      tail = nodeNew;
    }
    ++_size;
  }

  bool List::pop_front()
  {
    if (_size == 0)
      return false;

    listNode *ptr = head;
    if (_size == 1)
      head = tail = nullptr;

    else{
      head = head->next;
    head->prev = nullptr;}
    delete ptr;
    --_size;
    return true;
  }

  bool List::pop_back()
  {
    if (_size == 0)
      return false;

    listNode *ptr = tail;
    if (_size == 1)
      head = tail = nullptr;

    else
    {
      tail = tail->prev;
      tail->next = nullptr;
    }

    delete ptr;
    --_size;
    return true;
  }

  void List::insert_at(int value, size_t idx)
  {
    if (idx > _size || idx < 0)
      throw std::runtime_error("invalid index");
    if (idx == 0)
      return push_front(value);
    if (idx == _size)
      return push_back(value);

    listNode *ptr = head;
    for (size_t i = 0; i < idx; ++i)
      ptr = ptr->next;

    listNode *nodeNew = new listNode(value);
    nodeNew->prev = ptr->prev;
    nodeNew->next = ptr;
    ptr->prev->next = nodeNew;
    ptr->prev = nodeNew;
    ++_size;
  }

  void List::delete_at(size_t idx)
  {
    if (idx < 0 || idx >= _size)
      throw std::runtime_error("invalid index");
    if (idx == 0)
      this->pop_front();
    else if (idx == _size - 1)
      this->pop_back();
    else
    {
      listNode *ptr = head;
      for (size_t i = 0; i < idx; ++i)
        ptr = ptr->next;

      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      delete ptr;
      --_size;
    }
  }

  bool List::delete_val(int value)
  {
    if (_size == 0)
      return false;

    listNode *ptr = head;
    while (ptr != nullptr && ptr->data != value)
    {
      ptr = ptr->next;
    }
    if (ptr && ptr->data == value)
    {
      if (ptr == head)
        this->pop_front();
      else if (ptr == tail)
        this->pop_back();
      else
      {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        --_size;
      }
      return true;
    }
    else
      return false;
  }

  bool List::find(int value) const
  {
    if (_size == 0)
      return false;
    listNode *ptr = head;
    while (ptr != nullptr)
    {
      if (ptr->data == value)
        return true;
      ptr = ptr->next;
    }
    return false;
  }

} // namespace ds