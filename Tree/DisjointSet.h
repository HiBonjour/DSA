#pragma once
#include <iostream>
#include <map>
using namespace std;
template<class T>
struct DisjointSet {
    int* parent;
    T* data;
    int capacity;
    int size;
    map<T, int> m;
    DisjointSet(int max = 20) {
        capacity = max;
        size = 0;
        parent = new int[max + 1];
        data = new T[max + 1];
    }
    ~DisjointSet() {
        delete[] parent;
        delete[] data;
    }
    bool insert(T x) {
        if (capacity > size) {
            size++;
            parent[size] = -1;
            data[size] = x;
            m[x] = size;
            return true;
        }
        else {
            return false;
        }
    }
    int find(T x) {
        typename map<T, int>::iterator it = m.find(x);
        int rt = -1;
        if (it != m.end()) {
            int i, temp;
            i = rt = it->second;
            while (parent[rt] > 0)
                rt = parent[rt];
            for (; i != rt; i = temp) {
                temp = parent[i];
                parent[i] = rt;
            }
        }
        return rt;
    }
    bool unionSet(T a, T b) {
        int ra = find(a);
        int rb = find(b);
        if (ra != -1 && rb != -1) {
            if (ra != rb) {
                if (parent[ra] <= parent[rb]) {
                    parent[ra] += parent[rb];
                    parent[rb] = ra;
                }
                else {
                    parent[rb] += parent[ra];
                    parent[ra] = rb;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    void print() {
        for (int i = 1; i <= size; i++)
            cout << i << '\t';
        cout << endl;
        for (int i = 1; i <= size; i++)
            cout << data[i] << '\t';
        cout << endl;
        for (int i = 1; i <= size; i++)
            cout << parent[i] << '\t';
        cout << endl;
    }
};
