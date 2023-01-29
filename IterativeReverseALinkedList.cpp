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
node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    head = reverse(head);
    cout << "Reversed list is:" << endl;
    rPrint(head);
    return 0;
}