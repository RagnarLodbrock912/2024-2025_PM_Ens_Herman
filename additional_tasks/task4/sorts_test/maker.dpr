// случайный вход
{$apptype console}
{$B-,R+,Q+}
Uses
       SysUtils;
Const
       Target = 'input.txt';
       N      = 2000000;
       R      = 100000;
Var
       i : Integer;
Begin
       Rewrite(output,Target);
       Randomize;
       For i:=1 To N Do Write(random(R)+1,' ');
End.
