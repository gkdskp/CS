-- Testbench for BCDAdder

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BCDAdder_tb is 
end BCDAdder_tb;

architecture test of BCDAdder_tb is
	component BCDAdder
	port (
		A, B: in unsigned(3 downto 0);
		S: out unsigned(3 downto 0);
		Cout: out std_logic
	);
	end component;

	signal A, B, S: unsigned(3 downto 0);
	signal Cout: std_ulogic;

begin
	uut: BCDAdder port map (
		A => A,
		B => B,
		S => S,
		Cout => Cout
	);

	stim_proc: process begin
		A <= "0011";
		B <= "1001";
		wait for 50 ns;

		A <= "0011";
		B <= "0110";
		wait for 50 ns;

		wait;
	end process;
end;