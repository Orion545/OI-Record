#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[110];
int del[110];
int deleted=0;
int cf=0;
int shangxian=0;
map<int,int> m;

int search(int indexx){
	if (m.find(indexx)!=m.end()){
		return m[indexx];
	}
	return 0;
}

void digui(int pos,int csum){
	if (pos==n+1) return;
	if (del[pos]) digui(pos+1,csum);
	vector<int> v;
	for (int i=0;csum+a[pos]*i<shangxian;i++){
		int tmp=csum+a[pos]*i;
		if (tmp>a[pos]&&tmp!=a[pos]) {
			del[search(tmp)]=1;
		}
		v.push_back(tmp);
	}
	for (int i=0;i<v.size();i++){
		digui(pos+1,v[i]);
	}
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin>>T;
	a[0]=-1;
	while (T--){
		m.clear();
		memset(del,0,sizeof(del));
		deleted=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if (n==1||a[1]==1){
			cout<<1<<endl;
			continue;
		}
		shangxian=a[n]+1;
		for (int i=1;i<=n;i++) {
			m[a[i]]=i;
			if (a[i]>=shangxian) del[i]=1;
		}
	
		
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++){
				if (a[j]%a[i]==0) del[j]=1;
			}
		
		digui(1,0);
		
		for (int i=1;i<=n;i++) {
			if (del[i]) {
				deleted++;
			}
		}
		
		cout<<n-deleted<<endl;
	}
	return 0;
}
