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
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << (root->data) << " ";
        inOrder(root->right);
    }
}
// Implementation of  inorder for getting tree elements:
//  void trav(vector<int> &res, Node *root){
//          if(!root){
//          return;
//      }
//      trav(res, root->left);
//      res.push_back(root->data);
//      trav(res,root->right);
//      }
//      vector<int> inOrder(Node* root) {
//          Your code here
//          vector<int> res;
//          trav(res,root);
//          return res;
//      }
void preOrder(node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}
/*Implementation of preorder for getting tree elements:
void trav(vector<int> &res, Node *root){
    if(!root){
        return;
    }
    res.push_back(root->data);
    trav(res, root->left);
    trav(res,root->right);
}

vector <int> preorder(Node* root)
{
  vector<int> res;
  trav(res,root);
  return res;
}
*/
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << (root->data) << " ";
    }
}
int main()
{
    string s;
    getline(cin, s);
    node *root = buildTree(s);
    inOrder(root);
}