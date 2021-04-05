/* 
Create the table named acct_details and populate the table
+-----------+------------+-------------------+---------------+
| acct_no   | branch     | name              | phone         |
+-----------+------------+-------------------+---------------+
| A40123401 | Chicago    | Mike Adams        | (378)400-1234 |
| A40123402 | Miami      | Diana George      | (372)420-2345 |
| B40123403 | Miami      | Diaz Elizabeth    | (371)450-3456 |
| B40123404 | Atlanta    | Jeoffrey George   | (370)460-4567 |
| B40123405 | New York   | Jennifer Kaitlyn  | (373)470-5678 |
| C40123406 | Chicago    | Kaitlyn Vincent   | (318)200-3235 |
| C40123407 | Miami      | Abraham Gottfield | (328)300-2256 |
| C50123408 | New Jersey | Stacy Williams    | (338)400-5237 |
| D50123409 | New York   | Catherine George  | (348)500-6228 |
| D50123410 | Miami      | Oliver Scott      | (358)600-7230 |
+-----------+------------+-------------------+---------------+

1. Find the names of all people starting on the alphabet ‘D’.
2. List the names of all branches containing the substring ‘New’
3. List all the names in Upper Case Format
4. List the names where the 4th letter is ‘n’ and last letter is ‘n’
5. List the names starting on ‘D’, 3rd letter is ‘a’ and contains the substring ‘Eli’
6. List the names of people whose account number ends in ‘6’.
7. Update the table so that all the names are in Upper Case Format
8. List the names of all people ending on the alphabet ‘t’
9. List all the names in reverse
10. Display all the phone numbers including US Country code ( +1). For eg:
(378)400-1234 should be displayed as +1(378)400-1234. Use LPAD function.
11. Display all the account numbers. The starting alphabet associated with the
Account No should be removed. Use LTRIM function.
12. Display the details of all people whose account number starts in ‘4’ and name
contains the sub string ‘Williams’.
*/

CREATE TABLE acct_details (
	acct_no CHAR(9) PRIMARY KEY,
	branch VARCHAR(10),
	name VARCHAR(30),
	phone VARCHAR(15)	
);
INSERT INTO acct_details 
VALUES ('A40123401','Chicago' ,'Mike Adams' ,'(378)400-1234'),
	('A40123402','Miami','Diana George','(372)420-2345'),
	('B40123403','Miami','Diaz Elizabeth','(371)450-3456'),
	('B40123404','Atlanta','Jeoffrey George','(370)460-4567'),
	('B40123405','New York','Jennifer Kaitlyn','(373)470-5678'),
	('C40123406','Chicago','Kaitlyn Vincent','(318)200-3235'),
	('C40123407','Miami','Abraham Gottfield','(328)300-2256'),
	('C50123408','New Jersey','Stacy Williams','(338)400-5237'),
	('D50123409','New York','Catherine George','(348)500-6228'),
	('D50123410','Miami','Oliver Scott','(358)600-7230');
SELECT * FROM acct_details;

SELECT name FROM acct_details
WHERE name LIKE 'D%';

SELECT branch FROM acct_details
WHERE branch LIKE '%New%';

SELECT UPPER(name) FROM acct_details;

SELECT name FROM acct_details
WHERE name LIKE '___n%n';

SELECT name FROM acct_details
WHERE name LIKE 'D_a%' and name LIKE '%Eli%';

SELECT name FROM acct_details
WHERE acct_no LIKE '%6';

UPDATE acct_details
SET name=UPPER(name);
SELECT * FROM acct_details;

SELECT name FROM acct_details
WHERE LOWER(name) LIKE '%t';

SELECT REVERSE(name) AS reverse_name FROM acct_details;

SELECT LPAD(phone, 15, '+1') FROM acct_details;

SELECT LTRIM(acct_no, 'ABCD') AS accnt_no, name, branch, phone
FROM acct_details;

SELECT * FROM acct_details
WHERE UPPER(name) LIKE '%WILLIAMS%' or acct_no LIKE '_4%';
