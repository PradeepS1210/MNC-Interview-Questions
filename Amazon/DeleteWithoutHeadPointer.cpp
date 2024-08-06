/*
Example:
=========
Enter the number of nodes: 5
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Enter data for node 5: 50
Original list: 10 20 30 40 50
Enter the position of the node to delete (1-based index): 3
List after deletion: 10 20 40 50
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    void deleteNode(Node *del_node)
    {
        if (del_node == NULL || del_node->next == NULL)
        {
            return;
        }

        Node *temp = del_node->next;
        del_node->data = temp->data;

        del_node->next = temp->next;

        delete temp;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int n, data;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "List is empty" << endl;
        return 0;
    }

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    int delete_pos;
    cout << "Enter the position of the node to delete (1-based index): ";
    cin >> delete_pos;

    if (delete_pos <= 0 || delete_pos > n)
    {
        cout << "Invalid position" << endl;
        return 0;
    }

    Node *del_node = head;
    for (int i = 1; i < delete_pos; i++)
    {
        del_node = del_node->next;
    }

    Solution sol;
    sol.deleteNode(del_node);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
