#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define inf 0x7fffffff
using namespace std;
struct node{
	int num,l,r;
	bool sex;
}a[200100];
struct couple{
	int l,r,num;
	inline bool operator <(const couple &b) const{
		if(num<b.num) return 1;
		else{
			if(num==b.num&&l<b.l) return 1;
			else return 0;
		} 
	}
};
set<couple>s;
int abs(int k){return (k>=0)?k:-k;}
int n,m,ans1[200010],ans2[200010];
char t2[200010];
inline int read(){
	int re=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+(int)(ch-'0');ch=getchar();
	}
	return re;
}
inline void get_string(){
	char ch=getchar();int cnt=-1;
	while(ch!='B'&&ch!='G') ch=getchar();
	while(ch=='B'||ch=='G'){
		t2[++cnt]=ch;ch=getchar();
	}
}
inline couple cp(int xx,int yy,int zz){
	couple re;
	re.l=xx;re.r=yy;re.num=zz;
	return re;
}
inline void put(int x){
	char s[100];int cnt=0;
	if(x==0) putchar('0');
	else{
		while(x){
			s[++cnt]=(char)(x%10+48);
			x/=10;
		}
	}
	while(cnt) putchar(s[cnt--]);
}
int main(){
	freopen("dancingLessons.in","r",stdin);
	freopen("dancingLessons.out","w",stdout);
	int i,t1;
	couple tmp;
	n=read();
	get_string();
	for(i=0;i<n;i++) a[i+1].sex=(t2[i]=='B');
	for(i=1;i<=n;i++){
		a[i].num=read();
		a[i].l=i-1;a[i].r=i+1;
	} 
	for(i=1;i<n;i++){
		if(a[i].sex!=a[i+1].sex) s.insert(cp(i,i+1,abs(a[i+1].num-a[i].num)));
	}
	while(!s.empty()){
		tmp=*s.begin();
		ans1[++m]=tmp.l;ans2[m]=tmp.r;
		s.erase(s.begin());
		if(a[tmp.l].l>0)  s.erase(cp(a[tmp.l].l,tmp.l,abs(a[a[tmp.l].l].num-a[tmp.l].num)));
		if(a[tmp.r].r<=n) s.erase(cp(tmp.r,a[tmp.r].r,abs(a[a[tmp.r].r].num-a[tmp.r].num)));
		if(a[tmp.l].l>0&&a[tmp.r].r<=n&&a[a[tmp.l].l].sex!=a[a[tmp.r].r].sex) s.insert(cp(a[tmp.l].l,a[tmp.r].r,abs(a[a[tmp.l].l].num-a[a[tmp.r].r].num)));
		a[a[tmp.l].l].r=a[tmp.r].r;
		a[a[tmp.r].r].l=a[tmp.l].l;
	}
	put(m);putchar('\n');
	for(i=1;i<=m;i++) put(ans1[i]),putchar(' '),put(ans2[i]),putchar('\n');
	return 0;
}
