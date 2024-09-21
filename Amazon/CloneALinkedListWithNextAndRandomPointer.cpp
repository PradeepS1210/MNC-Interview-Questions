/*
Example:
=========
Input:
Enter the number of nodes in the linked list: 4
Enter the number of random pointer pairs: 2
Enter the random pointer pairs in format a b (denoting a->random = b):
1 2
2 4

Output:
Original List:
Node data: 1, Random data: 2
Node data: 2, Random data: 4
Node data: 3, Random data: NULL
Node data: 4, Random data: NULL

Copied List:
Node data: 1, Random data: 2
Node data: 2, Random data: 4
Node data: 3, Random data: NULL
Node data: 4, Random data: NULL
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;
        while (curr)
        {
            Node *newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        curr = head;
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node *copyHead = head->next;
        Node *copyCurr = copyHead;
        while (curr)
        {
            curr->next = curr->next->next;
            if (copyCurr->next)
            {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << "Node data: " << temp->data << ", Random data: ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

Node *createLinkedList(int n, unordered_map<int, int> &randomPairs)
{
    if (n == 0)
        return nullptr;

    Node *head = new Node(1);
    Node *curr = head;
    unordered_map<int, Node *> nodeMap;

    nodeMap[1] = head;
    for (int i = 2; i <= n; ++i)
    {
        curr->next = new Node(i);
        curr = curr->next;
        nodeMap[i] = curr;
    }

    for (auto &pair : randomPairs)
    {
        int a = pair.first, b = pair.second;
        nodeMap[a]->random = nodeMap[b];
    }

    return head;
}

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    int m;
    cout << "Enter the number of random pointer pairs: ";
    cin >> m;

    unordered_map<int, int> randomPairs;
    cout << "Enter the random pointer pairs in format a b (denoting a->random = b):\n";
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        randomPairs[a] = b;
    }

    Node *head = createLinkedList(n, randomPairs);

    cout << "\nOriginal List:\n";
    printList(head);

    Node *copiedList = solution.copyList(head);

    cout << "\nCopied List:\n";
    printList(copiedList);

    return 0;
}
