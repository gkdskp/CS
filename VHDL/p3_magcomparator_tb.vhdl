-- Testbench for magnitudeComparator

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity magnitudeComparator_tb is
end magnitudeComparator_tb;

architecture test of magnitudeComparator_tb is
	component magnitudeComparator
	port (
		A, B: in std_logic_vector(1 downto 0);
		greater, equal, smaller: out std_ulogic
	);
	end component;

	signal A, B: std_logic_vector(1 downto 0) := (others => '0');
	signal greater, equal, smaller: std_ulogic;

begin
	uut: magnitudeComparator port map (
		A => A,
		B => B,
		greater => greater,
		equal => equal,
		smaller => smaller
	);

	process begin
		A <= std_logic_vector(to_unsigned(0, 2));
		B <= std_logic_vector(to_unsigned(1, 2));
		wait for 50 ns;

		A <= std_logic_vector(to_unsigned(3, 2));
		B <= std_logic_vector(to_unsigned(2, 2));
		wait for 50 ns;

		A <= std_logic_vector(to_unsigned(0, 2));
		B <= std_logic_vector(to_unsigned(0, 2));
		wait for 50 ns;

		wait;
	end process;
end;