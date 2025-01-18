#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    void append(int val) {
        if (head == NULL) {
            head = new Node(val);
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    void printList(Node* node) {
        while (node != NULL) {
            cout << node->data << " -> ";
            node = node->next;
        }
        cout << "NULL" << endl;
    }

    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        list.append(val);
    }

    cout << "Original list: ";
    list.printList(list.head);

    list.head = list.reverseList(list.head);

    cout << "Reversed list: ";
    list.printList(list.head);

    return 0;
}
