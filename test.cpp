#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
Node *Begin(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    head = new_node;
    new_node->next = head;
}
Node *insertBegin(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    head->next = new_node;
    new_node->next = head;
    head = new_node;
}
void rPrint(Node *head)
{ // Print singly linked list
    if (head == NULL)
    {
        return;
    }
    cout << (head->data) << " ";
    Node *print = head->next;
    while (print != head)
    {
        print = print->next;
        cout << (print->data) << " ";
    }
    // cout << (head->data) << " ";
    // rPrint(head->next);
}
Node *deleteKth(Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    int pos = 1;
    Node *curr = head;
    while (pos != key - 1)
    {
        curr = curr->next;
        pos++;
    }
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
int main()
{
    Begin(5);
    insertBegin(10);
    insertBegin(33);
    insertBegin(50);
    // head = deleteKth(head, 50);
    rPrint(head);
    return 0;
}