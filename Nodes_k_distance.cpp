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
    int data;
    node *left;
    node *right;
    node(int k){
        data=k;
        left=right=NULL;
    }
};
void Distance(node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    else{
        Distance(root->left,k-1);
        Distance(root->right,k-1);
    }
}
int main()
{
struct node *root=new node(10);
root->left=new node(6);
root->right=new node(8);
root->right->right=new node(7);
root->right->right->left=new node(11);
root->right->right->right=new node(12);
Distance(root,3);
return 0;
}