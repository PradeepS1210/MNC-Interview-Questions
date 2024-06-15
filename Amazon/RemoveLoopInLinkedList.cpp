#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    void removeLoop(Node *head)
    {
        if (!head || !head->next)
            return;

        Node *slow = head, *fast = head;
        bool loopExists = false;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                loopExists = true;
                break;
            }
        }

        if (loopExists)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            Node *prev = slow;
            while (fast->next != slow)
            {
                fast = fast->next;
            }

            fast->next = nullptr;
        }
    }
};

Node *createLinkedList()
{
    int n;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input. Number of nodes must be greater than zero." << endl;
        return nullptr;
    }

    int values[n];
    cout << "Enter values for the nodes: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int pos;
    cout << "Enter the position of the node to which the last node should link back (0 for no loop): ";
    cin >> pos;

    Node *head = new Node(values[0]);
    Node *tail = head;
    Node *loopStart = nullptr;

    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
        if (i == pos - 1)
            loopStart = tail;
    }

    if (pos > 0)
        tail->next = loopStart;

    return head;
}

void printLinkedList(Node *head)
{
    unordered_set<Node *> visited;
    Node *curr = head;

    cout << "Linked List: ";
    while (curr)
    {
        if (visited.count(curr))
        {
            cout << curr->data << " (Loop detected at node with value " << curr->data << ")";
            return;
        }
        cout << curr->data;
        visited.insert(curr);
        curr = curr->next;
        if (curr)
            cout << " -> ";
    }

    cout << " (No loop)";
}

int main()
{
    Node *head = createLinkedList();

    if (head)
    {
        Solution solution;
        solution.removeLoop(head);

        printLinkedList(head);
        cout << endl;
    }

    return 0;
}
