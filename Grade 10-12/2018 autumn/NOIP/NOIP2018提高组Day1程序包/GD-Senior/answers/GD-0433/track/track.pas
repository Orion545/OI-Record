const maxn=50000;

type edge=record
	node:longint;
	next:longint;
	v:longint;
	end;

var n,m,i,f,g,w,tot,max:longint;
	head,dp:array[1..maxn]of longint;
	e:array[1..2*maxn]of edge;
	flag:array[1..maxn]of boolean;
	
procedure add(x,y,z:longint);
begin
	inc(tot);
	e[tot].node:=y;
	e[tot].v:=z;
	e[tot].next:=head[x];
	head[x]:=tot;
end;
	
procedure dfs(x:longint);
var p,u:longint;
begin
	flag[x]:=false;
	p:=head[x];
	while p<>0 do
	begin
		u:=e[p].node;
		if flag[u] then
		begin
			dfs(u);
			if dp[x]<dp[u]+e[p].v then
				dp[x]:=dp[u]+e[p].v;
		end;
		p:=e[p].next;
	end;
	flag[x]:=true;
end;

	
begin
	assign(input,'track.in');
	assign(output,'track.out');
	reset(input);
	rewrite(output);
	
	
	readln(n,m);
	filldword(head,n,0);
	tot:=0;
	for i:=1 to n-1 do
	begin
		readln(f,g,w);
		add(f,g,w);
		add(g,f,w);
	end;
	max:=0;
	fillchar(flag,n,true);
	for i:=1 to n do
	begin
		filldword(dp,n,0);
		dfs(i);
		if dp[i]>max then
			max:=dp[i];
	end;
	writeln(max);
	
	close(input);
	close(output);
end.