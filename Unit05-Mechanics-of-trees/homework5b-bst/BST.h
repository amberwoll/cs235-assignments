#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

private:
    Node* root = nullptr;
    int treeSize = 0;

    void clearNode(Node* node) {
        if (node) {
            clearNode(node->left);
            clearNode(node->right);
            delete node;
        }
    }

public:
    BST() {}

    ~BST() {
        clear();
    }

    const Node* getRootNode() const {
        return root;
    }

    bool insert(T item) {
        Node** current = &root;
        while (*current) {
            if (item < (*current)->value) {
                current = &((*current)->left);
            } else if (item > (*current)->value) {
                current = &((*current)->right);
            } else {
                return false;
            }
        }
        *current = new Node(item);
        treeSize++;
        return true;
    }

    bool remove(T item) {
        Node** current = &root;
        while (*current) {
            if (item < (*current)->value) {
                current = &((*current)->left);
            } else if (item > (*current)->value) {
                current = &((*current)->right);
            } else {
                Node* toDelete = *current;
                if (!toDelete->left) {
                    *current = toDelete->right;
                } else if (!toDelete->right) {
                    *current = toDelete->left;
                } else {
                    Node* branch = toDelete->right;
                    Node** base = &(toDelete->right);
                    while (branch->left) {
                        base = &(branch->left);
                        branch = branch->left;
                    }

                    toDelete->value = branch->value;
                    toDelete = branch;
                    *base = branch->right;
                }
                delete toDelete;
                treeSize--;
                return true;
            }
        }
        return false;
    }

    bool contains(T item) const {
        Node* current = root;
        while (current) {
            if (item < current->value) {
                current = current->left;
            } else if (item > current->value) {
                current = current->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void clear() {
        clearNode(root);
        root = nullptr;
        treeSize = 0;
    }

    int size() const {
        return treeSize;
    }
};
