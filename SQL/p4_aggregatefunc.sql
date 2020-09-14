/*
1. Create a table named Student and populate the table. 
	a. The table contains the marks of 10 students for 3 subjects(Physics, Chemistry, 
Mathematics). 
	b. The total marks for physics and chemistry is 25, while for mathematics it is 50. 
	c. The pass mark for physics and chemistry is 12 and for mathematics it is 25. 
	d. A student is awarded a ‘Pass’ if he has passed all the subjects. 
+----------+----------+---------+-----------+-------------+
| roll_num | name     | physics | chemistry | mathematics |
+----------+----------+---------+-----------+-------------+
|        1 | Adam     |      20 |        20 |          33 |
|        2 | Bob      |      18 |         9 |          41 |
|        3 | Bright   |      22 |         7 |          31 |
|        4 | Duke     |      13 |        21 |          20 |
|        5 | Elvin    |      14 |        22 |          23 |
|        6 | Fetcher  |       2 |        10 |          48 |
|        7 | Georgina |      22 |        12 |          22 |
|        8 | Mary     |      24 |        14 |          31 |
|        9 | Tom      |      19 |        15 |          24 |
|       10 | Zack     |       8 |        20 |          36 |
+----------+----------+---------+-----------+-------------+
2. Find the class average for the subject ‘Physics’ 
3. Find the highest marks for mathematics (To be displayed as highest_marks_maths). 
4. Find the lowest marks for chemistry(To be displayed as lowest_mark_chemistry) 
5. Find the total number of students who has got a ‘pass’ in physics. 
6. Generate the list of students who have passed in all the subjects. 
7. Generate a rank list for the class. Indicate Pass/Fail. 
8. Find pass percentage of the class for mathematics. 
9. Find the overall pass percentage for all class. 
10. Find the class average. 
11. Find the total number of students who have got a Pass.
*/

CREATE TABLE IF NOT EXISTS Student (
	roll_num INT PRIMARY KEY,
	name VARCHAR(10),
	physics INT,
	chemistry INT,
	mathematics INT
);
INSERT INTO Student 
VALUES
	(1, "Adam", 20, 20, 33), 
	(2, "Bob", 18, 9, 41), 
	(3, "Bright", 22, 7, 31),
	(4, "Duke", 13, 21, 20),
	(5, "Elvin", 14, 22, 23),
	(6, "Fetcher", 2, 10, 48),
	(7, "Georgina", 22, 12, 22), 
	(8, "Mary", 24, 14, 31),
	(9, "Tom", 19, 15, 24),
	(10, "Zack", 8, 20, 36);
SELECT * FROM Student;

SELECT AVG(physics)
FROM Student;

SELECT MAX(mathematics) as 'highest_marks_maths'
FROM Student;

SELECT MIN(chemistry) as 'lowest_mark_chemistry'
FROM Student;

SELECT COUNT(*)
FROM Student
WHERE physics >= 12;

SELECT *
FROM Student
WHERE physics >= 12 AND chemistry >= 12 AND mathematics >= 25;

ALTER TABLE Student
ADD COLUMN Status VARCHAR(4) DEFAULT 'Fail';
UPDATE Student
SET Status='Pass'
WHERE physics >= 12 AND chemistry >= 12 AND mathematics >= 25;
SELECT *
FROM Student
ORDER BY (physics+chemistry+mathematics);

SELECT 100*COUNT(*)/(SELECT COUNT(*) FROM Student) as 'math_pass_percentage'
FROM Student
WHERE mathematics >= 25;

SELECT 100*COUNT(*)/(SELECT COUNT(*) FROM Student) as 'pass_percentage'
FROM Student
WHERE Status='Pass';

SELECT AVG(physics+chemistry+mathematics)
FROM Student;

SELECT COUNT(*) as 'passed'
FROM Student
WHERE Status='Pass';