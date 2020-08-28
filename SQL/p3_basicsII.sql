/*
1. Create a CAR database with the following details.
+----+--------+------------+---------+-------------+
| id | name   | company    | country | approxprice |
+----+--------+------------+---------+-------------+
|  1 | Beat   | Chevrolet  | USA     |         4.0 |
|  2 | Swift  | Maruti     | Japan   |         6.0 |
|  3 | Escort | Ford       | USA     |         4.2 |
|  4 | Sunny  | Nissan     | Japan   |         8.0 |
|  5 | Beetle | Volkswagen | Germany |        21.0 |
|  6 | Etios  | Toyota     | Japan   |         7.2 |
|  7 | Sail   | Chevrolet  | USA     |         5.0 |
|  8 | Aria   | Tata       | India   |         7.0 |
|  9 | Passat | Volkswagen | Germany |        25.0 |
| 10 | SX4    | Maruti     | Japan   |         6.7 |
+----+--------+------------+---------+-------------+
2. List the car companies in the database.
3. List the names of countries with car production companies.
4. List the details of cars within a price range 4 to 7 lakhs.
5. List the name and company of all the cars originating from India and
having price <= 8 lakhs.
6. List the names, companies and countries of cars either from Nissan or
from Germany.
7. List the names of all cars produced by (Maruti,Ford). Use SQL IN
statement.
8. Alter the table cars to add a new field year (model release year). Update
the year column for all the rows in the database.
9. Retrieve the names of all cars and display names under 'Car_name'.
10. Rename the attribute name to car_name.
11. List the car manufactured by Toyota (to be displayed as cars_Toyota).
12. List the details of all cars in alphabetical order.
13. List the details of all cars from cheapest to costliest.
*/

CREATE TABLE CAR(
	id INT PRIMARY KEY,
	name VARCHAR(10),
	company VARCHAR(20),
	country VARCHAR(10),
	approxprice DECIMAL(1, 3)
);
INSERT INTO CAR 
VALUES
	(1, 'Beat', 'Chevrolet', 'USA', 4),
	(2, 'Swift', 'Maruti', 'Japan', 6),
	(3, 'Escort', 'Ford', 'USA', 4.2),
	(4, 'Sunny', 'Nissan', 'Japan', 8),
	(5, 'Beetle', 'Volkswagen', 'Germany', 21),
	(6, 'Etios', 'Toyota', 'Japan', 7.2),
	(7, 'Sail', 'Chevrolet', 'USA', 5),
	(8, 'Aria', 'Tata', 'India', 7),
	(9, 'Passat', 'Volkswagen', 'Germany', 25),
	(10, 'SX4', 'Maruti', 'Japan', 6.7);

SELECT company 
FROM CAR;

SELECT country 
FROM CAR;

SELECT *
FROM CAR
WHERE approxprice>4 AND approxprice<7;

SELECT name, company
FROM CAR
WHERE country='India' AND approxprice<=8;

SELECT name, company, country
FROM CAR
where company='Nissan' OR country='Germany';

SELECT name
FROM CAR
WHERE company IN ('Maruti', 'Ford');

ALTER TABLE CAR
ADD COLUMN year INT;
UPDATE CAR
SET year=2010;

SELECT name AS 'Car_name'
FROM CAR

ALTER TABLE CAR
CHANGE COLUMN name Car_name VARCHAR(10);

SELECT Car_name AS 'cars_Toyota'
FROM CAR
WHERE company='Toyota';

SELECT *
FROM CAR
ORDER BY Car_name ASC;

SELECT *
FROM CAR
ORDER BY approxprice ASC;

