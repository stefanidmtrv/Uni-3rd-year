pragma SPARK_Mode;

package Decrement is

   subtype Digit is Integer range 0 .. 9;

   type Num is record
      T1, T2, T3 : Digit;
   end record;

   function minus1Func (Number : in Num) return Num with
     Post    => (if ((Number.T1 * 100 ) + (Number.T2 * 10) + Number.T3) = 0 then
                   ((minus1Func'Result.T1 * 100) + (minus1Func'Result.T2 * 10) + minus1Func'Result.T3) = 999
      else ((Number.T1 * 100) + (Number.T2 * 10) + Number.T3) - 1 =
        ((minus1Func'Result.T1 * 100) + (minus1Func'Result.T2 * 10) + minus1Func'Result.T3));

   procedure minus1Proc (Number : in Num; O : out Num) with
      Depends => (O => Number),
      Post    => (if ((Number.T1 * 100) + (Number.T2 * 10) + Number.T3) = 0 then
        ((O.T1 * 100) + (O.T2 * 10) + O.T3) = 999
      else ((Number.T1 * 100) + (Number.T2 * 10) + Number.T3) - 1 =
        ((O.T1 * 100) + (O.T2 * 10) + O.T3));

end Decrement;
