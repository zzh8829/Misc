var n,x,t,i,j:longint;
	m:array[1..10001]of longint;
begin
	readln(x);
	readln(n);
	m[0]:= 0;
	for i:=1 to x do
		m[i]:=99999;
	for i:=1 to n do begin
        readln(t);
        for j:=t to x do 
            if m[j-t]+1 < m[j] then
                m[j] := m[j-t]+1;
    end;
    writeln(m[x]);
end.