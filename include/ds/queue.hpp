#pragma once
#include <cstddef>

namespace ds {

    /**
     * @brief A circular buffer implementation of a queue
     * 
     * This queue implementation uses a circular buffer to achieve O(1) operations
     * for enqueue, dequeue, and front. The buffer automatically resizes when
     * it becomes full or when it's only 1/4 full (to save memory).
     * 
     * Exception guarantees:
     * - Strong exception guarantee for enqueue
     * - No-throw guarantee for size(), isEmpty(), isFull(), capacity(), clear()
     * - Basic exception guarantee for dequeue and front
     */
    class Queue
    {
    public:
        static constexpr size_t MIN_CAPACITY = 32;
        /**
         * @brief Construct a new queue object
         * @param cap Initial capacity of the queue (default: MIN_CAPACITY)
         * @throw std::runtime_error if capacity is 0 or too large
         */
        Queue(size_t cap = MIN_CAPACITY);

        /**
         * @brief Destroy the queue object and free allocated memory
         */
        ~Queue();

        /**
         * @brief Get the current number of elements in the queue
         * @return size_t Number of elements
         */
        size_t size() const noexcept; 

        /**
         * @brief Check if the queue is empty
         * @return true if queue is empty, false otherwise
         */
        bool isEmpty() const noexcept; 

        /**
         * @brief Check if the queue is full
         * @return true if queue is full, false otherwise
         */
        bool isFull() const noexcept; 

        /**
         * @brief Get the current capacity of the queue
         * @return size_t Current capacity
         */
        size_t capacity() const noexcept;

        /**
         * @brief Clear all elements from the queue
         * Resets the queue to its initial state without deallocating memory
         */
        void clear() noexcept;

        /**
         * @brief Add an element to the back of the queue
         * @param value Element to add
         * @throw std::runtime_error if capacity would overflow
         */
        void enqueue(int value); 

        /**
         * @brief Get the element at the front of the queue without removing it
         * @return int Front element
         * @throw std::runtime_error if queue is empty
         */
        int front() const; 

        /**
         * @brief Remove and return the element at the front of the queue
         * @return int Front element
         * @throw std::runtime_error if queue is empty
         */
        int dequeue(); 

    private:
        size_t head, tail, _size, _capacity; 
        int *elements;
        void resize(size_t newCap);
    };
    
    
    

}