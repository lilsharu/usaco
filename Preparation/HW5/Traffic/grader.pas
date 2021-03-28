program grader;
   uses traffic;
   var i,r,N: longint;
   var P,S,D: array [0..1000000] of longint;
begin
   read(N); 
   for i:=0 to N-1 do read(P[i]);
   for i:=0 to N-2 do read(S[i],D[i]);
   r := LocateCentre(N,P,S,D);
   writeln(r);
end.
