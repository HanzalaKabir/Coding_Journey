#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
node *createLinkedList(int n)
{
    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> x;

        node *newNode = new node(x);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
node *insertBegin(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        return temp;
    }
    node *curr = head;
    temp->next = curr->next;
    curr->next = temp;
    int replace = curr->data;
    curr->data = temp->data;
    temp->data = replace;
    return head;
}
node *insertEnd(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        return temp;
    }
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
node *deleteFirst(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = head->next;
        delete head;
        return temp;
    }
}
node *deleteLast(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}
node *insertAtPos(node *head, int pos, int data)
{
    node *temp = new node(data);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    node *curr = head;
    for (int i = 1; i <= pos - 2 && curr->next != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
int searchInSingly(node *head, int data)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == data)
    {
        return 1;
    }
    else
    {
        int res = searchInSingly(head->next, data);
        if (res == -1)
        {
            return -1;
        }
        return res + 1;
    }
}
bool checkLoop(int *head)
{
    class Solution
    {
    public:
        // Function to check if the linked list has a loop.
        bool detectLoop(node *head)
        {
            // your code here
            if (head->next == NULL)
            {
                return false;
            }
            node *slow = head;
            node *fast = head->next->next;
            while (fast->next->next != NULL)
            {
                if (fast == slow)
                {
                    return true;
                }
                slow = slow->next;
                fast = fast->next->next;
                if (fast->next == NULL)
                {
                    return false;
                }
            }
            return false;
        }
    };
}
void rPrint(node *head)
{ // Print singly linked list
    if (head == NULL)
    {
        return;
    }
    node *print = head;
    while (print != NULL)
    {
        cout << (print->data) << " ";
        print = print->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    int n, data;
    cout << "Enter the number of nodes in list:";
    cin >> n;
    head = createLinkedList(n);
    cout << "List created is:" << endl;
    rPrint(head);
    cout << "Enter data to be inserted in list:" << endl;
    cin >> data;
    head = insertEnd(head, data);
    cout << "List is:" << endl;
    rPrint(head);
    // cout << "Enter data to be inserted at beggining of list:" << endl;
    // cin >> data;
    // head = insertBegin(head, data);
    // cout << "List after inserting " << data << " in the beginning is:" << endl;
    // rPrint(head);
    // cout << "List after deleting first node:" << endl;
    // head = deleteFirst(head);
    // rPrint(head);
    // cout << "List after deleting last node:" << endl;
    // head = deleteLast(head);
    // rPrint(head);
    // cout << "Enter position at which data is to be inserted:" << endl;
    // int pos;
    // cin >> pos;
    // cout << "Enter data to be inserted at " << pos << "nd position of list:" << endl;
    // cin >> data;
    // head = insertAtPos(head, pos, data);
    // rPrint(head);
    cout << "Enter data to be searched:" << endl;
    cin >> data;
    int result = searchInSingly(head, data);
    cout << result << endl;
    return 0;
}