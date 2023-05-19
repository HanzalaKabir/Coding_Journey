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
    int data;
    node *left;
    node *right;
};
node *newNode(int val)
{
    node *temp = new node;
    temp->data = val;
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
bool search(node *root, int num)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == num)
    {
        return true;
    }
    bool res = search(root->left, num);
    if (res)
    {
        return true;
    }
    bool res2 = search(root->right, num);
    return res2;
}

node *LCA(node *root, int n1, int n2)
{
    vector<node *> temp1, temp2;
    queue<node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *curr = q.front();
            q.pop();
            if (search(curr, n1))
            {
                temp1.push_back(curr);
            }
            if (search(curr, n2))
            {
                temp2.push_back(curr);
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    int size = min(temp1.size(), temp2.size());
    node *curr;
    for (int i = 0; i < size; i++)
    {
        if (temp1[i]->data == temp2[i]->data)
        {
            curr = temp1[i];
        }
        else
        {
            break;
        }
    }
    return curr;
}

int main()
{
    string s;
    getline(cin, s);
    node *root = buildTree(s);
    int n1, n2;
    cin >> n1 >> n2;
    node *res = LCA(root, n1, n2);
    cout << res->data;
    return 0;
}