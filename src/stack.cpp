#include "../include/ds/stack.hpp"
#include <stdexcept> // for std::runtime_error
#include <cstring>   // for std::memcpy if needed
#include <algorithm>
#include <limits> // for std::numeric_limits

namespace ds
{

    Stack::Stack(size_t cap)
    {
        if (cap <= 0)
            throw std::runtime_error("invalid capacity");
        if (cap > std::numeric_limits<size_t>::max() / 2)
            throw std::runtime_error("capacity too large");
        capacity = cap;
        topIdx = 0;
        elements = new int[cap];
    }

    Stack::~Stack() noexcept
    {
        delete[] elements;
    }

    size_t Stack::size() const noexcept
    {
        return topIdx;
    }

    bool Stack::isEmpty() const noexcept
    {
        return topIdx == 0;
        
    }

    int Stack::top() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("stack is empty");
        }
        return elements[topIdx - 1];
    }

    int Stack::pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("stack underflow");
        }
        int value = elements[topIdx - 1];
        --topIdx;
        // Only resize if we have more than minimum capacity and usage is low
        if (capacity > 32 && topIdx < capacity / 4)
        {
            resize(capacity / 2);
        }
        return value;
    }

    void Stack::push(const int value)
    {
        if (topIdx == capacity)
        {
            // Overflow protection
            if (capacity >= std::numeric_limits<size_t>::max() / 2)
            {
                throw std::runtime_error("stack capacity overflow");
            }
            resize(capacity * 2);
        }

        elements[topIdx++] = value;
    }

    void Stack::resize(size_t newCap)
    {
        int *newElements = new int[newCap];

        std::copy(elements, elements + topIdx, newElements);

        capacity = newCap;
        delete[] elements;
        elements = newElements;
    }

}