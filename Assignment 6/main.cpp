#include <iostream>

using std::cout;
using std::endl;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int data) : value(data), left(nullptr), right(nullptr) {}
    Node(int data, Node* left, Node* right) : value(data), left(left), right(right) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data <= node->value) {
            node->left = insert(node->left, data);
        } else if (data > node->value) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    Node* remove(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->value) {
            node->left = remove(node->left, data);
        } else if (data > node->value) {
            node->right = remove(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }

        return node;
    }

    Node* findMin(Node* node) {
        Node* current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }
    
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    BinaryTree(Node* root) : root(root) {}

    void inOrderDisplay() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrderDisplay() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrderDisplay() {
        postOrderTraversal(root);
        cout << endl;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = remove(root, data);
    }
};

int main() {
    // Constructing the tree from the illustrated examples:
    Node root = Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, nullptr, new Node(6)));
    BinaryTree exampleTree = BinaryTree(&root);

    cout << "Illustrated examples:" << endl << "In-order traversal: ";
    exampleTree.inOrderDisplay();

    cout << "Pre-order traversal: ";
    exampleTree.preOrderDisplay();

    cout << "Post-order traversal: ";
    exampleTree.postOrderDisplay();

    // Creating a new tree not based on anything, just inserting and letting the tree decide.
    BinaryTree tree;

    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(1);
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(6);

    cout << endl << "New tree:" << endl << "In-order traversal: ";
    tree.inOrderDisplay();

    cout << "Pre-order traversal: ";
    tree.preOrderDisplay();

    cout << "Post-order traversal: ";
    tree.postOrderDisplay();

    cout << endl << "Remove the 9 from the new tree" << endl;
    tree.remove(9);
    tree.inOrderDisplay();
}