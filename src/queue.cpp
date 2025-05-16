#include "../include/ds/queue.hpp"
#include <stdexcept> // for std::runtime_error
#include <cstring>   // for std::memcpy if needed
#include <algorithm>
#include <limits> // for std::numeric_limits

namespace ds
{
    Queue::Queue(size_t cap)
    {
        if (cap <= 0)
            throw std::runtime_error("invalid capacity");
        if (cap > std::numeric_limits<size_t>::max() / 2)
            throw std::runtime_error("capacity too large");
        _capacity = cap;
        head = 0;
        tail = 0;
        _size = 0;
        elements = new int[cap];
    }
    Queue::~Queue()
    {
        delete[] elements;
    }

    size_t Queue::size() const noexcept
    {
        return _size;
    }
    bool Queue::isEmpty() const noexcept
    {
        return _size == 0;
    }
    bool Queue::isFull() const noexcept
    {
        return _size == _capacity;
    }

    size_t Queue::capacity() const noexcept
    {
        return _capacity;
    }

    void Queue::clear() noexcept
    {
        head = tail = _size = 0;
    }

    void Queue::enqueue(int value)
    {
        if (_size == _capacity)
        {
            // Overflow protection
            if (_capacity >= std::numeric_limits<size_t>::max() / 2)
            {
                throw std::runtime_error("queue capacity overflow");
            }
            resize(_capacity * 2);
        }
        elements[tail] = value;
        tail = (tail + 1) % _capacity;
        ++_size;
    }

    int Queue::front() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("empty queue");
        }
        return elements[head];
    }

    int Queue::dequeue()
    {
        if (isEmpty())
        {
            throw std::runtime_error("queue underflow");
        }
        int value = elements[head];
        head = (head + 1) % _capacity;
        --_size;
        if (_capacity > MIN_CAPACITY && _size < _capacity / 4)
        {
            resize(_capacity / 2);
        }
        return value;
    }

    void Queue::resize(size_t newCap)
    {
        int *newElements = new int[newCap];
        for (size_t i = 0; i < _size; ++i)
        {
            newElements[i] = elements[(head + i) % _capacity];
        }
        delete[] elements;
        elements = newElements;
        _capacity = newCap;
        head = 0;
        tail = _size;
    }
}
