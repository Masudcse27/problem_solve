#include<bits/stdc++.h>
using namespace std;
int n,m;
void pre(string str,int i,int c){
    if(i<0){
        //if(c==m)cout<<str<<endl;
        return;
    }
    str[i]='0';
    pre(str,i-1,c);
    str[i]='1';
    pre(str,i-1,c+1);
    if(c==m-1)
    cout<<str<<endl;
}
int main(){
 int t;cin>>t;
 while(t--){
    cin>>n>>m;
    string str="";
    for(int i=0;i<n;i++)str+='0';
    pre(str,n-1,0);
    if(t)cout<<endl;
 }
}
