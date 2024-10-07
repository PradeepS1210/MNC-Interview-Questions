/*
Example:
=========
XOR Linked List Operations
1. Insert at front
2. Display list
3. Exit

Enter your choice (1-3): 1
Enter the integer to insert: 10
Inserted 10 at the front of the list.

Enter your choice (1-3): 1
Enter the integer to insert: 20
Inserted 20 at the front of the list.

Enter your choice (1-3): 1
Enter the integer to insert: 30
Inserted 30 at the front of the list.

Enter your choice (1-3): 2
XOR Linked List: 30 20 10 

Enter your choice (1-3): 3
Exiting the program. Goodbye!
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node* XOR(struct Node *a, struct Node *b) {
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node* insert(struct Node *head, int data) {
    Node* newNode = new Node(data);

    newNode->npx = XOR(NULL, head);

    if (head != NULL) {
        Node* nextNode = XOR(NULL, head->npx);
        head->npx = XOR(newNode, nextNode);
    }

    return newNode;
}

vector<int> getList(struct Node *head) {
    vector<int> result;
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while (curr != NULL) {
        result.push_back(curr->data);

        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }

    return result;
}


int main() {
    struct Node* head = NULL;
    int choice, data, n;

    cout << "XOR Linked List Operations\n";
    cout << "1. Insert at front\n";
    cout << "2. Display list\n";
    cout << "3. Exit\n";

    while (true) {
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the integer to insert: ";
            cin >> data;
            head = insert(head, data);
            cout << "Inserted " << data << " at the front of the list.";
        }
        else if (choice == 2) {
            vector<int> list = getList(head);
            if (list.empty()) {
                cout << "The list is empty.";
            }
            else {
                cout << "XOR Linked List: ";
                for (int val : list) {
                    cout << val << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please enter 1, 2, or 3.";
        }
    }

    return 0;
}
