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
    node(int k){
        key=k;
        left=right=NULL;
    }
};

void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << (root->key) << " ";
        inOrder(root->right);
    }
}
void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preOrder(root->left);
        preOrder(root->right);
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
    node *root=NULL;
    return 0;
}