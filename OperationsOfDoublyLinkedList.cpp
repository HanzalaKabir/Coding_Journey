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
    node *prev;
    node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};
node *insertBegin(node *head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    return temp;
}
node *insertEnd(node *head, int data)
{
    node *temp = new node(data);
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
    temp->prev = curr;
    return head;
}
node *insertAtKth(node *head, int pos, int data)
{
    node *temp = new node(data);
    int count = 0;
    node *previ = head;
    node *curr = head->next;
    while (pos != count)
    {
        count++;
        previ = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        previ->next = temp;
        temp->prev = previ;
        temp->next = curr;
        return;
    }
    previ->next = temp;
    temp->prev = previ;
    temp->next = curr;
    curr->prev = temp;
    return;
}
node *deleteFirst(node *head)
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
    else
    {
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
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
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
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
        if (curr->next == NULL && i != pos - 2)
        {
            cout << "Data could only be entered upto next to last position, given position is invalid.";
            return NULL;
        }
    }
    if (curr == NULL)
    {
        return head;
    }
    curr->next->prev = temp;
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}
int searchInDoubly(node *head, int data)
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
        int res = searchInDoubly(head->next, data);
        if (res == -1)
        {
            return -1;
        }
        return res + 1;
    }
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
    int n, data, pos;
    cout << "Enter the number of nodes in list:";
    cin >> n;
    cout << "Enter data to be inserted in list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        head = insertEnd(head, data);
    }
    cout << "List is:" << endl;
    rPrint(head);
    // cout << "Enter data to be inserted at beggining of list:" << endl;
    // cin >> data;
    // head = insertBegin(head, data);
    // cout << "List after inserting " << data << " in the beginning is:" << endl;
    // rPrint(head);
    // cout << "Enter position at which data has to be inserted:";
    // cin >> pos;
    // cout << "Enter data to be inserted:" << endl;
    // cin >> data;
    // cout << "List after inserting at given position " << endl;
    // head = insertAtPos(head, pos, data);
    // rPrint(head);
    // cout << "List after deleting first node:" << endl;
    // head = deleteFirst(head);
    // rPrint(head);
    // cout << "List after deleting last node:" << endl;
    // head = deleteLast(head);
    // rPrint(head);
    cout << "Enter data to be searched:" << endl;
    cin >> data;
    int result = searchInDoubly(head, data);
    cout << result << endl;
    return 0;
}