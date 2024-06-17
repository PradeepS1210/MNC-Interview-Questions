/*
Example
=========

Input:
Enter the number of nodes in the linked list: 3
Enter the values of nodes in the linked list: 1 3 4
Enter the position (1-based index) where the loop should be created (0 if no loop): 2

Output: True

Explanation:
1 -> 3 -> 4
     ^    |
     |____|

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
    bool detectLoop(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

Node *createLinkedList(int arr[], int n, int pos)
{
    if (n == 0)
    {
        return NULL;
    }

    Node *head = new Node(arr[0]);
    Node *tail = head;
    Node *loopNode = NULL;

    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;

        if (i == pos - 1)
        {
            loopNode = tail;
        }
    }

    if (pos > 0 && loopNode != NULL)
    {
        tail->next = loopNode;
    }

    return head;
}

int main()
{
    Solution sol;
    int n, pos;

    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input for number of nodes." << endl;
        return 0;
    }

    int value[n];

    cout << "Enter the values of nodes in the linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    cout << "Enter the position (1-based index) where the loop should be created (0 if no loop): ";
    cin >> pos;

    Node *head = createLinkedList(value, n, pos);

    bool hasLoop = sol.detectLoop(head);

    if (hasLoop)
    {
        cout << "Output: True" << endl;
    }
    else
    {
        cout << "Output: False" << endl;
    }

    return 0;
}
