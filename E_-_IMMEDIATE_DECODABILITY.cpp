#include<iostream>
#include<string.h>
#include <vector>
using namespace std;

const int mx = 2;
struct Trie{
    struct Trie *chi[mx];
    bool flag;
};
void create(string str,struct Trie *root){
    struct Trie *node= root;
    for(int i=0;i<str.size();i++){
        int ind=str[i]-'0';
        if(!node->chi[ind]){
            struct Trie *newnode=new Trie;
            for(int i=0;i<mx;i++)newnode->chi[i]=NULL;
            newnode->flag= false;
            node->chi[ind]=newnode;
        }
        node=node->chi[ind];
        //cout<<ind<<" ";
    }
   // cout<<endl;
    node->flag=true;
}
int Search_str(struct Trie *root,string str){
    struct Trie *node=root;
    //int cnt=0;
    for(int i=0;i<str.size();i++){
        int a=str[i]-'0';
        if(!node->chi[a]){
            int flag=false;
            for(int j=0;j<mx;j++){
                if(node->chi[j]){
                    //cout<<a<<" "<<j<<endl;
                    flag=true;break;
                }
            }
            return flag;
        }
        node=node->chi[a];
    }
    return false;
}
void solve() {
    string str;
    vector<string> v;
    int cas=1;
    while (cin>>str){
        if(str!="9"){
            v.push_back(str);
            continue;
        }
        Trie *trie=new Trie;
        for(int i=0;i<mx;i++)trie->chi[i]=NULL;
        trie->flag= false;
        create(v[0],trie);
        int flag=true;
        for(int i=1;i<v.size();i++){
            flag=Search_str(trie,v[i]);
            if(!flag)break;
            create(v[i],trie);
        }
        if(flag)cout<<"Set "<<cas++<<" is immediately decodable\n";
        else cout<<"Set "<<cas++<<" is not immediately decodable\n";
        v.clear();
    }
    
}

int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    //int n;
    while (t--) {
        //cout << "Case " << c++ << ": ";
        solve();
    }
    return 0;
}
