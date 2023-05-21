#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[10005];
ll fn(int n){
    if(arr[n]!=-1)return arr[n];
     return arr[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
}
int main(){
int t,cas=1;cin>>t;
while (t--){
 int n;
 memset(arr,-1,sizeof(arr));
 for(int i=0;i<=5;i++)cin>>arr[i];
 cin>>n;
 cout<<"Case "<<cas++<<": ";
 cout<<fn(n)%10000007<<endl;
}
return 0;
}
