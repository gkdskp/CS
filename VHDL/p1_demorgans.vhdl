-- Verify De-Morgan's theorems for two variables

library ieee;
use ieee.std_logic_1164.all;

entity deMorganVerification is
	port (
		a, b: in std_ulogic;
		c1, c2, c3, c4: out std_ulogic
	);
end deMorganVerification;

architecture behave of deMorganVerification is
begin
	c1 <= not(a or b);
	c2 <= not(a) and not(b);
	c3 <= not(a and b);
	c4 <= not(a) or not(b);
end behave;