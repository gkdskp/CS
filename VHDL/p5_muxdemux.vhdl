-- Implement multiplexer and demultiplexer circuits using logic gates.
-- Implement a full adder circuit with multiplexers.

library ieee;
use ieee.std_logic_1164.all;

entity multiplexer is 
	port (
		D0, D1, D2, D3, S1, S0: in std_ulogic;
		Y: out std_ulogic
	);
end multiplexer;

architecture behave of multiplexer is
begin
	Y <= (D0 and not(S0) and not(S1))
		  or (D1 and not(S1) and S0)
		  or (D2 and S1 and not(S0))
		  or (D3 and S1 and S0); 
end behave;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity demultiplexer is
	port (
		D, S1, S0: in std_ulogic;
		Y3, Y2, Y1, Y0: out std_ulogic
	);
end demultiplexer;

architecture behave of demultiplexer is
begin
	Y3 <= S1 and S0 and D;
	Y2 <= S1 and not(S0) and D;
	Y1 <= not(S1) and S0 and D;
	Y0 <= not(S1) and not(S0) and D;
end behave;

--------------------------------------------
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity fullAdder is
	port (
		A, B, Cin: in std_ulogic;
		S, Cout: out std_ulogic
	);
end fullAdder;

architecture behave of fullAdder is

component multiplexer
	port (
		D0, D1, D2, D3, S1, S0: in std_ulogic;
		Y: out std_ulogic
	);
end component;

signal NOTA: std_ulogic;

begin
	NOTA <= not(A);
	M1: multiplexer port map (
		A, NOTA, NOTA, A, B, Cin, S
	);

	M2: multiplexer port map (
		'0', A, A, '1', B, Cin, Cout 
	);
end;