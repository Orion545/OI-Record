#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<set>
#define ll long long
using namespace std;
#define mp make_pair
int IDENTIFICATION[100010],a[100010]; pair<int,int> e[100010];
bool cmp(int l,int r){
	return l>r;
}
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
#define THE_FIRST_ELE first
#define THE_s_ELE second
int main(){	
	int n,P=1,la=1;
	int x,y,tot=0; 
	n=read();
	IDENTIFICATION[1]=n;
	for(int i=1;i<n;i++){	
		x=read();y=read();
		if(x<y) swap(x,y);
		if(x==y||x!=n){
			
			puts("NO"); 
			
						return 0;
		}
		a[i]=y;
	}
	set<int>SET_OF_SOMETHING;
	for(int i=1;i<n;i++) SET_OF_SOMETHING.insert(-i);
	for(int i=1;i<n;i++){
		
		if(SET_OF_SOMETHING.count(-a[i])) 
												SET_OF_SOMETHING.erase(-a[i]);
	}
			
	sort(a+1,a+n,cmp);
	
	int i=1,j=i;
	for(;i<n;i=j){	
											for(j=i+1;j<n&&a[j]==a[i];j++);
		int cur=P;
		for(int k=i+1;k<j;k++){	
									if(!SET_OF_SOMETHING.size()||-*SET_OF_SOMETHING.begin()>a[i]){
				
				
				
				
				puts("NO");return 0;
			}
												IDENTIFICATION[++P]=-*SET_OF_SOMETHING.begin(); 
			e[++tot]=mp(la,P); 
			
			
			la=P; 
							SET_OF_SOMETHING.erase(SET_OF_SOMETHING.begin());
		}
		IDENTIFICATION[++P]=a[i]; e[++tot]=mp(la,P); la=cur+1;
	}
	puts("YES");
	
	for(i=1;i<=tot;i++) 
			printf("%d %d\n",IDENTIFICATION[e[i].THE_FIRST_ELE],IDENTIFICATION[e[i].THE_s_ELE]);
}
