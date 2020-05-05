-- Testbench for upCounter/downCounter

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity upCounter_tb is
end upCounter_tb;

architecture test of upCounter_tb is
	component upCounter is
		port (
			CLK, CLR: in std_ulogic;
			Q: out unsigned(3 downto 0)
		);
	end component;

	signal CLK, CLR: std_ulogic;
	signal Q: unsigned(3 downto 0);

begin
	uut: upCounter port map (
		CLK => CLK,
		CLR => CLR,
		Q => Q
	);

	clock_proc: process begin 
		CLK <= '0';
		wait for 10 ns;
		CLK <= '1';
		wait for 10 ns;
	end process;

	stim_proc: process begin
		CLR <= '1';
		wait for 20 ns;
		CLR <= '0';
		wait;
	end process;

	stop_proc: process begin
		wait for 10000 ns;
		assert false
			report "THIS IS NOT AN ERROR. Simulation finished successfully"
			severity failure;
	end process;
end;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity downCounter_tb is
end entity;

architecture test of downCounter_tb is
	component downCounter is
		port (
			CLK, CLR: in std_ulogic;
			Q: out unsigned(2 downto 0)
		);
	end component;

	signal CLK, CLR: std_ulogic;
	signal Q: unsigned(2 downto 0);

begin
	uut: downCounter port map (
		CLK => CLK,
		CLR => CLR,
		Q => Q
	);

	clock_proc: process begin
		CLK <= '1';
		wait for 10 ns;
		CLK <= '0';
		wait for 10 ns;
	end process;

	stim_proc: process begin
		CLR <= '1';
		wait for 20 ns;
		CLR <= '0';
		wait;
	end process;

	stop_proc: process begin
		wait for 10000 ns;
		assert false
			report "THIS IS NOT AN ERROR. Simulation finished successfully"
			severity failure;
	end process;
end;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity customCounter_tb is
end customCounter_tb;

architecture test of customCounter_tb is
	component customCounter is
		port (
			CLK, CLR: in std_ulogic;
			Q: out unsigned(2 downto 0)
		);
	end component;

	signal CLK, CLR: std_ulogic;
	signal Q: unsigned(2 downto 0);

begin
	uut: customCounter port map (
		CLK => CLK,
		CLR => CLR,
		Q => Q
	);

	clock_proc: process begin
		CLK <= '1';
		wait for 10 ns;
		CLK <= '0';
		wait for 10 ns;
	end process;

	stim_proc: process begin
		CLR <= '1';
		wait for 20 ns;
		CLR <= '0';
		wait;
	end process;

	stop_proc: process begin
		wait for 10000 ns;
		assert false
			report "THIS IS NOT AN ERROR. Simulation finished successfully"
			severity failure;
	end process;
end;