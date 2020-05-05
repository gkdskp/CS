-- To setup and study the following synchronous counters
-- 	a) 4 bit synchronous up counter
-- 	b) 3 bit synchronous down counter
-- 	c) Self starting counter for repeating the sequence 0,4,2,1,6....

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity upCounter is
	port (
		CLK, CLR: in std_ulogic;
		Q: out unsigned(3 downto 0)
	);
end upCounter;

architecture behave of upCounter is
signal counter: unsigned(3 downto 0) := "0000";

begin process(CLK, CLR)
begin
	if(CLR = '1') then
		counter <= "0000";
	elsif(CLK'event and CLK = '1') then
		counter <= counter + 1;
	end if;
end process;
	Q <= counter;
end behave;


--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity downCounter is
	port (
		CLK, CLR: in std_ulogic;
		Q: out unsigned(2 downto 0)
	);
end downCounter;

architecture behave of downCounter is
signal counter: unsigned(2 downto 0) := "111";

begin process(CLK, CLR)
begin 
	if(CLR = '1') then
		counter <= "111";
	elsif(CLK'event and CLK = '1') then
		counter <= counter - 1;
	end if;
end process;
	Q <= counter;
end behave;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity customCounter is
	port (
		CLK, CLR: in std_ulogic;
		Q: out unsigned(2 downto 0)
	);
end customCounter;

architecture behave of customCounter is
signal counter: unsigned(2 downto 0):= "000";

begin process(CLK, CLR)
begin
	if(CLR = '1') then
		counter <= "000";
	elsif(CLK'event and CLK = '1') then
		if(counter = "000") then
			counter <= "100";
		elsif(counter = "100") then
			counter <= "010";
		elsif(counter = "010") then
			counter <= "001";
		elsif(counter = "001") then
			counter <= "110";
		elsif(counter = "110") then
			counter <= "000";
		end if;
	end if;
end process;
	Q <= counter;
end behave;