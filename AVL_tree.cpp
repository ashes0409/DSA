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
    int height;
    node *left;
    node *right;
}*root=NULL;
node* new_node(int x)
{
    node *temp=new node;
    temp->value=x;
    temp->right=NULL;
    temp->left=NULL;
    temp->height=1;
    return temp;
}
int get_height(node* curr)
{
    if(curr==NULL)
        return 0;
    return curr->height;
}
int get_balance(node* curr)
{
    if(curr==NULL)
        return 0;
    return get_height(curr->left)-get_height(curr->right);
}
node* LR(node* curr)
{
    node* temp=curr->right;
    curr->right=temp->left;
    temp->left=curr;
    curr->height=max(get_height(curr->left),get_height(curr->right))+1;
    temp->height=max(get_height(temp->left),get_height(temp->right))+1;
    return temp;
}
node* RR(node* curr)
{
    node* temp=curr->left;
    curr->left=temp->right;
    temp->right=curr;
    curr->height=max(get_height(curr->left),get_height(curr->right))+1;
    temp->height=max(get_height(temp->left),get_height(temp->right))+1;
    return temp;
}
node* tree_insert(int x,node* curr)
{
    if(curr==NULL)
        return new_node(x);
    if (x<curr->value)
        curr->left=tree_insert(x,curr->left);
    else if(x>curr->value)
        curr->right=tree_insert(x,curr->right);
    else
        return curr; //AVL trees do not accept repeated values

    //update height and check balance
    curr->height=max(get_height(curr->left),get_height(curr->right))+1;
    int balance=get_balance(curr);

    // Left Left Case
    if (balance>1 && x<curr->left->value)
        return RR(curr);

    // Right Right Case
    if (balance<-1 && x>curr->right->value)
        return LR(curr);

    // Left Right Case
    if (balance>1 && x>curr->left->value)
    {
        curr->left = LR(curr->left);
        return RR(curr);
    }

    // Right Left Case
    if (balance<-1 && x<curr->right->value)
    {
        curr->right=RR(curr->right);
        return LR(curr);
    }
    return curr;
}
void tree_traverse(node* curr)
{
    if(curr->left!=NULL)
        tree_traverse(curr->left);
    cout<<curr->value<<" ";
    if(curr->right!=NULL)
        tree_traverse(curr->right);
    return;
}
int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n,x;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        root=tree_insert(x,root);
    }
    tree_traverse(root);
    return 0;
}
