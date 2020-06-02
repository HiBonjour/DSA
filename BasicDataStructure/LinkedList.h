#pragma once
#include <iostream>
using namespace std;
template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T x) {
        data = x;
        next = nullptr;
    }
};
template <class T>
class LList {
protected:
    Node<T>* head;
    Node<T>* at(int num) {
        Node<T>* p = head;
        for (int i = 0; i < num; i++) {
            if (!p) break;
            p = p->next;
        }
        return p;
    }
public:
    LList() {
        head = nullptr;
    }
    ~LList() {
        Node<T>* p;
        if (head) {
            for (p = head->next; p != nullptr; p = p->next) {
                delete head;
                head = p;
            }
            delete head;
        }
    }
    /*找到n号节点并返回指针*/
    int getLength() {
        int count = 0;
        Node<T>* p = head;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }
    void print() {
        Node<T>* p = head;
        while (p) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }
    bool insert(int pos, T data) {
        Node<T>* p = new Node<T>(data);
        bool flag = true;
        if (pos == 0) {
            p->next = head;
            head = p;
        } else if (pos < 0) {
            flag = false;
        } else {
            Node<T>* temp = at(pos - 1);
            if (!temp) flag = false;
            p->next = temp->next;
            temp->next = p;
        }
        return flag;
    }
    /*删除节点（不返回删除节点的数据）*/
    bool del(int pos) {
        int flag = true;
        if (pos < 0) {
            flag = false;
        } else if (pos == 0) {
            if (!head) {
                flag = false;
            } else {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node<T>* temp = at(pos - 1);
            Node<T>* target = temp->next;
            if (!target) {
                flag = false;
            } else {
                temp->next = target->next;
                delete target;
            }
        }
        return flag;
    }
    /*重载删除节点（返回删除节点的数据）*/
    bool del(int pos, T& x) {
        int flag = true;
        if (pos < 0) {
            flag = false;
        } else if (pos == 0) {
            if (!head) {
                flag = false;
            } else {
                x = head->data;
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node<T>* temp = at(pos - 1);
            Node<T>* target = temp->next;
            if (!target) {
                flag = false;
            } else {
                x = target->data;
                temp->next = target->next;
                delete target;
            }
        }
        return flag;
    }
    T operator[] (int n) {
        return at(n)->data; //若下标有误，此处会抛出异常
    }
};
