#include<bits/stdc++.h>
#define maxre 100005
#define ll long long
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

ll query(int n,int s,int e,int i){
    if(s>i)return tree[n];
    if(e<=i) return 0;
    int left=n*2;
    int right=n*2+1;
    int mid=(s+e)/2;
    ll p1=query(left,s,mid,i);
    ll p2=query(right,mid+1,e,i);
    return p1+p2;
}
void update(int n,int s,int e,int i){
     if (i>e||i<s)
        return;
    if (s>=i&&e<=i) {
        tree[n]=1;
        return;
    }
    int left=n*2;
    int right=n*2+1;
    int mid=(s+e)/2;
    update(left,s,mid,i);
    update(right,mid+1,e,i);
    tree[n]=tree[left]+tree[right];
}
int main(){
int n,m;cin>>n;
for(int i=1;i<=n;i++){
    cin>>arr[i];
}
creTree(1,1,n);
//for(int i=1;i<n*3;i++)cout<<tree[i]<<" ";cout<<endl;
for(int i=1;i<=n;i++){
    cout<<query(1,1,n,arr[i])<<endl;
    update(1,1,n,arr[i]);
    //for(int i=1;i<n*3;i++)cout<<tree[i]<<" ";cout<<endl;

}


return 0;
}
