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
};
node *newNode(int val)
{
    node *temp = new node;
    temp->key = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'n')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;

    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "n")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "n")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
int printLevel(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int size = 0;
    while (q.size() > 1)
    {
        node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        size++;
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    return size;
}

int sum(node *root, int check)
{
    if (check == 1)
    {
        if (root != NULL)
        {
            if (root->left == NULL && root->right != NULL)
            {
                if (root->right->key == root->key)
                {
                    check = sum(root->right, check);
                    if (check != 1)
                    {
                        return 0;
                    }
                }
                else
                {
                    check = 0;
                    check = sum(root->right, check);
                }
            }
            if (root->right == NULL && root->left != NULL)
            {
                if (root->left->key == root->key)
                {
                    check = sum(root->left, check);
                    if (check != 1)
                    {
                        return 0;
                    }
                }
                else
                {
                    check = 0;
                    check = sum(root->left, check);
                }
            }
            if (root->left != NULL && root->right != NULL)
            {
                if (root->key == root->left->key + root->right->key)
                {
                    check = sum(root->left, check);
                    if (check != 1)
                    {
                        return check;
                    }
                    check = sum(root->right, check);
                    if (check != 1)
                    {
                        return check;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
        if (root == NULL)
        {
            return check;
        }
    }
    else
    {
        return check;
    }
}
int main()
{
    string s;
    getline(cin, s);
    node *root = buildTree(s);
    int size = printLevel(root);
    cout << endl
         << size;
    int res = sum(root, 1);
    cout << endl
         << res;
    return 0;
}