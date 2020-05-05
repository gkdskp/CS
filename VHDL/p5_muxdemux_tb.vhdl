-- Testbench for multiplexer/demultiplexer/fullAdder

library ieee;
use ieee.std_logic_1164.all;

entity multiplexer_tb is 
end multiplexer_tb;

architecture test of multiplexer_tb is
	component multiplexer
	port (
		D0, D1, D2, D3, S1, S0: in std_ulogic;
		Y: out std_ulogic
	);
	end component;

	signal D0, D1, D2, D3, S1, S0: std_ulogic := '0';
	signal Y: std_ulogic;

begin
	uut: multiplexer port map (
		D0 => D0,
		D1 => D1,
		D2 => D2,
		D3 => D3,
		S1 => S1,
		S0 => S0,
		Y => Y
	);

	process begin
		wait for 50 ns;

		D0 <= '1';
		D1 <= '0';
		D2 <= '1';
		D3 <= '0';

		S0 <= '0'; S1 <= '0';
		wait for 50 ns;

		S0 <= '0'; S1 <= '1';
		wait for 50 ns;

		S0 <= '1'; S1 <= '0';
		wait for 50 ns;

		S0 <= '1'; S1 <= '1';
		wait for 50 ns;

		wait;
	end process;
end;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity demultiplexer_tb is 
end demultiplexer_tb;

architecture test of demultiplexer_tb is
	component demultiplexer
	port (
		D, S1, S0: in std_ulogic;
		Y3, Y2, Y1, Y0: out std_ulogic
	);
	end component;

	signal D, S1, S0: std_ulogic := '0';
	signal Y3, Y2, Y1, Y0: std_ulogic;

begin
	uut: demultiplexer port map (
		D => D,
		S1 => S1,
		S0 => S0,
		Y3 => Y3,
		Y2 => Y2,
		Y1 => Y1,
		Y0 => Y0
	);

	process begin
		wait for 50 ns;

		D <= '1';

		S0 <= '0'; S1 <= '0';
		wait for 50 ns;

		S0 <= '0'; S1 <= '1';
		wait for 50 ns;

		S0 <= '1'; S1 <= '0';
		wait for 50 ns;

		S0 <= '1'; S1 <= '1';
		wait for 50 ns;

		wait;
	end process;
end;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity fullAdder_tb is 
end fullAdder_tb;

architecture test of fullAdder_tb is
	component fullAdder
	port (
		A, B, Cin: in std_ulogic;
		S, Cout: out std_ulogic
	);
	end component;

	signal A, B, Cin: std_ulogic := '0';
	signal S, Cout: std_ulogic;

begin
	uut: fullAdder port map (
		A => A,
		B => B,
		Cin => Cin,
		S => S,
		Cout => Cout
	);

	process begin
		wait for 50 ns;

		A <= '0';
		B <= '0';
		Cin <= '0';
		wait for 50 ns;

		A <= '0';
		B <= '0';
		Cin <= '1';
		wait for 50 ns;

		A <= '0';
		B <= '1';
		Cin <= '0';
		wait for 50 ns;

		A <= '0';
		B <= '1';
		Cin <= '1';
		wait for 50 ns;

		A <= '1';
		B <= '0';
		Cin <= '0';
		wait for 50 ns;

		A <= '1';
		B <= '0';
		Cin <= '1';
		wait for 50 ns;

		A <= '1';
		B <= '1';
		Cin <= '0';
		wait for 50 ns;

		A <= '1';
		B <= '1';
		Cin <= '1';
		wait for 50 ns;

		wait;
	end process;
end;