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
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i&&__gcd(arr[i],arr[j])<=2){
                    ans=true;break;
                }
            }
            if(ans)break;
        }
        if(ans)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
