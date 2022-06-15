pragma SPARK_Mode (On);

with AS_Io_Wrapper; use AS_Io_Wrapper;
with Division;      use Division;

procedure Main is
   I                   : InputRecord;
   O                   : OutputRecord;
   User_Input          : String (1 .. 20);
   User_Input_Dividend : Integer;
   User_Input_Divisor  : Integer;
   Last                : Integer;

begin
   AS_Init_Standard_Output;
   AS_Init_Standard_Input;
   loop
      loop
         AS_Put ("Enter a dividend: ");
         AS_Get
           (User_Input_Dividend,
            "Please type in an integer; please try again");
         AS_Put ("Enter a divisor: ");
         AS_Get
           (User_Input_Divisor, "Please type in an integer; please try again");
         exit when User_Input_Dividend >= 0 and User_Input_Divisor > 0;
      end loop;

      I.Dividend := User_Input_Dividend;
      I.Divisor  := User_Input_Divisor;

      divisionProc (I, O);
      AS_Put ("The result of the procedure is ");

      AS_Put_Line (O.Q);
      AS_Put_Line (O.R);

      loop
         AS_Put ("Do you want to try again (y/n)? ");
         AS_Get_Line (User_Input, Last);
         exit when Last > 0;
         AS_Put_Line ("Please enter a non-empty string");
      end loop;
      exit when User_Input (1 .. 1) = "n";
   end loop;
end Main;
