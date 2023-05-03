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
bool isIdentical(node *r1, node *r2)
{
    // Your Code here
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
    {
        return false;
    }
    queue<node *> q1;
    q1.push(r1);
    queue<node *> q2;
    q2.push(r2);
    while (q1.empty() == false && q2.empty() == false)
    {

        int count1 = q1.size();
        int count2 = q2.size();
        vector<int> vec1;
        for (int j = 0; j < count1; j++)
        {
            node *temp = q1.front();
            vec1.push_back(temp->data);
            q1.pop();
            if (temp->left != NULL)
            {
                q1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q1.push(temp->right);
            }
        }
        vector<int> vec2;
        for (int j = 0; j < count2; j++)
        {
            node *temp = q2.front();
            vec2.push_back(temp->data);
            q2.pop();
            if (temp->left != NULL)
            {
                q2.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q2.push(temp->right);
            }
        }
        if (vec1 == vec2)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    if (q1.empty() == true && q2.empty() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s;
    getline(cin, s);
    node *root1 = buildTree(s);
    string r;
    getline(cin, r);
    node *root2 = buildTree(r);
    bool check = isIdentical(root1, root2);
    if (check == true)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}