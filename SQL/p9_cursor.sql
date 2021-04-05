/*
1. Create table student (id, name, m1, m2, m3, grade).Insert 5 tuples into it. Find the total,
calculate grade and update the grade in the table.
2. Create bank details(accno, name, balance,adate).Calculate the interest of the amount and
insert into a new table with fields(accno, interest). Interest= 0.08*balance.
3. Create table people_list(id, name, dt_joining, place).If persons experience
is above 10 years, put the tuple in table exp_list(id, name, experience).
Create table employee list(id,name,monthly salary).
i)If: annual salary <60000, increment monthly salary by 25%
ii)between 60000 and 200000, increment by 20%
iii)between 200000 and 500000, increment by 15%
iv)annual salary > 500000, increment monthly salary by 10%.
*/

CREATE TABLE student (
	id INT,
    name VARCHAR,
	m1 INT,
	m2 INT,
	m3 INT,
	grade CHAR
);
INSERT INTO student
(id, name, m1, m2, m3) VALUES
	(10, 'Name1', 58, 61, 29),
	(30, 'Name2', 60, 60, 60),
	(12, 'Name3', 50, 67, 75),
	(13, 'Name4', 59, 69, 99),
	(21, 'Name5', 10, 99, 10);
SELECT * FROM student;
CREATE OR REPLACE FUNCTION calculate_grade() RETURNS VOID AS $$
DECLARE
	total INT;
	grde CHAR;
	record_student RECORD;
	cursor_student CURSOR
	FOR SELECT * FROM student;
BEGIN
	OPEN cursor_student;
	LOOP
		FETCH cursor_student INTO record_student;
		EXIT WHEN NOT FOUND;
		total = record_student.m1 + record_student.m2 + record_student.m3;
		IF total > 240 THEN grde = 'A';
		ELSIF total > 180 THEN grde = 'B';
		ELSIF total > 120 THEN grde = 'C';
		ELSIF total > 60 THEN grde = 'D';
		ELSE grde = 'F';
		END IF;
		UPDATE student SET grade=grde WHERE id=record_student.id;
	END LOOP;
	CLOSE cursor_student;
END;
$$ LANGUAGE plpgsql;
SELECT calculate_grade();
SELECT * FROM student;

CREATE TABLE bank_details (
	accno INT,
	name VARCHAR(10),
	balance INT,
	adate DATE
);
CREATE TABLE bank_interest (
	accno INT,
	interest REAL
);
INSERT INTO bank_details 
VALUES
	(1001, 'Name1', 20000, '10-DEC-2019'),
	(1012, 'Name2', 25000, '17-APR-2019');
CREATE OR REPLACE FUNCTION calculate_interest()
RETURNS VOID AS $$
DECLARE
	interest INT;
	account RECORD;
	account_cursor CURSOR
	FOR SELECT * FROM bank_details;
BEGIN
	OPEN account_cursor;
	LOOP
		FETCH account_cursor INTO account;
		EXIT WHEN NOT FOUND;
		interest = 0.8*account.balance;
		INSERT INTO bank_interest VALUES (account.accno, interest);
	END LOOP;
	CLOSE account_cursor;
END;
$$ LANGUAGE plpgsql;
SELECT calculate_interest();
SELECT * FROM bank_interest;

CREATE TABLE people_list (
	id INT,
	name VARCHAR(10),
	dt_joining DATE,
	place VARCHAR(5)
);
CREATE TABLE exp_list(
	id INT,
	name VARCHAR,
	experience INT
);
INSERT INTO people_list
VALUES
	(101, 'Name1', '10-APR-2020', 'City1'),
	(101, 'Name2', '10-APR-2010', 'City2'),
	(101, 'Name3', '10-APR-2000', 'City3');
SELECT * FROM people_list;
CREATE OR REPLACE FUNCTION calculate_exp()
RETURNS VOID AS $$
DECLARE
	exp INT;
	person RECORD;
	today DATE;
	person_cursor CURSOR FOR SELECT * FROM people_list;
BEGIN
	OPEN person_cursor;
	SELECT current_date INTO today;
	LOOP
		FETCH person_cursor INTO person;
		EXIT WHEN NOT FOUND;
		SELECT DATE_PART('year', today::date) - DATE_PART('year', person.dt_joining::date)
		INTO exp;
		IF exp > 10 THEN
			INSERT INTO exp_list VALUES (person.id, person.name, exp);
		END IF;
	END LOOP;
	CLOSE person_cursor;
END;
$$ LANGUAGE plpgsql;
SELECT calculate_exp();
SELECT * FROM exp_list;