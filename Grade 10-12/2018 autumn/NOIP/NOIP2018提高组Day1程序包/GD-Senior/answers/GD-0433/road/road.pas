const maxn=100010;
	maxt=400010;
type node=record
	left:longint;
	right:longint;
	min:longint;
	max:longint;
	delay:longint;
	end;
	
var n,i,ans:longint;
	d:array[1..maxn]of longint;
	a:array[1..maxt]of node;
	
function mi(x,y:longint):longint;
begin
	if x>y then exit(y);
	exit(x);
end;

function ma(x,y:longint):longint;
begin
	if x<y then exit(y);
	exit(x);
end;
	
procedure update(cur:longint);
var left,right:longint;
begin
	left:=cur shl 1;
	right:=left+1;
	
	dec(a[left].min,a[cur].delay);
	dec(a[left].max,a[cur].delay);
	dec(a[right].min,a[cur].delay);
	dec(a[right].max,a[cur].delay);
	
	inc(a[left].delay,a[cur].delay);
	inc(a[right].delay,a[cur].delay);
	
	a[cur].delay:=0;
end;
	
function query(cur,l,r:longint):longint;
var left,right,m1,m2:longint;
begin
	if (a[cur].left>=l)and(a[cur].right<=r) then
		exit(a[cur].min)
	else
	begin
		left:=cur shl 1;
		right:=left+1;
		if a[cur].delay>0 then
			update(cur);
		if a[left].right>l then
			m1:=query(left,l,r)
		else m1:=10001;
		if a[right].left<r then
			m2:=query(right,l,r)
		else m2:=10001;
		query:=mi(m1,m2);
	end;
end;

function query2(cur,l,r:longint):longint;
var left,right,m1,m2:longint;
begin
	if (a[cur].left>=l)and(a[cur].right<=r) then
		exit(a[cur].max)
	else
	begin
		left:=cur shl 1;
		right:=left+1;
		if a[cur].delay>0 then
			update(cur);
		if a[left].right>l then
			m1:=query2(left,l,r)
		else m1:=0;
		if a[right].left<r then
			m2:=query2(right,l,r)
		else m2:=0;
		query2:=ma(m1,m2);
	end;
end;
	
procedure modify(cur,l,r,num:longint);
var left,right:longint;
begin
	if (a[cur].left>=l)and(a[cur].right<=r) then
	begin
		dec(a[cur].min,num);
		dec(a[cur].max,num);
		inc(a[cur].delay,num);
	end
	else
	begin
		left:=cur shl 1;
		right:=left+1;
		if a[cur].delay>0 then
			update(cur);
		if a[left].right>l then
			modify(left,l,r,num);
		if a[right].left<r then
			modify(right,l,r,num);
		a[cur].min:=mi(a[left].min,a[right].min);
		a[cur].max:=ma(a[left].max,a[right].max);
	end;
end;
	
procedure built(cur,l,r:longint);
var left,right,mid:longint;
begin
	a[cur].left:=l;
	a[cur].right:=r;
	a[cur].delay:=0;
	if l+1=r then
	begin
		a[cur].min:=d[l];
		a[cur].max:=d[l];
	end
	else
	begin
		left:=cur shl 1;
		right:=left+1;
		mid:=(l+r)shr 1;
		built(left,l,mid);
		built(right,mid,r);
		a[cur].min:=mi(a[left].min,a[right].min);
		a[cur].max:=ma(a[left].max,a[right].max);
	end;
end;
	
function bi(le,ri:longint):longint;
var mid,t:longint;
begin
	while le<ri do
	begin
		mid:=(le+ri)shr 1;
		t:=query(1,le,mid+1);
		if t=0 then
			ri:=mid
		else le:=mid+1;
	end;
	if (le=ri)and(query(1,le,le+1)<>0) then
	begin
		exit(le+1);
	end;
	exit(le);
end;

function bi2(le,ri:longint):longint;
var mid,t:longint;
begin
	while le<ri do
	begin
		mid:=(le+ri)shr 1;
		t:=query2(1,le,mid+1);
		if t>0 then
			ri:=mid
		else le:=mid+1;
	end;
	if (le=ri)and(query2(1,le,le+1)=0) then
		exit(le+1);
	exit(le);
end;
	
procedure main(l,r:longint);
var t,zero,nz:longint;//min
begin
	t:=query(1,l,r+1);
	if t>0 then
	begin
		inc(ans,t);
		modify(1,l,r+1,t);
	end;
	while query2(1,l,r+1)>0 do
	begin
		nz:=bi2(l,r);
		zero:=bi(nz,r);
		main(nz,zero-1);
	end;
end;
	
begin
	assign(input,'road.in');
	assign(output,'road.out');
	reset(input);
	rewrite(output);
	
	readln(n);
	for i:=1 to n do
		read(d[i]);
	built(1,1,n+1);
	ans:=0;
	main(1,n);
	writeln(ans);
	
	close(input);
	close(output);
end.