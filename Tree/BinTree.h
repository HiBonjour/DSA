#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class Elem>
struct BinNode {
    Elem data;
    BinNode* left;
    BinNode* right;
    int height;                      //节点高度，在AVL树时使用
    BinNode(Elem x) {
        data = x;
        left = right = nullptr;
        height = 0;                  //初始化节点高度（非必需）
    }
};
template <class Elem>
class BinTree {
protected:
    BinNode<Elem>* root;
    /*递归先序遍历并打印*/
    void rpreprint(BinNode<Elem>* node) {
        if (root == nullptr) return;    //若为空指针则返回（任何指针都应该考虑其为空的可能性）
        cout << node->data << ' ';
        if (node->left != nullptr) {    //前面已判断是否为空，此处可以不判断
            rpreprint(node->left);
        }
        if (node->right != nullptr) {   //前面已判断是否为空，此处可以不判断
            rpreprint(node->right);
        }
    }
    /*递归中序遍历并打印*/
    void rinprint(BinNode<Elem>* node) {
        if (root == nullptr) return;    //若为空指针则返回（任何指针都应该考虑其为空的可能性）
        if (node->left != nullptr) {    //前面已判断是否为空，此处可以不判断
            rinprint(node->left);
        }
        cout << node->data << ' ';
        if (node->right != nullptr) {   //前面已判断是否为空，此处可以不判断
            rinprint(node->right);
        }
    }
    /*递归后序遍历并打印*/
    void rpostprint(BinNode<Elem>* node) {
        if (root == nullptr) return;    //若为空指针则返回（任何指针都应该考虑其为空的可能性）
        if (node->left != nullptr) {    //前面已判断是否为空，此处可以不判断
            rpostprint(node->left);
        }
        if (node->right != nullptr) {   //前面已判断是否为空，此处可以不判断
            rpostprint(node->right);
        }
        cout << node->data << ' ';
    }
    /*迭代先序遍历并打印*/
    void ipreprint(BinNode<Elem>* r) {
        if (!r) return;
        stack<BinNode<Elem>*> st;
        while (!st.empty() || r) {
            if (r) {
                cout << r->data << ' ';
                st.push(r);
                r = r->left;
            }
            if (!r) {
                r = st.top()->right;
                st.pop();
            }
        }
    }
    /*迭代中序遍历并打印*/
    void iinprint(BinNode<Elem>* r) {
        if (!r) return;
        stack<BinNode<Elem>*> st;
        while (!st.empty() || r) {
            if (r) {
                st.push(r);
                r = r->left;
            }
            if (!r) {
                r = st.top();
                cout << r->data << ' ';
                r = r->right;
                st.pop();
            }
        }
    }
    /*递归查找 指定树 是否存在指定值 并返回地址*/
    BinNode<Elem>* rfind(Elem x, BinNode<Elem>* r) {//x:target; r:the root of the subtree;(未找到时返回空指针)
        if (r == nullptr) return nullptr;           //若为空指针则返回
        if (r->data == x) return r;
        BinNode<Elem>* found = rfind(x, r->left);   //临时变量，保存调用结果，减少重复调用的开销
        return found ? found : rfind(x, r->right);  //如果左子树里返回空，就返回右子树返回的结果（1：在左子树找到 2：在右子树找到 3：没找到）
    }
    /*递归先序遍历并展示*/
    void rprint(BinNode<Elem>* r, int depth) {
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        if (r) {
            cout << r->data << endl;
            rprint(r->left, depth + 1);
            rprint(r->right, depth + 1);
        } else {
            cout << "[]" << endl;
        }
    }
    /*递归释放节点(与后序遍历类似)*/
    void destruct(BinNode<Elem>* p) {
        if (!p) return;
        destruct(p->left);
        destruct(p->right);
        //cout << p->data << ' ';   打印输出被删除的节点，用于检查是否完全释放空间
        delete p;
    }
public:
    BinTree() {
        root = nullptr;
    }
    BinTree(Elem x) {
        root = new BinNode<Elem>(x);
    }
    ~BinTree() {
        destruct(root);
    }
    /*前序遍历*/
    void preprint() {
        //rpreprint(root);    //递归
        ipreprint(root);    //迭代
        cout << endl;
    }
    /*中序遍历*/
    void inprint() {
        //rinprint(root);     //递归
        iinprint(root);     //迭代
        cout << endl;
    }
    /*后序遍历*/
    void postprint() {
        rpostprint(root);
        cout << endl;
    }
    /*层序遍历*/
    void seqprint() {
        queue<BinNode<Elem>*> que;
        BinNode<Elem>* p = root;
        do {
            cout << p->data << ' ';
            if (p->left) {
                que.push(p->left);
            }
            if (p->right) {
                que.push(p->right);
            }
            p = que.front();
            que.pop();
        } while (!que.empty());
        cout << p->data << endl;
    }
    BinNode<Elem>* find(Elem x) {
        return rfind(x, root);
    }
    bool insert(Elem p, int LR, Elem x) {   //p:parent node; LR:left(0) or right(1); x:the inserted value.
        bool flag = true;
        if (root == nullptr) return false;
        BinNode<Elem>* found = rfind(p, root);
        if (!found) return false;
        if (LR == 0) {
            if (found->left == nullptr) {
                found->left = new BinNode<Elem>(x);
            } else {
                flag = false;
            }
        } else {
            if (found->right == nullptr) {
                found->right = new BinNode<Elem>(x);
            } else {
                flag = false;
            }
        }
        return flag;
    }
    void print() {
        rprint(root, 0);
    }
};

//final函数必须是虚函数，作用是防止被继承
