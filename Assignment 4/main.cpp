#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T>
struct Node {
    Node(T data, Node* next) {
        this->data = data;
        this->next = next;
    }
    T data;
    Node* next;
};

class RandomAccessList {
    private:
        Node<int> *top = nullptr;
        int size = 0;

    public:
        RandomAccessList() {
            top = nullptr;
            size = 0;
        }

        int getSize() {
            return size;
        }

        // Add a value to the list at a specific position
        // NOTE: `position` is the position *before* which the value will be inserted
        // NOTE: If `position` is negative, the value will be inserted at the beginning of the list
        void add(int value, int position) {
            Node<int> *newNode = new Node<int>(value, nullptr);
            Node<int> *current = top;

            if (position < 0) {
                newNode->next = top;
                top = newNode;
                return;
            }

            if (current != nullptr) {
                for (int currentPos = 0; currentPos < position && current->next != nullptr; currentPos++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            } else {
                top = newNode;
            }

            size++;
        }

        int remove(int position) {
            if (top == nullptr || position < 0) {
                cout << "Invalid position" << endl;
                return -1;
            }

            Node<int>* current = top;
            int returnValue;

            // Special case for removing the head
            if (position == 0) {
                top = current->next;
                returnValue = current->data;
                delete current;
            } else {
                // Find the node before the one we want to remove
                for (int i = 0; i < position - 1; i++) {
                    if (current->next == nullptr) {
                        throw std::out_of_range("Invalid position");
                    }
                    current = current->next;
                }

                // Remove the node
                Node<int>* nodeToRemove = current->next;
                if (nodeToRemove == nullptr) {
                    throw std::out_of_range("Invalid position");
                }
                current->next = nodeToRemove->next;
                returnValue = nodeToRemove->data;
                delete nodeToRemove;
            }

            size--;
            return returnValue;
        }

        int get(int position) {
            if (top == nullptr || position < 0) {
                cout << "Invalid position" << endl;
                return -1;
            }

            Node<int>* current = top;
            
            if (position == 0) {
                return top->data;
            } else {
                // Find the node before the one we want to get
                for (int i = 0; i < position - 1; i++) {
                    if (top->next == nullptr) {
                        cout << "Invalid position" << endl;
                        return -1;
                    }
                    current = current->next;
                }
                return current->data;
            }
        }

        string toString() {
            string result = "";
            Node<int> *current = top;

            while (current != nullptr) {
                result += std::to_string(current->data) + ", ";
                current = current->next;
            }

            return result;
        }
};

int main() {
    // Create a new RandomAccessList object
    RandomAccessList list = RandomAccessList();

    // Add some values to the list
    list.add(1, 0);
    list.add(2, 1);
    list.add(3, 2);
    list.add(4, 3);
    list.add(5, 4);

    // Print the list
    cout << "First list: \n" << list.toString() << "size " << list.getSize() << endl;

    // Add a value to the list at a specific position (in this case, between 2 and 3):
    // Using `1` since value 2 is in the 1st position in the list, and we want to place the new value after 2:
    list.add(80, 1);

    // Print the list containing the new value
    cout << "Second list:\n" << list.toString() << "size " << list.getSize() << endl;

    // Remove a value from the list at a specific position (in this case, the number 4 in 4th position):
    list.remove(3);

    // Print the list without the number 4
    cout << "Third list:\n" << list.toString() << "size " << list.getSize() << endl;

    return 0;
}