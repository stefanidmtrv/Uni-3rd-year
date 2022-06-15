pragma SPARK_Mode;

package body Division is

   procedure divisionProc (I : in InputRecord; O : out OutputRecord) is
      var : Integer;

   begin
      var := I.Dividend;
      O.Q := 0;
      while (var >= I.Divisor) loop
         pragma Loop_Invariant
           ((I.Divisor <= var) and (I.Dividend = (O.Q * I.Divisor + var)));
         var := var - I.Divisor;
         O.Q := O.Q + 1;
      end loop;
      O.R := var;

   end divisionProc;

end Division;
