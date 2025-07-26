#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @class Node
 * @brief linked list node implementation
 */
#include <stdexcept>
template<typename T>
class Node {
public:
    T key;
    Node* next;
};

/**
 * @class LinkedList
 * @brief custom linked list implementation
 */
template<typename T>
class LinkedList {
public:
    // return number of nodes in linkedlist
    int size() {
        Node<T>* curr = head;
        int size = 0;
        
        while(curr) {
            curr = curr->next;
            size++;
        }
        return size;
    }
    
    // return whether linked list is empty
    bool empty() { return head == nullptr; }
    
    // return value at ith node
    T value_at(int index) {
        if (head == nullptr) {
            throw std::runtime_error("list is empty");
        } else if (index < 0) {
            
        }
        
        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            if (!curr->next) {
                throw std::runtime_error("index out of range");
            }
            
            curr = curr->next;
        }
        return curr->key;
    }
    
    // append node to front of linked list
    void push_front(T value) {
        Node<T> new_head = new Node<T>();
        new_head.key = value;
        new_head.next = head;
        head = new_head;
        
        if (tail == nullptr) {
            tail = head;
        }
    }
    
    // remove node from front of linked list and return its value
    T pop_front() {
        if (head == nullptr) {
            throw std::runtime_error("cannot pop from empty linked list");
        }
        Node<T>* old_head = head;
        T value = old_head->key;
        head = head->next;
        delete old_head;
        
        return value;
    }
    
    // append node containing value to end of linked list
    void push_back(T value) {
        Node<T> new_tail = new Node<T>();
        new_tail.key = value;
        new_tail.next = nullptr;
        if (head == nullptr) {
            head = tail = new_tail;
        } else {
            tail.next = new_tail;
            tail = new_tail;
        }
    }
    
    // remove node from end of linked list and return its value
    T pop_back() {
        if (head == nullptr) {
            throw std::runtime_error("cannot pop from empty linked list");
        } else if (head == tail) {
            T value = head->key;
            delete head;
            head = tail = nullptr;
            return value;
        } else {
            Node<T>* curr = head;
            while (curr->next->next) {
                curr = curr->next;
            }
            
            T value = curr->next->key;
            delete curr->next;
            tail = curr;
            return value;
        }
    }
    
    // return key of first node in linked list
    T front() {
        if (head == nullptr) {
            throw std::runtime_error("cannot get front of empty linked list");
        }
        return head->key;
    }
    // return key of last node in linked list
    T back() {
        if (tail == nullptr) {
            throw std::runtime_error("cannot get back of empty linked list");
        }
        return tail->key;
    }
    
    // insert node containing value at index of linked list
    void insert(int index, T value) {
        if (index == 0) {
            return push_front(value);
        }
        
        Node<T>* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (!curr->next)
        }
    }

    
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
};

#endif // LINKEDLIST_H