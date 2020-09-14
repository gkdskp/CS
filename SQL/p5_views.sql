/*
1. Create the following tables with given constraints. 
	a. Create a table named Subjects with the given attributes. 
		• Sub_id ( Should not be NULL) 
		• Sub_name (Should not be NULL) 
		• Populate the database. Make sure that all constraints are working properly. 
		+--------+-----------+
		| Sub_id | Sub_name  |
		+--------+-----------+
		|      1 | Maths     |
		|      2 | Physics   |
		|      3 | Chemistry |
		|      4 | English   |
		+--------+-----------+

		i. Alter the table to set Sub_id as the primary key. 
	b. Create a table named Staff with the given attributes. 
		• Staff_id (Should be UNIQUE) 
		• Staff_name 
		• Dept 
		• Age ( Greater than 22) 
		• Salary (Less than 35000) 
		+----------+------------+------------+------+--------+
		| Staff_id | Staff_name | Dept       | Age  | Salary |
		+----------+------------+------------+------+--------+
		|        1 | John       | Purchasing |   24 |  30000 |
		|        2 | Sera       | Sales      |   25 |  20000 |
		|        3 | Jane       | Sales      |   28 |  25000 |
		+----------+------------+------------+------+--------+

		i. Delete the check constraint imposed on the attribute Salary. 
		ii. Delete the unique constraint on the attribute Staff_id. 
	c. Create a table named Bank with the following attributes. 
		• Bank_code (To be set as Primary Key, type= varchar(3) ) 
		• Bank_name (Should not be NULL) 
		• Head_office 
		• Branches (Integer value greater than Zero) 
		i. Make sure that all constraints are working properly. All constraints 
		have to be set after creating the table. 
		+-----------+-----------+-------------+----------+
		| Bank_code | Bank_name | Head_office | Branches |
		+-----------+-----------+-------------+----------+
		| AAA       | SIB       | Ernakulam   |        6 |
		| BBB       | Federal   | Kottayam    |        5 |
		| CCC       | Canara    | Trivandrum  |        3 |
		+-----------+-----------+-------------+----------+

	d. Create a table named Branch with the following attributes. 
		• Branch_id (To be set as Primary Key) 
		• Branch_name (Set Default value as ‘New Delhi") 
		• Bank_id (Foreign Key:- Refers to bank code of Bank table) 
		i. Populate the database. Make sure that all constraints are working 
		properly. 
		
		ii. During database population, demonstrate how the DEFAULT 
		Constraint is satisfied. (Insert values with branch as “New Delhi”) iii. Delete the bank with bank code "SBT" and make sure that the 
		corresponding entries are getting deleted from the related tables. iv. Drop the Primary Key using ALTER command 
	2. Create a View named sales_staff to hold the details of all staff working in sales 
	Department. (Refer to table Staff in question 1(b)) 
	3. Drop table branch. Create another table named branch and name all the constraints as 
	given below: 
	• Constraint name Column Constraint 
	• Pk branch_id Primary key 
	• Df branch_name Default :"New Delhi" 
	• Fk bankid Foreign key/References 
	i. Delete the default constraint in the table ii. Delete the primary key constraint 
	4. Update the view sales staff to include the details of staff belonging to sales department whose salary is greater than 20000. Drop the table EMP_NEW 
	5. Delete the view sales staff.
*/

CREATE TABLE IF NOT EXISTS Subjects (
	Sub_id INT NOT NULL,
	Sub_name VARCHAR(10) NOT NULL
);
INSERT INTO Subjects
VALUES
	(1, "Maths"),
	(2, "Physics"),
	(3, "Chemistry"),
	(4, "English");
ALTER TABLE Subjects
ADD PRIMARY KEY(Sub_id);
CREATE TABLE IF NOT EXISTS Staff (
	Staff_id INT NOT NULL UNIQUE,
	Staff_name VARCHAR(10),
	Dept VARCHAR(10),
	Age INT,
	Salary INT,
	CHECK(AGE > 22), 
	CONSTRAINT Staff_Staff_id_key UNIQUE (Staff_id),
	CONSTRAINT Staff_Salary_check CHECK(Salary < 35000)
);
INSERT Into Staff
VALUES
	("1","John","Purchasing","24","30000"),
	("2","Sera","Sales","25","20000"),
	("3","Jane","Sales","28","25000");
ALTER TABLE Staff
DROP CONSTRAINT Staff_Salary_check;
ALTER TABLE Staff
DROP CONSTRAINT Staff_Staff_id_key;
CREATE TABLE IF NOT EXISTS Bank (
	Bank_code VARCHAR(3),
	Bank_name VARCHAR(10),
	Head_office VARCHAR(10),
	Branches INT
);
ALTER TABLE Bank
ADD CONSTRAINT primary_key PRIMARY KEY (Bank_code);
ALTER TABLE Bank
ADD CONSTRAINT branch_office CHECK (Branches > 0);
INSERT INTO Bank
VALUES
	("AAA", "SIB", "Ernakulam", 6),
	("BBB", "Federal", "Kottayam", 5),
	("CCC", "Canara", "Trivandrum", 3);
CREATE TABLE IF NOT EXISTS Branch (
	Branch_id INT,
	Branch_name VARCHAR(10) DEFAULT 'New Delhi',
	Bank_id VARCHAR(3),
	CONSTRAINT Branch_pkey PRIMARY KEY (Branch_id) 
);
ALTER TABLE Branch
ADD CONSTRAINT Branch_Bank_id_fkey 
	FOREIGN KEY (Bank_id) REFERENCES Bank(Bank_code) ON UPDATE CASCADE ON DELETE CASCADE;
INSERT INTO Branch
VALUES
	(1, "Kottayam", "CCC"),
	(2, NULL, "AAA");
INSERT INTO Bank
VALUES ("SBT", "Indian", "Delhi", 7);
INSERT INTO Branch
VALUES (5, "Calicut", "SBT");
DELETE FROM Bank
WHERE Bank_code='SBT';
ALTER TABLE Branch
DROP CONSTRAINT Branch_pkey;
INSERT INTO Branch
VALUES (1, "PPP", "CCC");

CREATE VIEW sales_staff AS 
	(SELECT * FROM Staff WHERE Dept="SALES");
SELECT * FROM sales_staff;

DROP TABLE Branch;
CREATE TABLE Branch (
	Branch_id INT,
	Branch_name VARCHAR(10) CONSTRAINT Df DEFAULT 'New Delhi',
	Bank_id VARCHAR(3),
	CONSTRAINT Pk PRIMARY KEY (Branch_id),
	CONSTRAINT Fk FOREIGN KEY (Bank_id) REFERENCES Bank (Bank_code) ON UPDATE CASCADE ON DELETE CASCADE
);
ALTER TABLE Branch 
DROP CONSTRAINT Df;
ALTER TABLE Branch
DROP CONSTRAINT Pk;

CREATE OR REPLACE VIEW sales_staff 
AS (SELECT * FROM Staff WHERE Salary > 20000 AND Dept="Sales");

DROP VIEW sales_staff;