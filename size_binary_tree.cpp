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
int getSize(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + getSize(root->left) + getSize(root->right);
    }
}
int main()
{
    node *root = NULL;
    return 0;
}