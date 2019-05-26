#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int ap[500005],a[1000005],al[1000005],ad[1000005],an=0;
int d1[500005],d2[500005];
bool t[500005];

void add(int x,int y,int l){
	an++; a[an]=y; al[an]=ap[x]; ap[x]=an;
} 

int main(){
	
	freopen ("track.in","r",stdin);
	freopen ("track.out","w",stdout);
    
    cin>>n>>m;
    bool t1=1,t2=0;//1ÎªÁ´£¬2Îª²æ 
    
    for(int i=1,a1,b1,l;i<=n;i++){
    	cin>>a1>>b1>>l;
    	if(a1!=1) t1=0;
    	if(b1!=a1+1) t2=1;
    	if(t1) d1[b1]=l;
    	if(t2) d2[b1]=l;
    	add(a1,b1,l);
    	add(b1,a1,l);
    }
    
    if(t1){
    	d1[1]=0;
    	long long cnt,l=0,r=n*10000,mid,sum;
		while(l<r){
			cnt=0;
			sum=0;
			mid=(l+r)>>1+1;
			for(int i=1;i<=n;i++){
				sum+=d1[i];
				if(sum>=mid){
					sum=0; cnt++;
				}
			}
			if(cnt>=mid) l=mid;
			else r=mid-1;
		}
		cout<<l;
    }
    else if(t2){
    	d2[1]=0;
    	sort(d2+1,d2+n+1);
    	long long cnt,l=0,r=n*10000,mid;
		int mi=1000000;
		while(m>(n-1)/2){
			mi=min(mi,d2[n]);
			n--;
			m--;
	    }
		for(int i=1,l=2+(2*n-2-m),r=n;i<=m;i++,l++,r--)
		mi=min(mi,d2[l]+d2[r]);
		cout<<mi;
    }
    else if(m==1){
    	
    }
    else{
    	long long sum=0;
    	for(int i=1;i<=an;i++) sum==ad[i];
    	sum=sum>>1;
    	sum/=m;
    	cout<<sum;
    }
}
