/*
Example 1:
============
Input:
Enter the number of nodes in the first linked list: 3
Enter the values for the first linked list: 10 15 30
Enter the number of nodes in the second linked list: 3
Enter the values for the second linked list: 3 6 9
Enter the intersection node value (enter -1 if no intersection): 15

Output: The intersection point is 15

Example 2:
============
Input:
Enter the number of nodes in the first linked list: 4
Enter the values for the first linked list: 1 2 3 4
Enter the number of nodes in the second linked list: 3
Enter the values for the second linked list: 5 6 7
Enter the intersection node value (enter -1 if no intersection): -1

Output: No Intersection
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

int getLength(Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

int intersectPoint(Node *head1, Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node *longer = len1 > len2 ? head1 : head2;
    Node *shorter = len1 > len2 ? head2 : head1;

    for (int i = 0; i < diff; i++)
    {
        if (longer != NULL)
        {
            longer = longer->next;
        }
    }

    while (longer != NULL && shorter != NULL)
    {
        if (longer == shorter)
        {
            return longer->data;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return -1;
}

Node *newNode(int data)
{
    Node *node = new Node(data);
    return node;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void appendNode(Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    Node *last = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

int main()
{
    int n1, n2, intersectValue;

    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n1;
    Node *head1 = NULL;
    cout << "Enter the values for the first linked list: ";
    for (int i = 0; i < n1; i++)
    {
        int value;
        cin >> value;
        appendNode(&head1, value);
    }

    cout << "Enter the number of nodes in the second linked list: ";
    cin >> n2;
    Node *head2 = NULL;
    cout << "Enter the values for the second linked list: ";
    for (int i = 0; i < n2; i++)
    {
        int value;
        cin >> value;
        appendNode(&head2, value);
    }

    cout << "Enter the intersection node value (enter -1 if no intersection): ";
    cin >> intersectValue;

    if (intersectValue != -1)
    {
        Node *intersectNode = newNode(intersectValue);
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = intersectNode;

        temp = head2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = intersectNode;
    }

    int intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == -1)
    {
        cout << "No Intersection" << endl;
    }
    else
    {
        cout << "The intersection point is " << intersectionPoint << endl;
    }

    return 0;
}
