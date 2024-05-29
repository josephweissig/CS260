#include <iostream>

/***********************
 * LINKED LIST VERSION *
 ***********************/

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        // Structure's gotta start somewhere, so here we take care of the case where the tree is empty
        if (node == nullptr) {
            return new Node(data);
        }

        // Otherwise, we need to figure out where to insert the new node
        // If the data is less than the current node's data, we need to insert it in the left subtree
        // And if the data is greater than the current node's data, we need to insert it in the right subtree
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    void display(Node* node) {
        // If there's no tree, there's nothing to print
        if (node == nullptr) {
            return;
        }

        // Recursively call display until we hit proper leaves of the subtrees
        display(node->left);
        std::cout << node->data << " ";
        display(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void printTree() {
        display(root);
        std::cout << std::endl;
    }
};

/***********************
 * ARRAY-BASED VERSION *
 ***********************/

class SortedArray {
private:
    int* data;
    int capacity;
    int size;

public:
    SortedArray(int capacity) : capacity(capacity), size(0) {
        data = new int[capacity];
    }

    ~SortedArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            std::cout << "Array is full" << std::endl;
            return;
        }

        // Just naïvely go through the array from the top down, shifting elements to the right
        //  until we find the right spot for our new value
        int i;
        for (i = size - 1; (i >= 0 && data[i] > value); i--) {
            data[i + 1] = data[i];
        }

        // Then we put the new value where we stopped the for-loop
        data[i + 1] = value;
        size++;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    // Oh apparently this doesn't handle duplicates great...
    // I changed the code to specify that duplicate values go toward the left subtree.
    tree.insert(1);
    tree.insert(5);
    tree.insert(9);
    std::cout << "Linked List: ";
    tree.printTree();

    SortedArray array(10);
    array.insert(3);
    array.insert(1);
    array.insert(4);
    array.insert(1);
    array.insert(5);
    array.insert(9);
    std::cout << "Array: ";
    array.print();
}