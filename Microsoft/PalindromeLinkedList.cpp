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
private:
    Node *reverseList(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *secondHalf = reverseList(slow);

        Node *firstHalf = head;
        Node *secondHalfCopy = secondHalf;
        bool isPalindrome = true;
        while (secondHalf != NULL)
        {
            if (firstHalf->data != secondHalf->data)
            {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        reverseList(secondHalfCopy);

        return isPalindrome;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertAtEnd(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}

int main()
{
    Solution obj;
    Node *head = NULL;

    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        head = insertAtEnd(head, val);
    }

    cout << "The linked list is: ";
    printList(head);

    if (obj.isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
