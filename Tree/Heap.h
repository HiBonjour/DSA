#pragma once
#include <iostream>
using namespace std;
template <class T>
class Heap {
protected:
    T* data;
    int capacity;
    int size;
    /*void percolateUp(int pos) {                       每次比较都交换，开销相对大
        while (pos > 1 && data[pos] < data[pos / 2]) {
            T temp = data[pos];
            data[pos] = data[pos / 2];
            data[pos / 2] = temp;
            pos = pos / 2;
        }
    }*/
    /*向上渗透（到确定位置后再放入元素）*/
    void percolateUp(int pos) {
        T temp = data[pos];
        int i;
        for (i = pos; i > 1 && temp < data[i / 2]; i /= 2) {
            data[i] = data[i / 2];
        }
        data[i] = temp;
    }
    /*向上渗透（到确定位置后再放入元素）*/
    void percolateDown(int pos) {
        T temp = data[pos];
        int i, child;
        for (i = pos; i * 2 <= size; i = child) {
            child = i * 2;
            if (child != size && data[child] > data[child + 1]) {
                child++;
            }
            if (temp > data[child]) {
                data[i] = data[child];
            } else {
                break;
            }
        }
        data[i] = temp;

    }
public:
    /*0号位置不使用，也可在0号放入无穷小作为哨兵*/
    Heap(int max = 20) {
        cout << "!!!!" << endl;
        size = 0;
        data = new T[max + 1];
        if (data) {
            capacity = max;
        } else {
            capacity = 0;
        }
        cout << &data << endl;
    }
    /*用数组初始化堆*/
    Heap(T a[], int size, int max = 20) {
        if (max >= size) {
            data = new T[max + 1];
            if (data) {
                capacity = max;
            } else {
                throw - 1;
            }
            if (data) {
                this->size = size;
                for (int i = 1; i <= size; i++) {
                    data[i] = a[i - 1];
                }
                for (int i = size / 2; i > 0; i--) {
                    percolateDown(i);
                }
            }
        } else {
            throw - 1;
        }
    }
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
    bool isFull() {
        return size >= capacity;
    }
    bool isEmpty() {
        return size == 0;
    }
    /*插入*/
    bool insert(T x) {
        if (!isFull()) {
            data[++size] = x;
            percolateUp(size);
            return true;
        } else {
            return false;
        }
    }
    /*移除最高优先级元素*/
    T remove() {
        if (isEmpty()) throw - 1;
        T r = data[1];
        data[1] = data[size--];
        percolateDown(1);
        return r;
    }
    /*改变某个节点的值(target:原值,value:修改后的值)*/
    bool change(T target, T value) {
        int i;
        for (i = 1; i <= size; i++) {
            if (data[i] == target) {
                break;
            }
        }
        if (i <= size && target != value) {
            data[i] = value;
            if (target < value) {
                percolateDown(i);
            } else {
                percolateUp(i);
            }
            return true;
        } else {
            return false;
        }
    }
};
