#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
FILE *iin,*outt;
struct Dian
{
	vector<int> tto;
}dian[5003];
int n,m,a,b,c,bj[5003],mm[5003][5003];
int js=1;
int AK_IOI(int x,int num)
{
	mm[x][js++]=num;
	Dian u=dian[num];
	int paixu[u.tto.size()+2];
	for(int i=0;i<u.tto.size();i++)
		paixu[i]=u.tto[i]; 
	sort(paixu,paixu+u.tto.size());
	for(int i=0;i<u.tto.size();i++)
	if(paixu[i]!=19260817)
	if(bj[paixu[i]]!=233)
	{
		bj[paixu[i]]=233;
		AK_IOI(x,paixu[i]);
		bj[paixu[i]]=0;
	}
}
int h_bj[5003];
int shang[5003],xia[5003],nage,jie=0;
int huan(int num,int bac)
{
	h_bj[num]=233;
	Dian u=dian[num];
	for(int i=0;i<u.tto.size();i++)
	if(u.tto[i]!=bac)
	{
		int nex=u.tto[i];
		if(h_bj[nex]==233)
		{
			xia[nex]=num;
			shang[num]=nex;
			xia[num]=bac;
			shang[bac]=num;
			nage=nex;
			return 1;
		}
		xia[num]=bac;
		shang[bac]=num;
		int asa=huan(nex,num);
		if(asa)return 1;
	}
	return 0;
}
int goodd=1;
int AK_NOIP()
{
	int p=nage;
	int yyy=1;
	while(1)
	{
		int pre=shang[p];
		int bac=p;
		int qq,zz;
		for(int i=0;i<dian[pre].tto.size();i++)
			if(dian[pre].tto[i]==bac)
			{
				qq=i;
				dian[pre].tto[i]=19260817;
				break;
			}
		for(int i=0;i<dian[bac].tto.size();i++)
			if(dian[bac].tto[i]==pre)
			{
				zz=i;
				dian[bac].tto[i]=19260817;
				break;
			}
		js=1;
		bj[1]=233;
		AK_IOI(yyy,1);
		dian[pre].tto[qq]=bac;
		dian[bac].tto[zz]=pre;
		for(int i=1;i<=n;i++)
		if(mm[yyy][i]!=mm[goodd][i])
		{
			if(mm[yyy][i]<mm[goodd][i])
				goodd=yyy;
			break;
		}
		yyy++;
		if(shang[p]==nage)return 0;
		p=shang[p];
	}
}
int main()
{
	iin=fopen("travel.in","rb");
	outt=fopen("travel.out","wb");
	fscanf(iin,"%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		fscanf(iin,"%d%d",&a,&b);
		dian[a].tto.push_back(b);
		dian[b].tto.push_back(a);
		bj[a]=0;
		bj[b]=0;
	}
	if(m==n-1)
	{
		bj[1]=233;
		AK_IOI(1,1);
		for(int i=1;i<js;i++)
			fprintf(outt,"%d ",mm[1][i]);
	}
	else
	{
		huan(1,0);
		AK_NOIP();
		for(int i=1;i<js;i++)
			fprintf(outt,"%d ",mm[goodd][i]);
	}
	return 0;
}
