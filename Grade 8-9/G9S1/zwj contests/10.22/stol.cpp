#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct seg{
	int left,right;
}a[410][410][210];
int cnt[410][410];
int merge(int l,int r){
//	cout<<"merge "<<l<<ends<<r<<endl;
	short vis1[410]={0},vis2[410]={0},vis[410]={0};int i,j;
	for(i=1;i<=cnt[l][r-1];i++){
//		cout<<a[l][r-1][i].left<<ends<<a[l][r-1][i].right<<endl;system("pause");
		for(j=a[l][r-1][i].left;j<=a[l][r-1][i].right;j++){
			vis1[j]=1;
//			cout<<"	tp1 "<<i<<ends<<j<<endl;system("pause");
		} 
	}
	for(i=1;i<=cnt[r][r];i++){
//		cout<<a[r][r][i].left<<ends<<a[r][r][i].right<<endl;system("pause");
		for(j=a[r][r][i].left;j<=a[r][r][i].right;j++){
			vis2[j]=1;
//			cout<<"	tp2 "<<i<<ends<<j<<endl;system("pause");
		} 
	}
//	cout<<"half"<<endl;
	for(i=1;i<=m;i++) vis[i]=vis1[i]&&vis2[i];
//	for(i=1;i<=m;i++) cout<<vis[i];cout<<endl;
	int p1=1,p2=1,ans=0;vis[m+1]=2;
	while(p2<m){
		while(!vis[p1]) p1++,p2++;
		if(p1==m+1) break;
		while(vis[p2+1]==1) p2++;
//		cout<<"added "<<p1<<ends<<p2<<endl;//system("pause");
		cnt[l][r]++;a[l][r][cnt[l][r]].left=p1;a[l][r][cnt[l][r]].right=p2;ans=max(ans,p2-p1+1);
		p1=++p2;
	}
//	cout<<"finished "<<ans<<endl;
	return ans;
}
int main(){
	freopen("stol.in","r",stdin);
	freopen("stol.out","w",stdout);
	int i,j,k,l,r,ans=0;char s[410];
	cin>>n>>m;
	for(i=1;i<=n;i++){
//		cout<<i<<endl;
		for(l=1;l<=m;l++) cin>>s[l];
		l=0;r=0;
		while(r<m){
//			cout<<"	before "<<l<<ends<<r<<endl;
			while(s[l]!='.') l++,r++;
			if(l==m+1) break;
//			cout<<"	middle "<<l<<ends<<r<<endl;
			while(s[r+1]=='.') r++;
//			cout<<"	after "<<l<<ends<<r<<endl;
			cnt[i][i]++;a[i][i][cnt[i][i]].left=l;a[i][i][cnt[i][i]].right=r;ans=max(ans,((r-l+2)<<1)-1);
			l=++r;
		}
	}
//	for(i=1;i<=n;i++){
//		cout<<i<<endl;
//		for(j=1;j<=cnt[i][i];j++) cout<<"	"<<a[i][i][j].left<<ends<<a[i][i][j].right<<endl;
//	}
//	cout<<ans<<endl;
	for(k=2;k<=n;k++){
		for(i=1;i<=n-k+1;i++){
			j=i+k-1;
			int tmp=merge(i,j);
			if(tmp==0) continue;
			ans=max(ans,(tmp<<1)+(k<<1)-1);
//			cout<<i<<ends<<j<<ends<<ans<<endl;
		}
	}
	printf("%d",ans);
}
