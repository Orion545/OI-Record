const maxn=105;
	maxa=25000;
var n,te,i,j,ans:longint;
	a:array[1..maxn]of longint;
	dp,flag:array[0..maxa]of boolean;
	
procedure swap(var x,y:longint);
var tem:longint;
begin
	tem:=x;
	x:=y;
	y:=tem;
end;
	
procedure qs(l,r:longint);//as
var x,y,k:longint;
begin
	x:=l;y:=r;
	k:=a[(l+r)shr 1];
	while x<=y do
	begin
		while a[x]<k do inc(x);
		while a[y]>k do dec(y);
		if x<=y then
		begin
			swap(a[x],a[y]);
			inc(x);
			dec(y);
		end;
	end;
	if x<r then qs(x,r);
	if y>l then qs(l,y);
end;
	
begin
	assign(input,'money.in');
	assign(output,'money.out');
	reset(input);
	rewrite(output);
	
	readln(te);
	while te>0 do
	begin
		readln(n);
		ans:=n;
		for i:=1 to n do
			read(a[i]);
		qs(1,n);
	
		fillchar(dp,a[n],false);
		fillchar(flag,a[n],false);
		for i:=1 to n do
			flag[a[i]]:=true;
		dp[0]:=true;
		for i:=1 to n-1 do
		begin
			if not(flag[a[i]]) then
				continue;
			flag[a[i]]:=false;
			for j:=0 to (a[n]-a[i]) do
				if (dp[j])and(not dp[j+a[i]]) then
				begin
					dp[j+a[i]]:=true;
					if flag[j+a[i]] then
					begin
						dec(ans);
						flag[j+a[i]]:=false;
					end;
				end;
		end;
		dec(te);
		writeln(ans);
	end;
	
	close(input);
	close(output);
end.