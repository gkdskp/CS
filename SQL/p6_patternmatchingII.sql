/*
Use the system table DUAL for the following questions:
1. Find the reverse of the string ‘ nmutuAotedOehT’.
2. Use LTRIM function on ‘123231xyzTech’ so as to obtain the output ‘Tech’
3. Use RTRIM function on ‘Computer ‘ to remove the trailing spaces.
4. Perform RPAD on ‘computer’ to obtain the output as ‘computerXXXX’
5. Use POSITION function to find the first occurrence of ‘e’ in the string
‘Welcome to Kerala’.
6. Perform INITCAP function on ‘mARKcALAwaY’.
7. Find the length of the string ‘Database Management Systems’..
8. Concatenate the strings ‘Julius’ and ‘Caesar’.
9. Use SUBSTR function to retrieve the substring ‘is’ from the string ‘India is
my country’.
10. Use INSTR function to find the second occurrence of ‘k’ from the last. The
string is ‘Making of a King’.
*/

SELECT REVERSE('nmutuAotedOehT');

SELECT LTRIM('’123231XYZTECH', '123XYZ');

SELECT RTRIM('Computer   ');

SELECT RPAD('computer', 12, 'X');

SELECT POSITION('e' in 'Welcome to Kerala');

SELECT INITCAP('mARKcALAwaY');

SELECT LENGTH('Database Management Systems');

SELECT CONCAT('Julius', 'Caesar');

SELECT SUBSTR('India is my country', 7, 2);

SELECT INSTR('Making of a King', -1, 2);

