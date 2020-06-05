#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T x) {
        data = x;
        next = nullptr;
    }
};
template <class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    ~Queue() {
        Node<T>* temp;
        while (front) {
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(T x) {
        Node<T>* temp = new Node<T>(x);
        if (front == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    bool dequeue(T& x) {
        if (front == nullptr)
            return false;
        x = front->data;
        Node<T>* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return true;
    }
};
