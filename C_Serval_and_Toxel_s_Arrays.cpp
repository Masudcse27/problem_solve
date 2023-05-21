#include <bits/stdc++.h>
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)


void solve() {
   
}

int main() {

    int t = 1;

    Fast_io;

    cin >> t;
    while (t--) {
        int n,m;cin>>n;
        vector<int>v[n+m+1],ans(m+2,0);
        for(int i=0;i<n;i++){
            int a;cin>>a;
            cout<<a<<endl;
            v[a].push_back(1);
        }
        // ans[0]=n;
        // for(int i=2;i<=m+1;i++){
        //     int pi,vi;cin>>pi>>vi;
        //     // for(auto x:v[vi]){
        //     //     ans[x]+=1;
        //     // }
        // }
         long long res=0;
        // // for(int i=1;i<=m;i++){
        // //     res+=(n+m)-ans[i]-i;
        // // }
        cout<<res<<endl;
    }
    
    return 0;
}
