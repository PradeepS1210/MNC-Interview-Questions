/*
Examples:
===========
Input:
Enter the number of nodes: 6
Enter the values of the nodes: 1 2 3 4 5 6

Output:
Reversed linked list: 6 5 4 3 2 1

Input:
Enter the number of nodes: 5
Enter the values of the nodes: 2 7 10 9 8

Output:
Reversed linked list: 8 9 10 7 2
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
    struct Node *reverseList(struct Node *head)
    {
        struct Node *prev = NULL;
        struct Node *current = head;
        struct Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    struct Node *head = new Node(arr[0]);
    struct Node *tail = head;
    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    struct Node *head = createList(arr, n);

    Solution sol;
    struct Node *reversedHead = sol.reverseList(head);

    cout << "Reversed linked list: ";
    printList(reversedHead);

    delete[] arr;
    return 0;
}
