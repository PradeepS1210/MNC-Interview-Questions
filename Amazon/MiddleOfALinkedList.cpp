/*
Examples:
============

Input:
Enter the size of the linked list: 5
Enter the values of the linked list: 1 2 3 4 5

Output: The middle element is: 3

Input:
Enter the size of the linked list: 6
Enter the values of the linked list: 2 4 6 7 5 1

Output: The middle element is: 7
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == NULL)
            return -1;

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

Node *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; ++i)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the linked list: ";
    cin >> n;

    int value[n];
    cout << "Enter the values of the linked list: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> value[i];
    }

    Node *head = createLinkedList(value, n);

    Solution solution;
    int middleValue = solution.getMiddle(head);
    cout << "The middle element is: " << middleValue << endl;

    // Optional: Print the linked list (for verification)
    // printLinkedList(head);

    return 0;
}
