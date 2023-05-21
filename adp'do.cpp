#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
string str,str2;
map<char,int>gry,y;
map<int,int>gn;
set<char>st,st2;
for(int i=0;i<n;i++){
    cin>>str>>str2;
    //cout<<str<<" "<<str2<<endl;
    for(int j=0;j<5;j++){
        if(str2[j]=='-'){
            gry[str[j]]++;
        }
        else if(str2[j]=='Y'){
            st.insert(str[j]);
            y[str[j]]++;
        }
        else{
            int a=(int)str[j];
            gn[j]=a;
            st.insert(str[j]);
            y[str[j]]++;
            //cout<<a<<" ";
        }
    }
    //cout<<endl;
}
    set<string>ans;
    for(int i=0;i<m;i++){
        cin>>str;
        int flag=true;
        for(int j=0;j<5;j++){
            int a=str[j];
            if(gn[j]&&gn[j]!=a){
                //cout<<i<<" "<<j<<endl;
                //cout<<gn[j]<<"gn"<<a<<endl;
                flag=false;
                break;
            }
            else if(y[str[j]]) {
                st2.insert(str[j]);
            }
        }
//        if(flag){
//        for(auto x:st)cout<<x;cout<<endl;
//        for(auto x:st2)cout<<x;cout<<endl;
//        }
        if(flag&&st==st2){
            cout<<str<<endl;
            ans.insert(str);
        }
        st2.clear();
    }
     cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<endl;
    }
return 0;
}
