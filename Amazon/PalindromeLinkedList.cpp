/*
Examples:
==========
Input:
Enter the number of nodes in the linked list: 5
Enter the values of the linked list nodes: 1 2 3 2 1

Output:
The linked list 1 2 3 2 1
is a palindrome.

Input:
Enter the number of nodes in the linked list: 4
Enter the values of the linked list nodes: 1 2 3 4

Output:
The linked list 1 2 3 4
is not a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }

        Node *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow->next);

        Node *p1 = head, *p2 = secondHalf;
        bool isPalindrome = true;
        while (isPalindrome && p2 != nullptr)
        {
            if (p1->data != p2->data)
            {
                isPalindrome = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        slow->next = reverseList(secondHalf);

        return isPalindrome;
    }

private:
    Node *reverseList(Node *head)
    {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

Node *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input. Number of nodes should be greater than 0." << endl;
        return 0;
    }

    int *arr = new int[n];
    cout << "Enter the values of the linked list nodes: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Node *head = createLinkedList(arr, n);
    delete[] arr;

    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "The linked list ";
    printLinkedList(head);
    if (result)
    {
        cout << "is a palindrome." << endl;
    }
    else
    {
        cout << "is not a palindrome." << endl;
    }

    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
