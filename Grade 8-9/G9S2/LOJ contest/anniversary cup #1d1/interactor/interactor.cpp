#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

int n,m,d,l;

std::string maze[1500];
int dist[505][505];

std::string cmd;

int x,y;
int dir;

bool check(int x,int y,int dir,int side)
{
	if (x<1||y<1||x>n||y>m)
		return 0;
	dir=(dir+(side<<1^1))&3;
	if (dir&1)
		return maze[2*x-2+dir][2*y]!=' ';
	return maze[2*x][2*y+1-dir]!=' ';
}

int movex(int x,int dir)
{
	if (dir&1)
		return x-2+dir;
	return x;
}
int movey(int y,int dir)
{
	if (dir&1)
		return y;
	return y+1-dir;
}

int main()
{
	std::ifstream datin("input");
	std::ofstream score("score.txt");	

	datin>>n>>m>>l>>d;
	std::cout<<n<<" "<<m<<" "<<" "<<l<<" "<<d<<std::endl<<std::flush;

	for (int i=1;i<=2*n+1;i++)
	{
		std::getline(datin,maze[i]);
		if (maze[i].size()<2*m+1)
			std::getline(datin,maze[i]);
		maze[i]=" "+maze[i];
	}

	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			datin>>dist[i][j];

	x=y=1;
	dir=0;

	while (1)
	{
		if (l==0)
		{
			if (x==n&&y==m)
			{
				score<<100<<std::endl;
				std::cerr<<"Mission Completed. "<<std::endl;
				exit(0);
			}
			score<<std::max(0.0,(dist[1][1]-dist[x][y])*100.0/(dist[1][1]*1.0))<<std::endl;
			std::cerr<<"Mission Failed. "<<std::endl;
			exit(1);
		}
		cmd="";
		std::cin>>cmd;
		if (cmd=="reverse")
		{
			dir=dir^2;
			continue;
		}
		if (cmd=="reach_dest")
		{
			if (x==n&&y==m)
			{
				std::cout<<1<<std::endl<<std::flush;
				score<<100<<std::endl;
				std::cerr<<"Mission Completed. "<<std::endl;
				exit(0);
			}
			std::cout<<0<<std::endl<<std::flush;
			continue;
		}
		if (cmd=="dist")
		{
			if (d==0)
				std::cout<<0<<std::endl<<std::flush;
			else
			{
				d--;
				std::cout<<dist[x][y]<<std::endl<<std::flush;
			}
			continue;
		}
		if (cmd=="move_left")
		{
			if (check(x,y,dir,0)==0)
			{
				std::cout<<0<<std::endl<<std::flush;
				continue;
			}
			l--;
			if (check(x,y,(dir+3)&3,0))
			{
				dir=(dir+3)&3;
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			if (check(movex(x,dir),movey(y,dir),dir,0))
			{
				x=movex(x,dir);
				y=movey(y,dir);
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			if (check(movex(movex(x,dir),(dir+1)&3),movey(movey(y,dir),(dir+1)&3),(dir+1)&3,0))
			{
				x=movex(movex(x,dir),(dir+1)&3);
				y=movey(movey(y,dir),(dir+1)&3);
				dir=(dir+1)&3;
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			x=movex(x,(dir+1)&3);
			y=movey(y,(dir+1)&3);
			dir=dir^2;
			std::cout<<1<<std::endl<<std::flush;
			continue;
		}
		if (cmd=="move_right")
		{
			if (check(x,y,dir,1)==0)
			{
				std::cout<<0<<std::endl<<std::flush;
				continue;
			}
			l--;
			if (check(x,y,(dir+1)&3,1))
			{
				dir=(dir+1)&3;
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			if (check(movex(x,dir),movey(y,dir),dir,1))
			{
				x=movex(x,dir);
				y=movey(y,dir);
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			if (check(movex(movex(x,dir),(dir+3)&3),movey(movey(y,dir),(dir+3)&3),(dir+3)&3,1))
			{
				x=movex(movex(x,dir),(dir+3)&3);
				y=movey(movey(y,dir),(dir+3)&3);
				dir=(dir+3)&3;
				std::cout<<1<<std::endl<<std::flush;
				continue;
			}
			x=movex(x,(dir+3)&3);
			y=movey(y,(dir+3)&3);
			dir=dir^2;
			std::cout<<1<<std::endl<<std::flush;
			continue;
		}
		std::cerr<<"Invalid command `"+cmd+"'! "<<std::endl;
		score<<-1<<std::endl;
		exit(1);
	}

	return 0;
}