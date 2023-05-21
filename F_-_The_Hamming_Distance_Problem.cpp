#include<bits/stdc++.h>
using namespace std;
int n,m;
void pre(string str,int i,int c){
    if(i==n){
        if(c==m)cout<<str<<endl;
        return;
    }
    pre(str,i+1,c);
    str[i]='1';
    pre(str,i+1,c+1);
}
int main(){
 int t;cin>>t;
 while(t--){
    cin>>n>>m;
    string str="";
    for(int i=0;i<n;i++)str+='0';
    pre(str,0,0);
    if(t)cout<<endl;
 }
}
