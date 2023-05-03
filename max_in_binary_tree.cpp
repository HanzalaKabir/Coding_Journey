#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int size(node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    if (root != NULL)
    {
        return max(root->key, max(size(root->left), size(root->right)));
    }
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << (root->key) << " ";
    }
}
int main()
{
    node *root = new node(50);
    root->left = new node(20);
    root->left->left = new node(80);
    postOrder(root);
    cout << endl;
    cout << size(root);
    return 0;
}