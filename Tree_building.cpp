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

// Tree Node
struct node
{
    int data;
    node *left;
    node *right;
};
vector<int> preorder(struct node *root);

// Utility function to create a new Tree Node
node *newNode(int val)
{
    node *temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
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

int main()
{
    string s;
    getline(cin, s);
    node *root = buildTree(s);
    vector<int> res = preorder(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}

// Function to return a list containing the preorder traversal of the tree.
void trav(vector<int> &res, node *root)
{
    if (!root)
    {
        return;
    }
    res.push_back(root->data);
    trav(res, root->left);
    trav(res, root->right);
}

vector<int> preorder(node *root)
{
    vector<int> res;
    trav(res, root);
    return res;
}
