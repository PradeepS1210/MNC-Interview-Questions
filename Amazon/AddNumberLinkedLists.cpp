/*
Example 1:
============
Input:
Enter the first number: 190
Enter the second number: 25

Output: Sum of the two numbers: 2->1->5

Example 2:
============
Input:
Enter the first number: 45
Enter the second number: 345

Output: Sum of the two numbers: 3->9->0
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
    Node *func(Node *num1, Node *num2, int c)
    {
        if (!num1 && !num2)
            return c ? new Node(c) : NULL;
        int sum = (num1 ? num1->data : 0) + (num2 ? num2->data : 0) + c;
        Node *nn = new Node(sum % 10);
        nn->next = func((num1 ? num1->next : num1), (num2 ? num2->next : num2), sum / 10);
        return nn;
    }

    Node *rev(Node *head)
    {
        Node *tmp = NULL, *prev = NULL, *curr = head;
        while (curr)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    Node *rz(Node *head)
    {
        while (head && head->data == 0)
            head = head->next;
        return head == NULL ? new Node(0) : head;
    }

    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        return rz(rev(func(rev(rz(num1)), rev(rz(num2)), 0)));
    }
};

void printList(Node *n)
{
    while (n)
    {
        cout << n->data;
        n = n->next;
        if (n)
            cout << "->";
    }
    cout << endl;
}

Node *createList(string num)
{
    Node *head = new Node(num[0] - '0');
    Node *tail = head;
    for (int i = 1; i < num.length(); ++i)
    {
        tail->next = new Node(num[i] - '0');
        tail = tail->next;
    }
    return head;
}

int main()
{
    string num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    Node *head1 = createList(num1);
    Node *head2 = createList(num2);

    Solution sol;
    Node *result = sol.addTwoLists(head1, head2);

    cout << "Sum of the two numbers: ";
    printList(result);

    return 0;
}
