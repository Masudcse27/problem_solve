#include <iostream>
#include <vector>
using namespace std;

#define Fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

void solve(int &n) {
    vector<int>a(n+5),b(n+5,0),c(n+5,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,j=n;i<=n;i++,j--){
        b[i]=b[i-1]^a[i];
        c[j]=a[j]^c[j+1];
    }
    int ans=0;
    // if(b[n-2]<a[n-1])ans++;
    // if(c[1]<a[0])ans++;
    for(int i=1;i<=n;i++){
        if((b[i-1]^c[i+1])<a[i])ans++;
    }
    if(b[n]==0)ans=0;

    cout<<ans<<endl;
}

int main() {

    int t = 1;

    //Fast_io;

    //cin >> t;
    int c = 1;
    int n;
    while (scanf("%d",&n)) {
        if(n==0)break;
        //cout << "Case " << c++ << ": ";
        solve(n);
    }
    return 0;
}
