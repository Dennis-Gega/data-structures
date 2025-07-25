#ifndef VECTOR_H
#define VECTOR_H

/**
 * @class Vector
 * #brief Dynamic array implementation
 */
template <typename T>
class Vector {
public:
    Vector(int capacity);
    ~Vector();
    
    // return number of items in array
    int size() { return m_size; }
    // return maximum capacity of array
    int capacity() { return m_capacity; }
    // return whether array is empty
    bool is_empty() { return m_size == 0 ? true : false; }
    // return item located at intex
    T at(int index);
    // append item to end of array
    void push(T item);
    // insert item in specific index of array
    void insert(int index, T item);
    // insert item at beginning of array
    void prepend(T item);
    // return last item in array and delete it
    T pop();
    // delete item at index
    void del(int index);
    // remove item from array
    void remove(T item);
    // return index of the first appearance of item, or -1 if item is not in array
    int find(T item);

private:
    // number of items in array
    int m_size = 0;
    // maximum capacity of array
    int m_capacity = 16;
    // raw array
    T* m_array;
    
    // resize array
    void resize(int capacity);
};

#endif // VECTOR_H
