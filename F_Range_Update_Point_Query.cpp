#include<bits/stdc++.h>
#define maxre 100005
#define ll long long
#define Fast_io     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
ll arr[maxre],tree[maxre*3];
void creTree(int n,int s,int e){
    if(s==e){
        tree[n]=0;
        return;
    }
    int left=n*2;
    int right=n*2+1;
    int mid=(s+e)/2;
    creTree(left,s,mid);
    creTree(right,mid+1,e);
    tree[n]=tree[left]+tree[right];
}

ll query(int n,int s,int e,int i,int j){
    if(s>j||e<i)return 0;
    if(s>=i&&e<=j)return tree[n];
    int left=n*2;
    int right=n*2+1;
    int mid=(s+e)/2;
    ll p1=query(left,s,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int n,int s,int e,int i,int x){
     if (i>e||i<s)
        return;
    if (s>=i&&e<=i) {
        tree[n]+=x;
        return;
    }
    int left=n*2;
    int right=n*2+1;
    int mid=(s+e)/2;
    update(left,s,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[n]=tree[left]+tree[right];
}
int main(){
Fast_io;
int t;cin>>t;
while(t--){
int n,q;cin>>n>>q;
creTree(1,1,n);
vector<int>v(n);
for(int i=0;i<n;i++)cin>>v[i];
while(q--){
    int c,l;cin>>c>>l;
    if(c==1){
        int r;cin>>r;
        // update(1,1,n,l,1);
        // if(r+1<=n)
        // update(1,1,n,r+1,-1);
    }
    // else{
    //     int nu=query(1,1,n,1,l);
    //     int num=v[l-1];
    //     while (nu>0&&num>9){
    //         int su=0;
    //         while (num>0){
    //             su+=num%10;
    //             num/=10;
    //         }
    //         nu--;
    //         num=su; 
    //     }
    //     cout<<num<<endl;
        
    // }
}
}
return 0;
}
