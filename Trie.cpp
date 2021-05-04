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
char str[1000];
struct Trie_node
{
    Trie_node* c[26]={NULL};
    bool ec=0;
}*root=NULL;
Trie_node* new_node()
{
    Trie_node *temp=new Trie_node;
    return temp;
}
int ctoi(char ch)
{
    return ch-'a';
}
void Trie_insert(Trie_node* curr,string &s,int i)
{
    if(i==s.size())
    {
        curr->ec=1;
        return ;
    }
    if(curr->c[ctoi(s[i])]==NULL)
        curr->c[ctoi(s[i])]=new_node();
    Trie_insert(curr->c[ctoi(s[i])],s,i+1);
}
void max_match(Trie_node* root,string &p)
{
    Trie_node* curr=root;
    int i=0;
    while(i<p.size() && curr->c[ctoi(p[i])]!=NULL)
    {
        cout<<p[i];
        curr=curr->c[ctoi(p[i])];
        i++;
    }
    cout<<"\n";
    return ;
}
Trie_node* next_pos(Trie_node* root,string &p,int &pos,char &ch)
{
    Trie_node* curr=root;
    Trie_node* temp;
    int j,i=0;
    while(i<p.size())
    {
        for(j=ctoi(p[i])+1;j<26;j++)
        {
            if(curr->c[j]!=NULL)
            {
                pos=i;
                temp=curr->c[j];
                ch=j+'a';
                break;
            }
        }

        if(curr->c[ctoi(p[i])]!=NULL)
        {
            curr=curr->c[ctoi(p[i])];
            i++;
            if(i==p.size())
            {
                for(j=0;j<26;j++)
                {
                    if(curr->c[j]!=NULL)
                    {
                        pos=i;
                        temp=curr->c[j];
                        ch=j+'a';
                        break;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    return temp;
}
void print_first(Trie_node* root)
{
    if(root->ec==1)
        return ;
    for(int i=0;i<26;i++)
    {
        if(root->c[i]!=NULL)
        {
            cout<<char(i+'a');
            print_first(root->c[i]);
            return ;
        }
    }
}
void successor(Trie_node* root,string &p)
{
    int pos=-1;
    char ch;
    Trie_node* last=next_pos(root,p,pos,ch);
    if(pos==-1)
    {
        cout<<"No successor\n";
        return ;
    }
    cout<<p.substr(0,pos)<<ch;
    print_first(last);
    cout<<"\n";
    return ;
}
void Trie_traverse(Trie_node* curr,int pos)
{
    if(curr->ec==1)
    {
        str[pos]='\0';
        cout<<str<<"\n";
    }
    for(int i=0;i<26;i++)
    {
        if(curr->c[i]!=NULL)
        {
            str[pos]=i+'a';
            Trie_traverse(curr->c[i],pos+1);
        }
    }
    return ;
}

int main()
 {
    /*ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    int i,n,m;
    cin>>n>>m;
    string s;
    root=new_node();
    for(i=1;i<=n;i++)
    {
        cin>>s;
        Trie_insert(root,s,0);
    }
    /*Trie_traverse(root,0);
    cout<<"\n";*/
    string p;
    while(m--)
    {
        cin>>p;
        successor(root,p);
    }
    return 0;
}
