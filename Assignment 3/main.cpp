#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

struct Node {
    int data;
    Node *next;
};

class Queue {
    private:
        Node *head;
        Node *tail;
    public:
        Queue() {
            head = NULL;
            tail = NULL;
        }

        void enqueue(int data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = NULL;
            if (head == NULL && tail == NULL) {
                head = temp;
                tail = temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }

        int dequeue() {
            if (head == NULL) {
                return NULL;
            }
            Node* temp = head;
            if (head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
            }
            int returnData = temp->data;
            delete temp;
            return returnData;
        }

        void peek() {
            if (head == NULL) {
                cout << "Queue is empty" << endl;
            } else {
                cout << head->data << endl;
            }
        }

        bool isEmpty() {
            return head == NULL;
        }
};

int main() {
    Queue q = Queue();
    q.peek();  // Should tell us the queue is empty
    q.enqueue(1);
    q.peek();  // Should tell us the head of the queue is 1
    int firstValue = q.dequeue();   // Returns the head of the queue and deletes, in this case 1
    cout << "firstValue: " << firstValue << endl;
    q.peek();  // Should tell us the queue is empty again

    q.enqueue(8000);
    int secondValue = q.dequeue(); // Returns the head of the queue and deletes, in this case 8000
    cout << endl << "secondValue: " << secondValue << endl;
    int thirdValue = q.dequeue();  // Should return NULL, but is converted to 0 implicitly.
    cout << "thirdValue: " << thirdValue << endl;
    return 0;
}