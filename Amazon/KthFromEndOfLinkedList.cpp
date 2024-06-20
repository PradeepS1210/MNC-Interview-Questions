/*
Example 1:
============
Input:
Enter the number of nodes in the linked list: 5
Enter the values of the nodes: 1 2 3 4 5
Enter the position (from end) of the node to find (1-indexed): 2

Output:
The 2th node from the end is: 4

Example 2:
============
Input:
Enter the number of nodes in the linked list: 3
Enter the values of the nodes: 10 20 30
Enter the position (from end) of the node to find (1-indexed): 5

Output:
Invalid position. It's beyond the number of nodes.

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution
{
public:
    int getKthFromLast(Node *head, int k)
    {
        if (head == NULL || k <= 0)
            return -1;

        Node *first = head;
        Node *second = head;

        for (int i = 0; i < k; ++i)
        {
            if (first == NULL)
                return -1;
            first = first->next;
        }

        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }

        return second->data;
    }
};

Node *createLinkedList(int values[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(values[0]);
    Node *current = head;
    for (int i = 1; i < n; ++i)
    {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

int main()
{
    int n, k;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid input. Number of nodes must be positive." << endl;
        return 1;
    }

    int *values = new int[n];
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    cout << "Enter the position (from end) of the node to find (1-indexed): ";
    cin >> k;

    Solution sol;
    Node *head = createLinkedList(values, n);
    int result = sol.getKthFromLast(head, k);

    if (result == -1)
    {
        cout << "Invalid position. It's beyond the number of nodes." << endl;
    }
    else
    {
        cout << "The " << k << "th node from the end is: " << result << endl;
    }

    delete[] values;

    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
