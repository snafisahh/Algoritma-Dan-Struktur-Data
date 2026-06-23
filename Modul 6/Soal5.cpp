#include <iostream>
#include <string>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node,
              const RedBlackTree::Node* nil)
{
    if (node == nil) return;

    cout << node->key << " ";
    preorder(node->left, nil);
    preorder(node->right, nil);
}

void inorder(const RedBlackTree::Node* node,
             const RedBlackTree::Node* nil)
{
    if (node == nil) return;

    inorder(node->left, nil);
    cout << node->key << " ";
    inorder(node->right, nil);
}

void postorder(const RedBlackTree::Node* node,
               const RedBlackTree::Node* nil)
{
    if (node == nil) return;

    postorder(node->left, nil);
    postorder(node->right, nil);
    cout << node->key << " ";
}

int main() {
    int N;
    cin >> N;

    RedBlackTree tree;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (!tree.contains(x))
            tree.insert(x);
    }

    int Q;
    cin >> Q;

    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
        return 0;
    }

     while (Q--) {
        string traversal;
        cin >> traversal;

        if (traversal == "PREORDER") {
            cout << "[Preorder] : ";
            preorder(tree.root(), tree.nil());
            cout << endl;
        } else if (traversal == "INORDER") {
            cout << "[Inorder] : ";
            inorder(tree.root(), tree.nil());
            cout << endl;
        } else if (traversal == "POSTORDER") {
            cout << "[Postorder] : ";
            postorder(tree.root(), tree.nil());
            cout << endl;
        } else if (traversal == "ALL") {
            cout << "[Preorder] : ";
            preorder(tree.root(), tree.nil());
            cout << endl;

            cout << "[Inorder] : ";
            inorder(tree.root(), tree.nil());
            cout << endl;

            cout << "[Postorder] : ";
            postorder(tree.root(), tree.nil());
            cout << endl;
        }
    }

    return 0;
}