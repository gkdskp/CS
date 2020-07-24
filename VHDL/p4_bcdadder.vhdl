-- Design and Set up
-- 	a BCD adder using 7483

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BCDAdder is
	port (
		A, B: in unsigned(3 downto 0);
		S: out unsigned(3 downto 0);
		Cout: out std_logic
	);
end BCDAdder;

architecture behave of BCDAdder is

begin process(A, B)
variable sum_temp: unsigned(4 downto 0);

begin
	sum_temp := ('0' & A) + ('0' & B);
	if(sum_temp > 9) then
		Cout <= '1';
		S <= resize((sum_temp + "00110"),4);
	else
		Cout <= '0';
		S <= sum_temp(3 downto 0);
	end if;

end process;
end;
