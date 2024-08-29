/*
Example:
=========
Input:
Enter the number of nodes in the linked list: 6
Enter the elements of the linked list: 1 2 3 4 5 6
Enter the position to create a loop (0 if no loop): 3

Output: Length of the loop is: 4
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
    int countNodesinLoop(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return 0;

        struct Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                int loopLength = 1;
                struct Node *temp = slow;

                while (temp->next != slow)
                {
                    loopLength++;
                    temp = temp->next;
                }
                return loopLength;
            }
        }
        return 0;
    }
};

void createLoop(Node *head, int position)
{
    if (position == 0)
        return;

    Node *temp = head;
    Node *loopNode = nullptr;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == position)
        {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    if (loopNode != NULL)
    {
        temp->next = loopNode;
    }
}

Node *createLinkedList(int n)
{
    int data;
    cin >> data;
    Node *head = new Node(data);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

int main()
{
    int n, position;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    cout << "Enter the elements of the linked list: ";
    Node *head = createLinkedList(n);

    cout << "Enter the position to create a loop (0 if no loop): ";
    cin >> position;

    createLoop(head, position);

    Solution ob;
    int loopLength = ob.countNodesinLoop(head);

    if (loopLength == 0)
    {
        cout << "No loop detected in the linked list." << endl;
    }
    else
    {
        cout << "Length of the loop is: " << loopLength << endl;
    }

    return 0;
}
