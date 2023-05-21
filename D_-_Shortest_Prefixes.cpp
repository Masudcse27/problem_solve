#include<iostream>
#include<string.h>
#include <vector>
using namespace std;
#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int mx = 27;
struct Trie{
    Trie *chi[mx];
    int sum;
    bool flag;
};
void create(string str,struct Trie *root){
    struct Trie *node= root;
    for(int i=0;i<str.size();i++){
        int ind=str[i]-'a';
        if(!node->chi[ind]){
            struct Trie *newnode=new Trie;
            for(int i=0;i<mx;i++)newnode->chi[i]=NULL;
            newnode->sum=0;
            newnode->flag=false;
            node->chi[ind]=newnode;
            //cout<<newnode<<"  pp";
        }
        //cout<<node->chi[ind]<<"\n";
        node=node->chi[ind];
        node->sum+=1;
        //cout<<ind<<node->sum<<" ";
        //cout<<ind<<" ";
    }
    //cout<<endl;
    node->flag=true;
}
int Search_str(struct Trie *root,string str){
    struct Trie *node=root;
    int ans=str.size();
    for(int i=0;i<str.size();i++){
        int a=str[i]-'a';
        if(node->sum==1){
            return i;
        }
        node=node->chi[a];
    }
    return str.size();
}
void solve() {
    //int n;cin>>n;
    vector<string>v;
    string str;
    int flag=true;
    Trie *trie=new Trie;
    for(int i=0;i<mx;i++)trie->chi[i]=NULL;
    trie->flag=false;
    trie->sum=0;
    while (cin>>str){
        //cin>>str;
        create(str,trie);
        v.push_back(str);
        //cout<<i<<endl;
        //i++;
    }
    for(int i=0;i<v.size();i++){
        int len=Search_str(trie,v[i]);
        cout<<v[i]<<" "<<v[i].substr(0,len)<<endl;
    }
    
}

int main() {

    int t = 1;

    Fast_io;

    //cin >> t;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
