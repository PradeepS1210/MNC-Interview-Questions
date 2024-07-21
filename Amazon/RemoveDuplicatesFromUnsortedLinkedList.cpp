/*
Example:
==========
Input:
Enter the number of nodes: 4
Enter the values of the nodes: 5 2 2 4

Output: Linked list after removing duplicates: 5 2 4
Explanation:Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4
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
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
            return NULL;

        unordered_set<int> seen;

        Node *current = head;
        Node *prev = NULL;

        while (current != NULL)
        {
            if (seen.find(current->data) != seen.end())
            {
                prev->next = current->next;
                delete current;
            }
            else
            {
                seen.insert(current->data);
                prev = current;
            }
            current = prev->next;
        }
        return head;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *createLinkedList(vector<int> values)
{
    if (values.empty())
        return NULL;

    Node *head = new Node(values[0]);
    Node *tail = head;

    for (int i = 1; i < values.size(); i++)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }
    return head;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    Node *head = createLinkedList(values);
    Solution ob;
    head = ob.removeDuplicates(head);

    cout << "Linked list after removing duplicates: ";
    printList(head);

    return 0;
}
