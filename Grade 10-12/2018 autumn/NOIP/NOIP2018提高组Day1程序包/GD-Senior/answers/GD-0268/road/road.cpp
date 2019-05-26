#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,d[100001],l,r,min,day;
	bool ly;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	day=0;ly=true;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>d[i];
	while(ly){
	    min=10000;
	    ly=false;
		for(int i=1;i<=n;i++){
			if(d[i]!=0){
			    l=i;
				ly=true;
				break;
			}
		}
		if(!ly) break;
		for(int i=l;i<=n;i++) if((i==n)||(d[i+1]==0)){r=i;break;}
		for(int i=l;i<=r;i++) if(d[i]<min) min=d[i];
		for(int i=l;i<=r;i++) d[i]-=min;
		day+=min;
	}
	cout<<day;
	fclose(stdin);fclose(stdout);
	return 0;
}
