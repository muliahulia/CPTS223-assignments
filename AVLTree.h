
#include <iostream>
#include <limits>
#include <vector>
using namespace std;


template <typename Comparable>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    void makeEmpty();
    const Comparable & findMin() const;
    const Comparable & findMax() const;

    bool contains(const Comparable & x) const;
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    int treeSize() const;
    int computeHeight() const;
    int readRootHeight() const;
    bool isBalanced() const;
    bool isBST() const;

    double averageDepth() const;
    void removeByRank(int rank);

    // the next line follows textbook Figure 4.42, Line 19
    static const int ALLOWED_IMBALANCE = 1;
private:
    struct AVLNode  // refer to textbook, Figure 4.40
    {
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt ): element(theElement), left(lt), right(rt) {}
        AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt ): element(move(theElement)), left(lt), right(rt) {}
    };

    AVLNode *root;

    AVLNode * findMin( AVLNode * t ) const;
    AVLNode * findMax( AVLNode * t ) const;
 
    bool contains(const Comparable & x, AVLNode * t) const;
    void insert(const Comparable & x, AVLNode * & t);
    void remove(const Comparable & x, AVLNode * & t);
    bool isBalanced(AVLNode * t) const;
    bool isBST(AVLNode * t, const Comparable * min, const Comparable * max) const;
    int treeSize(AVLNode * t) const;
    int computeHeight(AVLNode * t) const;
    void averageDepth(AVLNode * t, int depth, int & totalDepth, int & nodeCount) const;
    void removeByRank(AVLNode * & t, int rank);


    void makeEmpty( AVLNode * & t );

    void balance(AVLNode * & t);
    void rotateWithLeftChild( AVLNode * & t );
    void rotateWithRightChild( AVLNode * & t );
    void doubleWithLeftChild( AVLNode * & t);
    void doubleWithRightChild( AVLNode * & t);

    int height(AVLNode * t) const {
        return t == nullptr ? -1 : t->height;
    }
};

// constructor
template <class Comparable>
AVLTree<Comparable>::AVLTree() : root(NULL) {}

// destructor
template <class Comparable>
AVLTree<Comparable>::~AVLTree()
{
    makeEmpty();
}

// public makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

// private recursive makeEmpty: follow the makeEmpty in BST, referring to textbook, Figure 4.27
template <typename Comparable>
void AVLTree<Comparable>::makeEmpty(AVLNode * & t) {
    if ( t != NULL ) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
}

// public findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMin(root)->element;
}

// private findMin: follow the findMin in BST, referring to textbook, Figure 4.20
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMin(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    } else {
        return findMin(t->left);
    }
}

// public findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMax() const {
    if (root == NULL) {
        throw underflow_error("Tree is empty");
    }
    return findMax(root)->element;
}

// private findMax: follow the findMax in BST, referring to textbook, Figure 4.21
template <typename Comparable>
typename AVLTree<Comparable>::AVLNode* AVLTree<Comparable>::findMax(AVLNode * t) const {
    if ( t == NULL ) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    } else {
        return findMax(t->right);
    }
}

// start our implementation:
// public contains: follow the contains in BST, referring to textbook, Figure 4.17 and Figure 4.18
template<typename Comparable>
bool AVLTree<Comparable>::contains( const Comparable & x ) const {
    return contains(x, root);
}

template<typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable & x, AVLNode * t) const {

    if (t == nullptr){
        return false;
    }
    else if(x <t->element){
        return contains(x, t->left);
    }
    else if(x > t->element){
        return contains(x, t->right);
    }
    else{
        return true;
    }
}

// public insert: following BST, referring to textbook, Figure 4.17 and Figure 4.23
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x) {

    insert(x, root);
    
}
template<typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & x, AVLNode * & t) {
    if (t == nullptr) {
        t = new AVLNode(x, nullptr, nullptr); 
    } else if (x < t->element) {
        insert(x, t->left); 
    } else if (x > t->element) {
        insert(x, t->right); 
    }

    balance(t); 
}
// public remove: refer to textbook, Figure 4.17 and Figure 4.26
template<typename Comparable>
void AVLTree<Comparable>::remove( const Comparable & x ) {
    remove(x,root);
}

template<typename Comparable>
void AVLTree<Comparable>::remove(const Comparable & x, AVLNode * & t) {
    if (t == nullptr) return;
    
    if (x < t->element) {
        remove(x, t->left); 
    } else if (x > t->element) {
        remove(x, t->right);
    } else if (t->left != nullptr && t->right != nullptr) { 
        t->element = findMin(t->right)->element;
        remove(t->element, t->right); 
    } else {
        AVLNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }

    balance(t); // Balance the tree
}

