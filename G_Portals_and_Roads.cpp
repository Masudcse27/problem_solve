#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/
ll dp[1000][1000][100];
ll minCost(int s,int e,vector<ll>&v,int r,int hol){
    //cout<<s<<" "<<e<<" "<<hol<<" "<<r<<endl;
    if(s>e)return INT_MAX;
    if(r==0)return v[e]-v[s];
     if(r<0||s>=e||hol<0)return INT_MAX;
    //else if(hol<=0)return INT_MAX;
    if(dp[s][e][r]!=-1)return dp[s][e][r];
    ll ans=LONG_LONG_MAX;
    cout<<s<<" p "<<e<<" p "<<hol<<endl;
    for(int i=s;i<=e;i++){
        //if(r>=(i-s))
        ans=min(ans,v[i]-v[s]+minCost(i+1,e,v,r-(i-s),hol-1));

        cout<<s<<" "<<i<<" "<<hol<<" "<<r<<" "<<ans<<endl;
    }
    
    return dp[s][e][r]=ans;
}
void run(){
   int n,r;cin>>n>>r;
   memset(dp,-1,sizeof(dp));
   vector<int>v(n+1);
   for(int i=1;i<=n;i++){
    cin>>v[i];
   }
   vector<ll>sum(n+1,0);
   for(int i=2;i<=n;i++){
    sum[i]=abs(v[i]-v[i-1])+sum[i-1];
   }
   for(auto x:sum)cout<<x<<" ";cout<<endl;
   cout<<minCost(1,n,sum,r,(n-r-1)*2)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
    run();
    }
}
