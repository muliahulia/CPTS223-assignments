#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
using namespace std;


/* ----------------------------------------------------------------------------
---- Below is declaration of BST class, referring to textbook, Figure 4.16 ----
---------------------------------------------------------------------------- */

template <typename Comparable>
class BST
{
public:
    BST();
    ~BST();
    void makeEmpty();

    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;
    int treeHeight() const;
    void printInOrder() const;
    void printLevels() const;
    void printMaxPath() const;

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt): element(theElement), left(lt), right(rt) {}
        BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt): element(move(theElement)), left(lt), right(rt) {}
    };

    BinaryNode *root;

    BinaryNode * findMin( BinaryNode * t ) const;
    BinaryNode * findMax( BinaryNode * t ) const;
    void makeEmpty( BinaryNode * & t );
    BinaryNode * contains(BinaryNode *node, const Comparable & x) const;
    void insert(const Comparable & x, BinaryNode *& node);
    void remove(BinaryNode *& node, const Comparable & x);
    int treeSize(BinaryNode *node) const;
    int treeHeight(BinaryNode *node) const;
    void printInOrder(BinaryNode *node) const;




};


/* --------------------------------------------------------------
---- Below is implementation of public and private functions ----
-------------------------------------------------------------- */

// constructor
template<typename Comparable>
BST<Comparable>::BST() : root(nullptr) {}

// destructor, refer to textbook, Figure 4.27
template<typename Comparable>
BST<Comparable>::~BST() {
    makeEmpty();
}

// public makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: refer to textbook, Figure 4.27
template <typename Comparable>
void BST<Comparable>::makeEmpty(BinaryNode *& t) {
    if ( t != nullptr ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

// public findMin
template <typename Comparable>
const Comparable & BST<Comparable>::findMin() const {
    if (root == nullptr) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}

// private findMin: refer to textbook, Figure 4.20
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMin(BinaryNode * t) const {
    if ( t == nullptr ) {
        return nullptr;
    } else if (t->left == nullptr) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax
template <typename Comparable>
const Comparable & BST<Comparable>::findMax() const {
    if (root == nullptr) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element;
}

// private findMax: refer to textbook, Figure 4.21
template <typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::findMax(BinaryNode * t) const {
    if ( t == nullptr ) {
        return nullptr;
    } else if (t->right == nullptr) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// public contains: refer to textbook, Figure 4.17, Line 4 - 7
template<typename Comparable>
bool BST<Comparable>::contains(const Comparable &x ) const {
    return contains(root, x);
}

template<typename Comparable>
typename BST<Comparable>::BinaryNode* BST<Comparable>::contains(BinaryNode *node, const Comparable & x) const {
    if (node == nullptr) {
        return nullptr;
    }
    if (x < node->element) {
        return contains(node->left, x);
    } else if (x > node->element) {
        return contains(node->right, x);
    } else {
        return node;
    }
}

// public insert: refer to textbook, Figure 4.17, Line 12 - 15
template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x) {
    insert(x, root);
}

template<typename Comparable>
void BST<Comparable>::insert(const Comparable & x, BinaryNode *& node) {
    if (node == nullptr) {
        node = new BinaryNode(x, nullptr, nullptr);
    } else if (x < node->element) {
        insert(x, node->left);
    } else if (x > node->element) {
        insert(x, node->right);
    }
}

// public remove: refer to textbook, Figure 4.17, Line 20 - 23
template<typename Comparable>
void BST<Comparable>::remove( const Comparable & x ) {
    remove(root, x);
}

template<typename Comparable>
void BST<Comparable>::remove(BinaryNode *& node, const Comparable & x) {
    if (node == nullptr) {
        return;
    }
    if (x < node->element) {
        remove(node->left, x);
    } else if (x > node->element) {
        remove(node->right, x);
    } else if (node->left != nullptr && node->right != nullptr) {
        node->element = findMin(node->right)->element;
        remove(node->right, node->element);
    } else {
        BinaryNode *oldNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        delete oldNode;
    }
}

// public treeSize
template <typename Comparable>
int BST<Comparable>::treeSize() const {
    return treeSize(root);
}

template <typename Comparable>
int BST<Comparable>::treeSize(BinaryNode *node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + treeSize(node->left) + treeSize(node->right);
}

// public treeHeight
template <typename Comparable>
int BST<Comparable>::treeHeight() const {
    return treeHeight(root);
}

template <typename Comparable>
int BST<Comparable>::treeHeight(BinaryNode *node) const {
    if (node == nullptr) {
        return -1;
    }
    return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

// public printInOrder: refer to textbook, Figure 4.60
template<typename Comparable>
void BST<Comparable>::printInOrder() const {
    printInOrder(root);
}

template<typename Comparable>
void BST<Comparable>::printInOrder(BinaryNode *node) const {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->element << " ->";
        printInOrder(node->right);
    }
}

// public printLevels
template <typename Comparable>
void BST<Comparable>::printLevels() const {
    if (root == nullptr) {
        return;
    }
    std::queue<BinaryNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinaryNode* current = q.front();
        q.pop();

        std::cout << current->element << " ->";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    std::cout << std::endl;
}

// public printMaxPath
template <typename Comparable>
void BST<Comparable>::printMaxPath() const {
    if (root == nullptr) {
        return;
    }
    BinaryNode* current = root;
    while (current != nullptr) {
        std::cout << current->element << " ->";
        if (current->right != nullptr) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    std::cout << std::endl;
}

#endif
