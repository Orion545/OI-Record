#include<iostream>
using namespace std;
int a[362881][2],hash=91249,h[100001];
int head=0,tail=1,duilie[1000001][3];
int ppow(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
inline int find(int a,int x){
	return (a%ppow(10,9-x+1)-a%ppow(10,9-x))/ppow(10,9-x);
}
inline int change(int a,int y1,int y2){
	int b=ppow(10,9-y1),c=ppow(10,9-y2);
	int x=(a%(b*10)-a%b),y=(a%(c*10)-a%c);
	a-=x;a-=y;
	x/=b;x*=c;y/=c;y*=b;
	a+=x;a+=y;
	return a;
}
void bfs(int zls){
	duilie[1][0]=a[1][0];duilie[1][1]=zls;duilie[1][2]=1;
	do{
		head++;
		//cout<<"HEAD!!! "<<head<<" "<<duilie[head][0]<<" "<<duilie[head][1]<<" "<<duilie[head][2]<<endl;
		for(int i=-3;i<=3;i+=2){
			if(duilie[head][1]+i<=9&&duilie[head][1]+i>=1&&(!(i==-1&&duilie[head][1]%3==1))&&(!(i==1&&duilie[head][1]%3==0))){
				tail++;
				a[tail][0]=change(duilie[head][0],duilie[head][1],i+duilie[head][1]);
				duilie[tail][2]=duilie[head][2]+1;duilie[tail][0]=a[tail][0];duilie[tail][1]=duilie[head][1]+i;
				//cout<<"TAIL!!! "<<tail<<" "<<duilie[tail][0]<<" "<<duilie[tail][1]<<" "<<duilie[tail][2]<<endl;
				int tmp=duilie[tail][0]%91249;
				if(h[tmp]!=0){
					//cout<<"*1 ";
					int tt=h[tmp];
					while(a[tt][1]!=0){
						if(a[tt][0]==duilie[tail][0]){
							//cout<<"*2"<<endl;
							duilie[tail][0]=0;duilie[tail][1]=0;
							a[tail][0]=0;a[tail][1]=0;tail--;
							goto p1;
						}
						tt=a[tt][1];
					}
					a[tt][1]=tail;
					//cout<<endl;
				}
				else h[tmp]=tail;
				//cout<<"*3"<<endl;
				p1:
				if(duilie[tail][0]==123894765){
					cout<<duilie[tail][2]-1;return;
				}
			}
		}
	}while(head<tail);
} 
int main(){
	int FFF,ZLS;cin>>FFF;
	for(int i=0;i<=8;i++){
		if((FFF%ppow(10,i+1)-FFF%ppow(10,i))/ppow(10,i)==0) ZLS=9-i;
	}
	//cout<<ZLS<<endl;//return 0;
	FFF+=9*ppow(10,9-ZLS);
	//cout<<FFF<<endl;//return 0;
	a[1][0]=FFF;a[1][1]=0;
	h[a[1][0]%91249]=1;
	bfs(ZLS);
}
/*
284719365
9=(a%10000-a%1000)/1000
*/
