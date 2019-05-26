const maxn=5010;

type edge=record
	node:longint;
	next:longint;
	end;

var n,m,i,f,g,dfn,min,minx,st:longint;
	lob,bck,ter:boolean;
	dgr,list:array[1..maxn]of longint;
	flag,inloop,lo:array[1..maxn]of boolean;
	e,et:array[1..maxn,1..maxn]of boolean;
	
{procedure add(x,y:longint);
begin
	inc(tot);
	e[tot].node:=y;
	e[tot].next:=head[x];
	head[x]:=tot;
end;}
	
procedure dfs(x:longint);
var i:longint;
begin
	inc(dfn);
	list[dfn]:=x;
	flag[x]:=true;
	for i:=1 to n do
	begin
		if (e[x,i]=false)or(flag[i]) then
			continue;
		e[x,i]:=false;
		e[i,x]:=false;
		dfs(i);
	end;
end;

procedure loop(x:longint);
var i:longint;
begin
	flag[x]:=true;
	for i:=1 to n do
	begin
		if (not et[x,i]) then
			continue;
		et[x,i]:=false;
		et[i,x]:=false;
		dec(dgr[x]);
		dec(dgr[i]);
		if flag[i] then
		begin
			{if i<>1 then
				lo2:=i;
			if dgr[x]>0 then
				lo1:=x;}
			lo[x]:=true;
			lo[i]:=true;
			st:=i;
			inc(dgr[i]);
			inloop[x]:=true;
			inloop[i]:=true;
			lob:=true;
			exit;
		end;
		loop(i);
		if st=x then
			ter:=true;
		if ter then
			exit;
		if lob then
		begin
			if dgr[x]>0 then
			begin
				{if (lo2<>x)and(lo1=0) then
					lo1:=x
				else writeln('fuck?');/////////////////}
				lo[x]:=true;
			end;
			inloop[x]:=true;
			exit;
		end
		else
			inc(dgr[x]);
	end;
end;

procedure dfs2(x:longint);
var i,j:longint;
begin
	//writeln(dfn,':',x);
	if (not flag[x]) then
	begin
		inc(dfn);
		list[dfn]:=x;
		flag[x]:=true;
	end;
	for i:=1 to n do
	begin
		if (e[x,i]=false)or(flag[i]) then
			continue;
		if (not bck)and(min<i)and(inloop[x])and(dgr[x]=0) then
		begin
			bck:=true;
			dfs2(minx);
			exit;
		end;
		e[x,i]:=false;
		e[i,x]:=false;
		if (not bck)and(not inloop[i]) then
			dec(dgr[x]);
		if (not bck)and(inloop[x]) then
			for j:=i+1 to n do
			begin
				if j>=min then break;
				if (e[x,j])and(not flag[j]) then
				begin
					min:=j;
					minx:=x;
					break;
				end;
			end;
		dfs2(i);
	end;
end;
	
begin
	assign(input,'travel.in');
	assign(output,'travel.out');
	reset(input);
	rewrite(output);
	
	
	readln(n,m);
	if m=n-1 then
	begin
		fillchar(e,sizeof(e),false);
		for i:=1 to m do
		begin
			readln(f,g);
			e[f,g]:=true;
			e[g,f]:=true;
		end;
		fillchar(flag,n,false);
		dfn:=0;
		dfs(1);
		for i:=1 to n do
			write(list[i],' ');
	end
	else
	begin
		fillchar(e,sizeof(e),false);
		fillchar(et,sizeof(et),false);
		filldword(dgr,n,0);
		for i:=1 to m do
		begin
			readln(f,g);
			e[f,g]:=true;
			e[g,f]:=true;
			et[f,g]:=true;
			et[g,f]:=true;
			inc(dgr[f]);
			inc(dgr[g]);
		end;
		fillchar(flag,n,false);
		fillchar(inloop,n,false);
		fillchar(lo,n,false);
		//lo1:=0;
		//lo2:=0;
		lob:=false;
		ter:=false;
		loop(1);
		
		{for i:=1 to n do
			if (e[lo1,i])and(not inloop[i]) then
			begin
				min1:=i;
				break;
			end;
		if lo2<>0 then
			for i:=1 to n do
				if (e[lo2,i])and(not inloop[i]) then
				begin
					min2:=i;
					break;
				end;}
		
		{for i:=1 to n do
			if inloop[i]}
		
		
		
		
		
		fillchar(flag,n,false);
		dfn:=0;
		bck:=false;
		min:=n+1;
		minx:=0;
		dfs2(1);
		for i:=1 to n do
			write(list[i],' ');
		//writeln;
		//writeln(inloop[1]);
		//writeln(lo1,' ',lo2);
	end;
	
	close(input);
	close(output);
end.