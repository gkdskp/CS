/*
1. Insert records into the employee table (Fields : EmpId, Ename,
Designation, Salary, Dept.id) created.

2. Display the details of all the employees.
3. Display the employee numbers, names and designation of all employees.
4. Suppose the emp_no 68454 has left the company. Delete the employee
from the database.
5. Suppose a new employee joins the company under department 2001 as
an analyst. The salary of the employee is not yet fixed. Add his record to
the database.
Emp_no Ename Designation Salary Dept.Id
66928 BLAZE MANAGER 55000 3001
67832 CLARE MANAGER 51000 1001
65646 JONAS MANAGER 59140 2001
67858 SCARLET ANALYST 62000 2001
69062 FRANK ANALYST 62000 2001
63679 SANDRINE CLERK 18000 2001
64989 ADELYN SALESMAN 34000 3001
65271 WADE SALESMAN 27000 3001
66564 MADDEN SALESMAN 27000 3001
68454 TUCKER SALESMAN 32000 3001
68736 ADNRES CLERK 24000 2001
69000 JULIUS CLERK 21000 3001
69324 MARKER CLERK 28000 1001
6. Find the details of employees with salary > 25000 working in department
with id 2001.
7. Suppose the newly added employee's salary is now fixed. Add his salary
details.
8. Suppose the employee ADELYN is now promoted as Analyst. Update his
designation and salary.
9. Display the names of all managers and analysts.
10. Retrieve the names of all employees whose salary is between 30000
and 60000.
11. A salary hike is now announced by dept. 2001. Update the salary of all
their employees by 5%.
12. List all employees whose salary is less than 30000 or working for dept.
1001.
*/

CREATE TABLE Employee(
	Emp_no INT(6) PRIMARY KEY,
	Ename VARCHAR(10),
	Designation VARCHAR(10),
	Salary INT(6),
	Dept_id INT(4)
);
INSERT INTO Employee
VALUES
	(66928, "BLAZE", "MANAGER", 55000, 3001),
	(67832, "CLARE", "MANAGER", 51000, 1001),
	(65646, "JONAS", "MANAGER", 59140, 2001),
	(67858, "SCARLET", "ANALYST", 62000, 2001),
	(69062, "FRANK", "ANALYST", 62000, 2001),
	(63679, "SANDRINE", "CLERK", 18000, 3001),
	(64989, "ADELYN", "SALESMAN", 34000, 3001),
	(65271, "WADE", "SALESMAN", 27000, 3001),
	(66564, "MADDEN", "SALESMAN", 27000, 3001),
	(68454, "TUCKER", "SALESMAN", 32000, 3001),
	(68736, "ANDRES", "CLERK", 24000, 2001),
	(69000, "JULIUS", "CLERK", 21000, 3001),
	(69324, "MARKER", "CLERK", 28000, 1001);

SELECT * FROM Employee;

SELECT Emp_no, Ename, Designation
FROM Employee;

DELETE FROM Employee
WHERE Emp_no=68454;

INSERT INTO Employee
(Emp_no, Ename, Designation, Dept_id) VALUES
	(69876, "Rahul", "ANALYST", 2001);

SELECT * FROM Employee
WHERE Salary>25000 AND Dept_id=2001;

UPDATE Employee
SET Salary=40000
WHERE Emp_no=69876;

UPDATE Employee
SET Designation="ANALYST", Salary=40000
WHERE Ename="ADELYN";

SELECT * FROM Employee
WHERE Designation="MANAGER" OR Designation="ANALYST";

SELECT * FROM Employee
WHERE Salary>30000 AND Salary<60000;

UPDATE Employee
SET Salary = Salary + Salary*(0.05)
WHERE Dept_id=2001;

SELECT * FROM Employee
WHERE Salary<30000 OR Dept_id=1001;

