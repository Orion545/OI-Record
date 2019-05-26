#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct cow{
	int x,y;bool breed;
}a[510];
int n,ans,tmp;
bool cmp(cow l,cow r){
	return l.y<r.y;
}
int xx[1010][1010],yy[1010][1010],zz[1010][1010];
int b[1010][1010]={0};
int main(){
	std::ios::sync_with_stdio(false);
	int i,j,k,t1,t2,l,r,maxx=0,maxy=0,minx=1010;char t3;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>t1>>t2>>t3;
		a[i].x=t1;a[i].y=t2;a[i].breed=((t3=='H')?1:0);
		b[t1][t2]=((t3=='H')?1:2);
		maxx=max(maxx,t1);minx=min(minx,t1);
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=1001;i++){
		for(j=1;j<=1001;j++){
			xx[i][j]=xx[i][j-1]+((b[i-1][j-1]==2)?1:0);
			yy[i][j]=yy[i][j-1]+((b[i-1][j-1]==1)?1:0);
			zz[i][j]=zz[i-1][j]+zz[i][j-1]-zz[i-1][j-1]+((b[i-1][j-1]==1)?1:0);	
		} 
	}
//	cout<<endl<<endl;
//	for(i=0;i<=6;i++){
//		for(j=0;j<=6;j++) cout<<zz[i][j]<<ends;
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//	for(i=0;i<=6;i++){
//		for(j=0;j<=6;j++) cout<<b[i][j]<<ends;
//		cout<<endl;
//	}
//	cout<<endl<<endl;
//	for(i=1;i<=n;i++) cout<<a[i].x<<ends<<a[i].y<<ends<<a[i].breed<<endl;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(!(a[i].breed&&a[j].breed)) continue;
//			cout<<i<<ends<<j<<endl;
//			maxx=max(a[i].x,a[j].x);minx=min(a[i].x,a[j].x);
			l=r=minx;
			do{
//				cout<<"	"<<l<<ends<<r<<endl;
				int t=zz[r+1][a[j].y+1]-zz[l][a[j].y+1]-zz[r+1][a[i].y]+zz[l][a[i].y],area=(r-l)*(a[j].y-a[i].y);
				if(xx[r+1][a[j].y+1]-xx[r+1][a[i].y]!=0) goto jump;
				if(ans<t||(ans==t&&tmp>area)){
//					cout<<"		renew "<<l<<ends<<r<<ends<<a[i].y<<ends<<a[j].y<<ends<<t<<ends<<area<<endl;
					ans=t;tmp=area;
				}
				jump:
				if(xx[r+1][a[j].y+1]-xx[r+1][a[i].y]!=0) l=++r;
				else{
					if(r<maxx) r++;
					else l++;
				}
			}while(r<maxx||(r==maxx&&l<=maxx));
		}
	}
	cout<<ans<<"\n"<<tmp<<endl;
}
