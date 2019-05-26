/*
ID: marcoli2
PROG: friday
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int main(){
	int n,y=1900,m=1,d=0,date=2,ans[10]={0};
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	scanf("%d",&n);
	while(!(y==1900+n-1&&m==12&&d==31)){
		d++;date++;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(date==8) date=1;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(d==29&&(!((y%100==0&&y%400==0)||(y%100&&y%4==0)))&&m==2) m=3,d=1;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(d==30&&((y%100==0&&y%400==0)||(y%100&&y%4==0))&&m==2) m=3,d=1;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(d==31&&(m==4||m==6||m==9||m==11)) m++,d=1;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(d==32) m++,d=1;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(m==13) m=1,y++;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;
		if(d==13) ans[date]++;
//		cout<<y<<ends<<m<<ends<<d<<ends<<date<<endl;system("pause");
	}
	for(int i=1;i<=7;i++){
		printf("%d",ans[i]);
		if(i==7) printf("\n");
		else printf(" ");
	} 
}
