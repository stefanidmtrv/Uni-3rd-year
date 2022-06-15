 pragma SPARK_Mode;

package Division is

   type InputRecord is record
      Dividend, Divisor : Integer;
   end record;

   type OutputRecord is record
      R, Q : Integer;
   end record;

   procedure divisionProc (I : in InputRecord; O : out OutputRecord) with
      Depends => (O => I),
      Pre     => (I.Dividend >= 0 and I.Divisor > 0),
      Post    =>
      (I.Dividend = ((O.Q * I.Divisor) + O.R) and O.R >= 0 and
       O.R < I.Divisor);

end Division;
