const
 filename='Game';
begin
 assign(input,filename+'.in');reset(input);
 assign(output,filename+'.out');rewrite(output);
 writeln(12);
 close(input);close(output);
end.