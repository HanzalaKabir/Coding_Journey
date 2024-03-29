#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}
int main()
{
    struct node *root = new node(10);
    root->left = new node(6);
    root->right = new node(8);
    root->right->right = new node(7);
    root->right->right->left = new node(11);
    root->right->right->right = new node(12);
    int res = height(root);
    cout << res;
    return 0;
}