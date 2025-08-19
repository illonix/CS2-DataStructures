#ifndef CS2_TREE_LAB_BTREE_HPP
#define CS2_TREE_LAB_BTREE_HPP

#include <iostream>

template <typename T>
class btree {
public:
              btree    ()                 : left(0), right(0), empty(true) {}
              btree    (const T& val)     : left(0), right(0), empty(false), data(val) {}
              btree    (const btree<T>&);
              ~btree   ();
    void      swap     (btree<T>&);
    btree<T>& operator=(btree<T> rhs)     { swap(rhs); return *this; }

    bool      isEmpty  () const           { return empty; }
    void      insert   (const T&);

    // TODO - NEEDS IMPLEMENTING
    int       findDepth(const T&) const;
    bool      find     (const T&) const;
    void      inorder  (std::ostream&) const;
    void      preorder (std::ostream&) const;
    void      postorder(std::ostream&) const;

private:
    btree<T>* left;
    btree<T>* right;
    bool      empty;
    T         data;

};

template <typename T>
btree<T>::btree(const btree<T>& actual) : btree<T>() {
    // Preorder
    // Visit - copy the data
    data = actual.data;
    empty = actual.empty;
    // Left
    if (actual.left)  { left  = new btree<T>(*(actual.left));  }
    // Right
    if (actual.right) { right = new btree<T>(*(actual.right)); }
}

template <typename T>
btree<T>::~btree() {
    // Postorder
    // Left
    if (left)  delete left;
    // Right
    if (right) delete right;
    // Visit - compiler deletes *this.
}

template <typename T>
void btree<T>::swap(btree<T>& rhs) {
    T temp = data;
    data = rhs.data;
    rhs.data = temp;
    bool tempty = empty;
    empty = rhs.empty;
    rhs.empty = tempty;
    
    btree<T> *ptr = left;
    left = rhs.left;
    rhs.left = ptr;
    ptr = right;
    right = rhs.right;
    rhs.right = ptr;
}


template <typename T>
void btree<T>::insert(const T& item) {
    if (empty) {
        data = item;
        empty = false;
    }
    else if (item < data) {
        if (!left) { left = new btree<T>(item); }
        else       { left->insert(item); }
    }
    else if (item > data) {
        if (!right) { right = new btree<T>(item); }
        else        { right->insert(item); }
    }
    else { return; } //No duplicates
}

template <typename T>
int btree<T>::findDepth(const T& key) const {
    if (empty) {
        return -1; // Tree is empty or key not found
    }
    if (data == key) {
        return 0; // Found at root
    }
    if (key < data && left) {
        int depth = left->findDepth(key);
        return (depth == -1) ? -1 : depth + 1;
    }
    if (key > data && right) {
        int depth = right->findDepth(key);
        return (depth == -1) ? -1 : depth + 1;
    }
    return -1; // Key not found
}

template <typename T>
bool btree<T>::find(const T& key) const {
    // TODO - Needs implementing!

    if (empty) {
        return false; // Tree is empty or key not found
    }
    if (data == key) {
        return true; // Key matches the current node
    }
    if (key < data && left) {
        return left->find(key); // Search in the left subtree
    }
    if (key > data && right) {
        return right->find(key); // Search in the right subtree
    }
    return false; // Key not found
}

template <typename T>
void btree<T>::postorder(std::ostream& out) const {
    // TODO - Needs implementing!
    if (empty) {
        return; // Empty tree, nothing to do
    }
    if (left) {
        left->postorder(out); // Visit left subtree
    }
    if (right) {
        right->postorder(out); // Visit right subtree
    }
    out << data << " "; // Visit current node
}



template <typename T>
void btree<T>::preorder(std::ostream& out) const {
    // TODO - Needs implementing!

    if (empty) {
        return; // Empty tree, nothing to do
    }
    out << data << " "; // Visit current node
    if (left) {
        left->preorder(out); // Visit left subtree
    }
    if (right) {
        right->preorder(out); // Visit right subtree
    }
}



template <typename T>
void btree<T>::inorder(std::ostream& out) const {
    // TODO - Needs implementing!

    if (empty) {
        return; // Empty tree, nothing to do
    }
    if (left) {
        left->inorder(out); // Visit left subtree
    }
    out << data << " "; // Visit current node
    if (right) {
        right->inorder(out); // Visit right subtree
    }
}



#endif
