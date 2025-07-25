#include "vector.h"
#include <stdexcept>

template<typename T>
Vector<T>::Vector(int capacity) {
    m_array = new T[capacity];
    m_capacity = capacity;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_array;
}

template<typename T>
T Vector<T>::at(int index) {
    if (index < 0 || index >= m_size) {
        throw std::runtime_error("index out of range");
    }

    return m_array[index];
}

template<typename T>
int Vector<T>::find(T item) {
    for (int i = 0; i < m_size; i++) {
        if (m_array[i] == item) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Vector<T>::push(T item) {
    if (m_size == m_capacity) {
        resize(m_capacity * 2);
    }

    m_array[m_size] = item;
    m_size++;
}

template<typename T>
void Vector<T>::insert(int index, T item) {
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

template<typename T>
void Vector<T>::prepend(T item) {
    insert(0, item);
}

template<typename T>
T Vector<T>::pop() {
    if (m_size == 0) {
        throw std::runtime_error("cannot pop from empty vector");
    }
    return m_array[--m_size];
}

template<typename T>
void Vector<T>::del(int index) {
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

template<typename T>
void Vector<T>::remove(T item) {
    int index = find(item);
    if (index == -1) {
        throw std::runtime_error("item not found");
    }

    del(index);
}

template<typename T>
void Vector<T>::resize(int capacity) {
    T* new_array = new T[capacity];

    for (int i = 0; i < m_size; i++) {
        new_array[i] = m_array[i];
    }

    delete[] m_array;
    m_array = new_array;
    m_capacity = capacity;
}
