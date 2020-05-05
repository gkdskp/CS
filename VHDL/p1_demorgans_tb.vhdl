-- Testbench for deMorganVerification

library ieee;
use ieee.std_logic_1164.all;

entity deMorganVerification_tb is
end deMorganVerification_tb;

architecture test of deMorganVerification_tb is
	component deMorganVerification
	port (
		a, b: in std_ulogic;
		c1, c2, c3, c4: out std_ulogic
	);
	end component;

	signal a, b, c1, c2, c3, c4: std_ulogic;

begin
	uut: deMorganVerification port map (
		a => a,
		b => b,
		c1 => c1,
		c2 => c2,
		c3 => c3,
		c4 => c4
	);

	process begin
		a <= '0';
		b <= '0';
		wait for 50 ns;

		a <= '0';
		b <= '1';
		wait for 50 ns;

		a <= '1';
		b <= '0';
		wait for 50 ns;

		a <= '1';
		b <= '1';
		wait for 50 ns;

		wait;
	end process;
end;