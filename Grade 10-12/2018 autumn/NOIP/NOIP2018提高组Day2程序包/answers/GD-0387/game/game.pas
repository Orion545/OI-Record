program game;
const
        inf=1000000007;
var
        n,m,i,j:longint;
        a:array[0..7,0..7] of char;
        w,s:ansistring;
        dp:array[0..9,0..100000] of longint;
        o,ans:int64;
begin
        assign(input,'game.in');reset(input);
        assign(output,'game.out');rewrite(output);
        read(n,m);
        dp[n-1,m]:=1;
        for i:=n-1 downto 0 do
                for j:=m-1 downto 0 do
                        dp[i,j]:=2*(dp[i,j+1]+dp[i+1,j]);
        o:=dp[1,0]*2-dp[n-1,0]*(dp[n-1,1] div 2);
        ans:=(dp[0,0]-o) mod inf;
        write(ans);
        close(input);close(output);
end.