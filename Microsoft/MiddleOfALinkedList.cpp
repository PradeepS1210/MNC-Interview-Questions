#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == nullptr)
        {
            return -1;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;
    Node *head = nullptr;

    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    cout << "Enter the elements of the linked list: " << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "Linked list: ";
    displayList(head);

    int middleElement = sol.getMiddle(head);
    if (middleElement != -1)
    {
        cout << "The middle element is: " << middleElement << endl;
    }
    else
    {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}
