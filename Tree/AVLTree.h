#pragma once
#include <iostream>
#include "BSTree.h"
using namespace std;
template<class Elem>
class AVLTree : public BSTree<Elem> {
protected:
    int getHeight(BinNode<Elem>* node) {
        int height;
        if (!node) height = -1;
        else height = node->height;
        return height;
    }
    /*LL自旋*/
    BinNode<Elem>* LLrotate(BinNode<Elem>* r) {
        BinNode<Elem>* child = r->left;
        r->left = child->right;
        child->right = r;
        r->height = getHeight(r->left) > getHeight(r->right) ? getHeight(r->left) + 1 : getHeight(r->right) + 1;
        child->height = getHeight(child->left) > getHeight(child->right) ? getHeight(child->left) + 1 : getHeight(child->right) + 1;
        return child;
    }
    BinNode<Elem>* RRrotate(BinNode<Elem>* r) {
        BinNode<Elem>* child = r->right;
        r->right = child->left;
        child->left = r;
        r->height = getHeight(r->left) > getHeight(r->right) ? getHeight(r->left) + 1 : getHeight(r->right) + 1;
        child->height = getHeight(child->left) > getHeight(child->right) ? getHeight(child->left) + 1 : getHeight(child->right) + 1;
        return child;
    }
    BinNode<Elem>* LRrotate(BinNode<Elem>* r) {
        r->left = RRrotate(r->left);
        return LLrotate(r);
    }
    BinNode<Elem>* RLrotate(BinNode<Elem>* r) {
        r->right = LLrotate(r->right);
        return RRrotate(r);
    }
    /*递归插入并检查平衡(其基类函数为虚函数，所以此处可省略virtual关键字)*/
    BinNode<Elem>* rinsert(Elem x, BinNode<Elem>* r) {
        if (r == nullptr) {
            r = new BinNode<Elem>(x);
            if (!r) throw - 1;
        }
        else if (x < r->data) {
            r->left = rinsert(x, r->left);
            if (getHeight(r->left) - getHeight(r->right) > 1) {
                if (x < r->left->data) {
                    r = LLrotate(r);
                }
                else {
                    r = LRrotate(r);
                }
            }
        }
        else if (x > r->data) {
            r->right = rinsert(x, r->right);
            if (getHeight(r->right) - getHeight(r->left) > 1) {
                if (x < r->right->data) {
                    r = RLrotate(r);
                }
                else {
                    r = RRrotate(r);
                }
            }
        }
        else {
            throw - 2;
        }
        r->height = getHeight(r->left) > getHeight(r->right) ? getHeight(r->left) + 1 : getHeight(r->right) + 1;
        return r;
    }
public:
    AVLTree() {
        this->root = nullptr;
    }
};

//不调用成员变量的函数建议写为static，使其不依赖对象而是依赖类
