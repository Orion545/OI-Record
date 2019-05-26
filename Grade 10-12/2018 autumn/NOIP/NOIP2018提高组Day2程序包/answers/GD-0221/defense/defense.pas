var i,j:longint;
    k,l,m,n,q,w,u,v,p1,p2,x,y:int64;
    a,b,v1,v2,f1,f2:array[0..5000] of int64;
    s:string;
function min(p,o:int64):int64;
begin
    if p>o then exit(o); exit(p);
end;
begin
assign(input,'defense.in'); reset(input);
assign(output,'defense.out'); rewrite(output);
    readln(n,m,s);
    for i:=1 to n do read(v1[i]);
    for i:=1 to n-1 do readln(u,v);
    while m>0 do begin
        dec(m);
        fillchar(f1,sizeof(f1),0);
        fillchar(f2,sizeof(f2),0);
        readln(p1,x,p2,y);
        if (abs(p1-p2)=1)and(x+y=0) then begin
          writeln(-1); continue;
        end;
        if x=0 then begin q:=v1[p1]; v1[p1]:=100*maxlongint; end
        else v2[p1]:=100*maxlongint;
        if y=0 then begin w:=v1[p2]; v1[p2]:=100*maxlongint; end
        else v2[p2]:=100*maxlongint;
        for i:=1 to n do begin
            f1[i]:=min(f1[i-1],f2[i-1])+v1[i];
            f2[i]:=f1[i-1]+v2[i];
        end;
        if x=0 then v1[p1]:=q else v2[p1]:=0;
        if y=0 then v1[p2]:=w else v2[p2]:=0;
        writeln(min(f1[n],f2[n]));
    end;
    close(input); close(output);
end.
