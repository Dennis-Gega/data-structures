#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

/**
 * @class Vector
 * @brief Dynamic array implementation
 */
template <typename T>
class Vector {
public:
    Vector(int capacity) {
        m_array = new T[capacity];
        m_capacity = capacity;
    }
    
    ~Vector() {
        delete[] m_array;
    }
    
    // return number of items in array
    int size() { return m_size; }
    // return maximum capacity of array
    int capacity() { return m_capacity; }
    // return whether array is empty
    bool is_empty() { return m_size == 0 ? true : false; }
    
    // return item located at index
    T at(int index) {
        if (index < 0 || index >= m_size) {
            throw std::runtime_error("index out of range");
        }
        return m_array[index];
    }
    
    // return index of the first appearance of item, or -1 if item is not in array
    int find(T item) {
        for (int i = 0; i < m_size; i++) {
            if (m_array[i] == item) {
                return i;
            }
        }
        return -1;
    }
    
    // append item to end of array
    void push(T item) {
        if (m_size == m_capacity) {
            resize(m_capacity * 2);
        }
        m_array[m_size] = item;
        m_size++;
    }
    
    // insert item in specific index of array
    void insert(int index, T item) {
        if (index < 0 || index >= m_size) {
            throw std::runtime_error("index out of range");
        } else if (m_size == m_capacity) {
            resize(m_capacity * 2);
        }
        
        for (int i = m_size; i > index; i--) {
            m_array[i] = m_array[i - 1];
        }
        
        m_array[index] = item;
        m_size++;
    }
    
    // insert item at beginning of array
    void prepend(T item) {
        insert(0, item);
    }
    
    // return last item in array and delete it
    T pop() {
        if (m_size == 0) {
            throw std::runtime_error("cannot pop from empty vector");
        }
        return m_array[--m_size];
    }
    
    // delete item at index
    void del(int index) {
        if (index < 0 || index >= m_size) {
            throw std::runtime_error("index out of range");
        } else if (m_size <= m_capacity / 4) {
            resize(m_capacity / 2);
        }
        
        for (int i = index; i < m_size - 1; i++) {
            m_array[i] = m_array[i + 1];
        }
        m_size--;
    }
    
    // remove item from array
    void remove(T item) {
        int index = find(item);
        if (index == -1) {
            throw std::runtime_error("item not found");
        }
        del(index);
    }

private:
    // number of items in array
    int m_size = 0;
    // maximum capacity of array
    int m_capacity = 16;
    // raw array
    T* m_array;
    
    // resize array
    void resize(int capacity) {
        T* new_array = new T[capacity];
        
        for (int i = 0; i < m_size; i++) {
            new_array[i] = m_array[i];
        }
        
        delete[] m_array;
        m_array = new_array;
        m_capacity = capacity;
    }
};

#endif // VECTOR_H
