unit traffic;

interface
   function LocateCentre(N: longint; P,S,D: array of longint): longint; 
implementation
   function LocateCentre(N: longint; P,S,D: array of longint): longint; 
   begin
     LocateCentre := N div 2;
   end;
begin
end.