// private balance: refer to textbook, Figure 4.42, Line 21 - 40
// assume t is the node that violates the AVL condition, and we then identify which case to use (out of 4 cases)
template<typename Comparable>
void AVLTree<Comparable>::balance(AVLNode * & t) {
    if (t == nullptr) return;

    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
        if (height(t->left->left) >= height(t->left->right)) {
            rotateWithLeftChild(t); 
        } else {
            doubleWithLeftChild(t); 
        }
    } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
        if (height(t->right->right) >= height(t->right->left)) {
            rotateWithRightChild(t); 
        } else {
            doubleWithRightChild(t); 
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
}

// private rotateWithLeftChild: for case 1, referring to textbook, Figure 4.44 (code) and Figure 4.43 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithLeftChild(AVLNode * & k2) {
     AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

// private rotateWithRightChild: for case 4 (the mirrored case of case 1)
template<typename Comparable>
void AVLTree<Comparable>::rotateWithRightChild(AVLNode * & k2) {
    AVLNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;
    k2 = k1;
}


// private doubleWithLeftChild: for case 2, see textbook, Figure 4.46 (code) and Figure 4.45 (visualization)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithLeftChild(AVLNode * & k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// private doubleWithRightChild: for case 3 (the mirrored case of case 2)
template<typename Comparable>
void AVLTree<Comparable>::doubleWithRightChild(AVLNode * & k3) {
        rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);

}

// public isBalanced
template <class Comparable>
bool AVLTree<Comparable>::isBalanced() const {
    return isBalanced(root);
}
template <class Comparable>
bool AVLTree<Comparable>::isBalanced(AVLNode * t) const {
    if (t == nullptr) return true;

    int leftHeight = height(t->left);
    int rightHeight = height(t->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(t->left) && isBalanced(t->right);
}
// public isBST
template <class Comparable>
bool AVLTree<Comparable>::isBST() const {
    return isBST(root, nullptr, nullptr);
}

template <class Comparable>
bool AVLTree<Comparable>::isBST(AVLNode * t, const Comparable * min, const Comparable * max) const {
    if (t == nullptr) return true;

    if ((min != nullptr && t->element <= *min) || (max != nullptr && t->element >= *max))
        return false;

    return isBST(t->left, min, &t->element) && isBST(t->right, &t->element, max);
}
// public treeSize
template <typename Comparable>
int AVLTree<Comparable>::treeSize() const {
      return treeSize(root);

}
template <typename Comparable>
int AVLTree<Comparable>::treeSize(AVLNode * t) const {
    if (t == nullptr) return 0;
    return 1 + treeSize(t->left) + treeSize(t->right);
}

// public computeHeight. See Figure 4.61 in Textbook
template <typename Comparable>
int AVLTree<Comparable>::computeHeight() const {
    return computeHeight(root);
}

template <typename Comparable>
int AVLTree<Comparable>::computeHeight(AVLNode * t) const {
    if (t == nullptr) {
        return -1; 
    }
    return 1 + max(computeHeight(t->left), computeHeight(t->right));
}

// public readRootHeight
template <typename Comparable>
int AVLTree<Comparable>::readRootHeight() const {
   if (root == nullptr) {
    return -1;
   }
    return root->height;
}

// public averageDepth
template <typename Comparable>
double AVLTree<Comparable>::averageDepth() const {
    int totalDepth = 0;
    int nodeCount = 0;
    averageDepth(root, 0, totalDepth, nodeCount);
    return nodeCount == 0 ? 0.0 : static_cast<double>(totalDepth) / nodeCount;
}
template <typename Comparable>
void AVLTree<Comparable>::averageDepth(AVLNode * t, int depth, int & totalDepth, int & nodeCount) const {
    if (t == nullptr) {
        return;
    }
    totalDepth += depth;
    nodeCount++;

    averageDepth(t->left, depth + 1, totalDepth, nodeCount);
    averageDepth(t->right, depth + 1, totalDepth, nodeCount);
}

// public removeByRank
template <typename Comparable>
void AVLTree<Comparable>::removeByRank(int rank) {
        removeByRank(root, rank);

}


template <typename Comparable>
void AVLTree<Comparable>::removeByRank(AVLNode * & t, int rank) {
    if (t == nullptr) {
        return;
    }
    int leftSize = treeSize(t->left);

    if (rank < leftSize) {
        removeByRank(t->left, rank);
    } else if (rank > leftSize) {
        removeByRank(t->right, rank - leftSize - 1);
    } else {
        remove(t->element, t); 
    }

    balance(t); 
}