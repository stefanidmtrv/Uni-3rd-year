pragma SPARK_Mode;

package body Decrement is

   function minus1Func (Number : in Num) return Num is
      O1, O2, O3   : Digit;
      OutputRecord : Num;
   begin
      if Number.T3 > 0 then
         O3 := Number.T3 - 1;
         O2 := Number.T2;
         O1 := Number.T1;
      elsif Number.T2 > 0 then
         O3 := 9;
         O2 := Number.T2 - 1;
         O1 := Number.T1;
      elsif Number.T1 > 0 then
         O3 := 9;
         O2 := 9;
         O1 := Number.T1 - 1;
      else
         O3 := 9;
         O2 := 9;
         O1 := 9;

      end if;
      OutputRecord := (O1, O2, O3);
      return OutputRecord;
   end minus1Func;

   procedure minus1Proc (Number : in Num; O : out Num) is

   begin
      if Number.T3 > 0 then
         O.T3 := Number.T3 - 1;
         O.T2 := Number.T2;
         O.T1 := Number.T1;
      elsif Number.T2 > 0 then
         O.T3 := 9;
         O.T2 := Number.T2 - 1;
         O.T1 := Number.T1;
      elsif Number.T1 > 0 then
         O.T3 := 9;
         O.T2 := 9;
         O.T1 := Number.T1 - 1;
      else
         O.T3 := 9;
         O.T2 := 9;
         O.T1 := 9;
      end if;

   end minus1Proc;

end Decrement;
