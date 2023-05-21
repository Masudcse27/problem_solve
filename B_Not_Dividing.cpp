#include <bits/stdc++.h>
using namespace std;
/// Typedef
typedef long long           LL;
typedef vector<int>         vi;
typedef pair<int,int>       pii;
#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 

int main() {
    int t = 1;

    Fast_io;

    cin >> t;
    int c = 1;
    int n;
    while (t--) {
        int n;cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        if(arr[0]==1)arr[0]=2;
        for(int i=1;i<n;i++){
            if(arr[i]==1)arr[i]=2;
            if(arr[i]%arr[i-1]==0)arr[i]++;
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}