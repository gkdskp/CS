-- Design and set up a 2-bit magnitude comparator using basic gates

library ieee;
use ieee.std_logic_1164.all;

entity magnitudeComparator is
	port (
		A, B: in std_logic_vector(1 downto 0);
		greater, equal, smaller: out std_ulogic
	);
end magnitudeComparator;

architecture behave of magnitudeComparator is
begin
	greater <= (A(1) and not(B(1)))
				or (A(0) and not(B(1)) and not(B(0)))
				or (A(1) and A(0) and not(B(0)));
	
	equal <= (A(0) xnor B(0)) and (A(1) xnor B(1));

	smaller <= (not(A(1)) and B(1))
				or (not(A(0)) and B(1) and B(0))
				or (not(A(1)) and not(A(0)) and B(0));
end behave;