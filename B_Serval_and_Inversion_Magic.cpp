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
        string str;cin>>str;
        int flag=false,ans=true,ans2=true;
        for(int i=0,j=n-1;i<j;i++,j--){
            if(str[i]==str[j]&&flag){
                ans=false;
            }
            else if(str[i]!=str[j]&&!ans){
                ans2=false;
                break;
            }
            else if(str[i]!=str[j])flag=true;
        }
        if(ans2)cout<<"Yes\n";
        else cout<<"No";
    }
    
    return 0;
}
