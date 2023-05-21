#include <iostream>
#define ll long long
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)



void solve(ll &n,ll &m) {
   int ans=1;
   if(n<m)swap(n,m);
   while (n>0&&m>0){
    if(n%m==0||n/m>1)break;
    n%=m;
    swap(n,m);
    ans++;
    ans%=2;
   }
   if(ans)cout<<"Stan wins\n";
   else cout<<"Ollie wins\n";
}

int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    //int c = 1;
    ll n,m;
    while (cin>>n>>m) {
        if(n==0&&m==0)break;
        //cout << "Case " << c++ << ": ";
        solve(n,m);
    }
    return 0;
}
