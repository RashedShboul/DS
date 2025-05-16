#pragma once
#include <cstddef>

namespace ds
{

    class Stack
    {
        size_t capacity;
        size_t topIdx;
        int *elements;

        void resize(size_t newCap);

    public:
        Stack(size_t cap = 32);
        ~Stack() noexcept;

        size_t size() const noexcept;
        void push(const int value);
        int pop();
        int top() const;
        bool isEmpty() const noexcept;
    };

}