#pragma once
#include <iostream>
#include "BinTree.h"
using namespace std;

template<class Elem>
class BSTree : public BinTree<Elem> {
protected:
    /*递归插入(virtual关键字使其变为动态联编，从而此文件中可以调用其在其他文件处的覆写)*/
    virtual BinNode<Elem>* rinsert(Elem x, BinNode<Elem>* r) {
        if (r == nullptr) {
            r = new BinNode<Elem>(x);
            if (!r) throw - 1;
        } else if (x < r->data) {
            r->left = rinsert(x, r->left);
        } else if (x > r->data) {
            r->right = rinsert(x, r->right);
        } else {
            throw - 2;
        }
        return r;
    }
    /*递归删除,返回删除操作后的树根（可能不变）*/
    BinNode<Elem>* remove(Elem x, BinNode<Elem>* r) {
        if (!r) throw - 1;
        if (x < r->data) {
            r->left = remove(x, r->left);
        } else if (x > r->data) {
            r->right = remove(x, r->right);
        } else {
            BinNode<Elem>* temp;
            if (r->left && r->right) {
                temp = rfindMax(r->left);
                r->data = temp->data;
                r->left = remove(temp->data, r->left);
            } else {
                temp = r;
                r = r->left ? r->left : r->right;
                delete temp;
            }
        }
        return r;
    }
    /*递归查找子树里最大的元素，并返回其节点指针(尾递归，可简单改为效率更高的迭代）*/
    BinNode<Elem>* rfindMax(BinNode<Elem>* r) {
        if (!r->right) {
            return r;
        } else {
            return rfindMax(r->right);
        }
    }
public:
    BSTree() {
        this->root = nullptr;
    }
    /*插入，返回是否成功*/
    bool insert(Elem x) {
        try {
            this->root = rinsert(x, this->root);
            return true;
        }
        catch (int e) {
            return false;
        }
    }
    /*删除，返回是否成功*/
    bool remove(Elem x) {
        try {
            this->root = remove(x, this->root);
            return true;
        }
        catch (int e) {
            return false;
        }
    }
    /*找最大值，并返回其节点指针*/
    BinNode<Elem>* findMax() {
        BinNode<Elem>* p = this->root;
        if (p) {
            while (p->right) {
                p = p->right;
            }
        }
        return p;
    }
    /*找最小值，并返回其节点指针*/
    BinNode<Elem>* findMin() {
        BinNode<Elem>* p = this->root;
        if (p) {
            while (p->left) {
                p = p->left;
            }
        }
        return p;
    }
    /*查找对应值，返回节点指针，未找到时返回空指针*/
    BinNode<Elem>* find(Elem x) {
        BinNode<Elem>* p = this->root;
        while (p && p->data != x) {
            //if (p->data == x) break;  已放入循环条件
            if (p->data > x)
                p = p->left;
            else
                p = p->right;
        }
        return p;
    }
};

//派生类使用基类保护成员，需使用this指针访问
//访问节点数据前应确保其不是空指针
