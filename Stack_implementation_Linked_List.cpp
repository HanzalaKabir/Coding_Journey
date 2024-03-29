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
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct MyStack
{
    node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int x)
    {
        node *temp = new node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
        {
            return INT_MAX;
        }
        int res = head->data;
        node *temp = head;
        head = head->next;
        delete (temp);
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    int peek()
    {
        if (head == NULL)
        {
            return INT_MAX;
        }
        return head->data;
    }
};

int main()
{

    return 0;
}