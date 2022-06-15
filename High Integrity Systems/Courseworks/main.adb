pragma SPARK_Mode (On);

with AS_Io_Wrapper; use AS_Io_Wrapper;
with Decrement;     use Decrement;

procedure Main is
   InputRecord  : Num;
   OutputRecord : Num;
   T1           : Digit;
   T2           : Digit;
   T3           : Digit;
   U : Num;
   User_Input     : String (1 .. 20);
   User_Input_Int : Integer;
   Last           : Integer;
begin
   loop
      loop
         AS_Put ("Enter a number from 0 .. 9: ");
         AS_Get (User_Input_Int);
         exit when User_Input_Int in Digit;
         AS_Put_Line ("Please Enter a number between 0 and 9");
      end loop;
      T1 := User_Input_Int;

      loop
         AS_Put ("Enter a number from 0 .. 9: ");
         AS_Get (User_Input_Int);
         exit when User_Input_Int in Digit;
         AS_Put_Line ("Please Enter a number between 0 and 9");
      end loop;
      T2 := User_Input_Int;

      loop
         AS_Put ("Enter a number from 0 .. 9: ");
         AS_Get (User_Input_Int);
         exit when User_Input_Int in Digit;
         AS_Put_Line ("Please Enter a number between 0 and 9");
      end loop;
      T3 := User_Input_Int;

      InputRecord := (T1, T2, T3);

      minus1Proc (InputRecord, OutputRecord);
      AS_Put_Line ("The result of the procedure is: ");
      AS_Put(OutputRecord.T1);
      AS_Put(OutputRecord.T2);
      AS_Put(OutputRecord.T3);

      U := minus1Func(InputRecord);
      AS_Put_Line ("The result of the function is: ");
      AS_Put(U.T1);
      AS_Put(U.T2);
      AS_Put(U.T3);

      
      loop
         AS_Put ("Do you want to try again (y/n)? ");
         AS_Get_Line (User_Input, Last);
         exit when Last > 0;
         AS_Put_Line ("Please enter a non-empty string");
      end loop;
      exit when User_Input (1 .. 1) = "n";
   end loop;
end Main;
