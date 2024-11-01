// почти упорядоченный вход
{$apptype console}
{$B-,R+,Q+}
Uses
       SysUtils;
Const
       Target = 'input.txt';
       N      = 100000;
       K      = 100;
Var
       X         : Array[1..N] Of Integer;
       i,a,b,tmp : Integer;
Begin
       For i:=1 To N Do X[i]:=i;
       Randomize;
       For i:=1 To K Do Begin
           a:=random(N)+1;
           b:=random(N)+1;
           tmp:=X[a];
           X[a]:=X[b];
           X[b]:=tmp;
       End;
       Rewrite(output,Target);
       For i:=1 To N Do Write(X[i],' ');
End.
