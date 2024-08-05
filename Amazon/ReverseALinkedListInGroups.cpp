/*
Example:
=========
Input:
Enter the number of elements in the list: 8
Enter the elements of the list: 1 2 2 4 5 6 7 8
Enter the value of k: 4

Output: Modified linked list: 4 2 2 1 8 7 6 5
Explanation: The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8. Hence, the resultant linked list is 4->2->2->1->8->7->6->5.
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    struct node *reverseIt(struct node *head, int k)
    {
        if (!head || k <= 1)
            return head;

        struct node *current = head;
        struct node *prevTail = NULL;
        struct node *newHead = NULL;

        while (current)
        {
            struct node *groupHead = NULL;
            struct node *groupTail = current;
            struct node *prev = NULL;
            int count = 0;

            while (current && count < k)
            {
                struct node *next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            if (!newHead)
            {
                newHead = prev;
            }

            if (prevTail)
            {
                prevTail->next = prev;
            }

            prevTail = groupTail;
        }

        if (prevTail)
        {
            prevTail->next = NULL;
        }

        return newHead;
    }
};

void printList(struct node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct node *createList(int arr[], int size)
{
    if (size == 0)
        return NULL;

    struct node *head = new node(arr[0]);
    struct node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new node(arr[i]);
        current = current->next;
    }

    return head;
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    struct node *head = createList(arr, n);

    Solution sol;
    head = sol.reverseIt(head, k);

    cout << "Modified linked list: ";
    printList(head);

    return 0;
}
