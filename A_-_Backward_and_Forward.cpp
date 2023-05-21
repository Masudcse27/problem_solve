//Tasnia Ahmed Tisha
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
   int t;cin>>t;
   while (t--){
        int n,m,k;
        cin>>n;
        vector<ll>a1(n+5);
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }
        cin>>m;
        vector<ll>a2(m+5);
        for(int i=0;i<m;i++){
            cin>>a2[i];
        }
        cin>>k;
        vector<ll>a3(k+5);
        for(int i=0;i<k;i++){
            cin>>a3[i];
        }
        vector<ll>ans1(100005,0);
        int j=0;
        for(int i=m-1;i>=0;i--){
            while(j>=i){
                if(a3[j]<a2[i]){
                    j++
                    break;
                }
                j--;
            }
            ans1[i]+=ans1[i+1]+(k-j);
        }
        //cout<<ans1[m-1]<<endl;
         ll ans=0;
         j=0;
        for(int i=0;i<n;i++){
            j=max(j,i);
            while(j<m){
                if(a2[j]>=a1[i])break;
                j++;
            }
            if(j>0)ans+=ans1[m-1]-ans1[j-1];
            else ans+=ans1[m-1];
        }
        cout<<ans<<endl;
   }

    return 0;
}
