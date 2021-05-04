#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define For(i) for((i)=0;(i)<n;(i)++)
#define Rfor(i,n) for((i)=(n-1);(i)>=0;(i)--)
#define Cfor(i,a,b) for((i)=(a);(i)<(b);(i)++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int> > vp;
typedef long long int ll;
typedef long double ld;
struct node
{
    int value;
    //int height;
    node *left;
    node *right;
}*root=NULL;
node* new_node(int x)
{
    node *temp=new node;
    temp->value=x;
    temp->right=NULL;
    temp->left=NULL;
    //temp->height=1;
    return temp;
}
/*int get_height(node *curr)
{
    if(curr=NULL)
        return 0;
    return curr->height;
}*/

void tree_insert(int x)
{
    if(root==NULL)
    {
        root=new_node(x);
        return ;
    }
    node *curr=root;
    while(1)
    {
    if(curr->value<x)
    {
        if(curr->right==NULL)
        {
            curr->right=new_node(x);
            return ;
        }
        else
            curr=curr->right;
    }
    else
    {
        if(curr->left==NULL)
        {
            curr->left=new_node(x);
            return ;
        }
        else
            curr=curr->left;
    }
    }
}
void tree_traverse(node* curr)
{
    cout<<curr->value<<" ";
    if(curr->left!=NULL)
        tree_traverse(curr->left);
    if(curr->right!=NULL)
        tree_traverse(curr->right);
    return;
}
int main()
 {
    /*ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int i,n,x;
    cin>>n;
    For(i)
    {
        cin>>x;
        tree_insert(x);
    }
    tree_traverse(root);
    return 0;
}
