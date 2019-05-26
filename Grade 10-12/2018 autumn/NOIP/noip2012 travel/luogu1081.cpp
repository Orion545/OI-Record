/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,q,h[100010];
int mindis[100010],secdis[100010],minpos[100010],secpos[100010];
int sta[100010][20],suma[100010][20],sumb[100010][20];
int stb[100010][20];
struct node{
	int val,pos;
	inline bool operator <(const node &b)const{
		return val<b.val;
	}
};
set<node>s;
inline bool cmp(int l,int r){
	return h[l]<h[r];
}
int main(){
	n=read();int i,j;
	for(i=1;i<=n;i++){
		h[i]=read();
		s.insert((node){h[i],i});
	}
	set<node>::iterator l1,l2,r1,r2,cur;
	for(i=1;i<=n;i++){
		mindis[i]=secdis[i]=2e9+10;
		
		cur=s.find((node){h[i],i});
//		cout<<"getcur "<<cur->pos<<'\n';
		r1=++cur;
		if(r1!=s.end()){
			r2=++cur;
			cur--;
		}
		cur--;
//		cout<<"getcur "<<cur->pos<<'\n';
		if(cur!=s.begin()){
			l1=--cur;
			if(l1!=s.begin()){
				l2=--cur;
				cur++;
			}
			cur++;
		}
		
//		cout<<"find "<<i<<' '<<l1->pos<<' '<<l2->pos<<' '<<r1->pos<<' '<<r2->pos<<'\n';
		
		if(cur!=s.begin())   mindis[i]=min(mindis[i],abs(h[i]-h[l1->pos]));
		if(r1!=s.end()) mindis[i]=min(mindis[i],abs(h[i]-h[r1->pos]));
		
		if(cur!=s.begin()&&mindis[i]==abs(h[i]-h[l1->pos])) minpos[i]=l1->pos;
		else if(r1!=s.end()&&mindis[i]==abs(h[i]-h[r1->pos])) minpos[i]=r1->pos;
		
//		cout<<"ckpt1\n";
		
		if(cur!=s.begin()&&l1->pos!=minpos[i])
			secdis[i]=min(secdis[i],abs(h[i]-h[l1->pos]));
		if(cur!=s.begin()&&l1!=s.begin()) 
			secdis[i]=min(secdis[i],abs(h[i]-h[l2->pos]));
		
//		cout<<"ckpt2\n";
		
		if(r1!=s.end()&&r1->pos!=minpos[i])
			secdis[i]=min(secdis[i],abs(h[i]-h[r1->pos]));
		if(r1!=s.end()&&r2!=s.end()) 
			secdis[i]=min(secdis[i],abs(h[i]-h[r2->pos]));
		
//		cout<<"ckpt3\n";
		
		if(cur!=s.begin()&&l1->pos!=minpos[i]&&secdis[i]==abs(h[i]-h[l1->pos])) secpos[i]=l1->pos;
		else if(cur!=s.begin()&&l1!=s.begin()&&secdis[i]==abs(h[i]-h[l2->pos])) secpos[i]=l2->pos;
		else if(r1!=s.end()&&r1->pos!=minpos[i]&&secdis[i]==abs(h[i]-h[r1->pos])) secpos[i]=r1->pos;
		else if(r1!=s.end()&&r2!=s.end()&&secdis[i]==abs(h[i]-h[r2->pos])) secpos[i]=r2->pos;
		
//		cout<<"ckpt4\n";
		
		s.erase(cur);
	}
	
//	for(i=1;i<=n;i++) cout<<i<<' '<<mindis[i]<<' '<<minpos[i]<<' '<<secdis[i]<<' '<<secpos[i]<<'\n';
	
	stb[n-1][0]=n;sumb[n-1][0]=abs(h[n]-h[n-1]);
	for(i=n-2;i>0;i--){
		sta[i][0]=secpos[i];
		suma[i][0]=secdis[i];
		stb[i][0]=minpos[i];
		sumb[i][0]=mindis[i];
	}
		
	for(i=1;i<=n;i++){
		sta[i][1]=stb[sta[i][0]][0];
		suma[i][1]=suma[i][0];
		sumb[i][1]=sumb[sta[i][0]][0];
	}
	
	for(j=2;j<19;j++){
		for(i=1;i<=n;i++){
			sta[i][j]=sta[sta[i][j-1]][j-1];
			suma[i][j]=suma[i][j-1]+suma[sta[i][j-1]][j-1];
			sumb[i][j]=sumb[i][j-1]+sumb[sta[i][j-1]][j-1];
		}
	}
	
	int x0=read(),u;double tmpa,tmpb;
	int pos=0;double ratio=2e9+10;
	for(i=1;i<=n;i++){
		u=i;tmpa=0;tmpb=0;
		for(j=18;j>=0;j--){
			if(sta[u][j]&&suma[u][j]+(j?sumb[u][j]:0)+tmpa+tmpb<=x0){
//				cout<<"	trans "<<u<<' '<<j<<' '<<sta[u][j]<<' '<<suma[u][j]<<' '<<sumb[u][j]<<'\n';
				tmpa+=suma[u][j];
				tmpb+=(j?sumb[u][j]:0);
				u=sta[u][j];
			}
		}
		if(sta[u][0]&&tmpa+tmpb+suma[u][0]<=x0&&stb[u][0]&&tmpa+tmpb+sumb[u][0]<=x0){
			tmpb+=sumb[u][0];
			u=stb[u][0];
		}
		if(!tmpb){
			if((ratio==2e9+10||ratio==-1)&&h[pos]<h[i]) pos=i,ratio=-1; 
		}
		else{
			if(ratio==-1||ratio>(tmpa/tmpb)||(ratio==(tmpa/tmpb)&&h[pos]<h[i]))
				pos=i,ratio=(tmpa/tmpb);
		}
//		cout<<"getdis "<<i<<' '<<x0<<' '<<u<<' '<<tmpa<<' '<<tmpb<<' '<<ratio<<'\n';
	}
	printf("%d\n",pos);
	q=read();
	while(q--){
		u=read();x0=read();
		tmpa=0;tmpb=0;
		for(j=18;j>=0;j--){
			if(sta[u][j]&&suma[u][j]+(j?sumb[u][j]:0)+tmpa+tmpb<=x0){
//				cout<<"	trans "<<u<<' '<<j<<' '<<sta[u][j]<<' '<<suma[u][j]<<' '<<sumb[u][j]<<'\n';
				tmpa+=suma[u][j];
				tmpb+=(j?sumb[u][j]:0);
				u=sta[u][j];
			}
		}
		if(sta[u][0]&&tmpa+tmpb+suma[u][0]<=x0&&stb[u][0]&&tmpa+tmpb+sumb[u][0]<=x0){
			tmpb+=sumb[u][0];
			u=stb[u][0];
		}
//		cout<<"getdis "<<x0<<' '<<u<<' '<<tmpa<<' '<<tmpb<<'\n';
		printf("%d %d\n",(int)tmpa,(int)tmpb);
	}
}
		
