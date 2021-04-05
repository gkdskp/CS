/*
1. Create Items, Orders, Customers, Delivery tables, populate them with appropriate data
and display the tables.
	i. Items Table
+--------+-------------------+-------------+-------+---------+
| itemid | itemname          | category    | price | instock |
+--------+-------------------+-------------+-------+---------+
|      1 | Xiomi             | electronics |  1001 |       6 |
|      2 | Iphone X          | electronics |  7007 |       6 |
|      3 | One Plus 7        | electronics |  6006 |       2 |
|      4 | Samsung Galaxy S4 | electronics |  5005 |       1 |
|      5 | sony z5 premium   | electronics |  5005 |       1 |
+--------+-------------------+-------------+-------+---------+

	ii. Customers Table
+--------+----------+----------------+------------+
| custid | custname | address        | state      |
+--------+----------+----------------+------------+
|    111 | elvin    | 202 jai street | delhi      |
|    112 | patrick  | harinagar      | tamilnadu  |
|    113 | soman    | puthumana      | kerala     |
|    114 | jaise    | kottarakara    | kerala     |
|    115 | mickey   | juhu           | maharastra |
+--------+----------+----------------+------------+

	iii. Orders Table
+---------+--------+----------+------------+--------+
| orderid | itemid | quantity | orderdate  | custid |
+---------+--------+----------+------------+--------+
|       1 |      1 |        2 | 2014-10-11 |    111 |
|       2 |      3 |        1 | 2012-01-29 |    113 |
|       3 |      5 |        1 | 2013-05-13 |    115 |
|       4 |      4 |        3 | 2014-12-22 |    114 |
+---------+--------+----------+------------+--------+

	iv. Delivery Table
+------------+---------+--------+
| deliveryid | orderid | custid |
+------------+---------+--------+
|       1001 |       1 |    111 |
|       1002 |       2 |    113 |
|       1003 |       3 |    115 |
+------------+---------+--------+

2. List the details of all customers who have placed an order.
3. List the details of all customers whose orders have been delivered
4. Find the orderdate for all customers whose name starts in the letter 'J'
5. Display the name and price of all items bought by the customer 'Mickey'
6. List the details of all customers who have placed an order after January 2013 and not
received delivery of items.
7. Find the itemid of items which has either been ordered or not delivered. (Use SET
UNION)
8. Find the name of all customers who have placed an order and have their orders
delivered.(Use SET INTERSECTION)
9. Find the custname of all customers who have placed an order but not having their
ordersdelivered. (EXCEPT is available in the PostgreSQL database while MINUS is
available in MySQL)
10. Find the name of the customer who has placed the most number of orders.
11. Find the details of all customers who have purchased items exceeding a price of
5000$.
12. Find the name and address of customers who has not ordered a 'Samsung Galaxy S4'
13. Perform Left Outer Join and Right Outer Join on Customers & Orders Table.
14. Find the details of all customers grouped by state.
15. Display the details of all items grouped by category and having a price greater than
the average price of all items.
*/

CREATE TABLE Items (
	itemid INT PRIMARY KEY,
	itemname VARCHAR(50),
	category VARCHAR(20),
	price INT,
	instock INT
);
CREATE TABLE Customers (
	custid INT PRIMARY KEY,
	custname VARCHAR(20),
	address VARCHAR(40),
	state VARCHAR(20)
);
CREATE TABLE Orders (
	orderid INT PRIMARY KEY,
	itemid INT,
	quantity INT NOT NULL,
	orderdate DATE,
	custid INT,
	FOREIGN KEY (itemid) REFERENCES Items(itemid) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (custid) REFERENCES Customers(custid) ON UPDATE CASCADE ON DELETE CASCADE 
);
CREATE TABLE Delivery (
	deliveryid INT PRIMARY KEY,
	orderid INT,
	custid INT,
	FOREIGN KEY (orderid) REFERENCES Orders(orderid) ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY (custid) REFERENCES Customers(custid) ON UPDATE CASCADE ON DELETE CASCADE 
);
INSERT INTO Items
VALUES
	(5,'sony z5 premium','electronics',5005,1),
	(4,'Samsung Galaxy S4','electronics',5005,1),
	(3,'One Plus 7','electronics',6006,2),
	(2,'Iphone X','electronics',7007,6),
	(1,'Xiomi','electronics',1001,6);
INSERT INTO Customers
VALUES
	(111,'elvin','202 jai street','delhi'),
	(113,'soman','puthumana','kerala'),
	(115,'mickey','juhu','maharastra'),
	(112,'patrick','harinagar','tamilnadu'),
	(114,'jaise','kottarakara','kerala');
INSERT INTO Orders
VALUES
	(1,1,2,'2014-10-11',111),
	(2,3,1,'2012-01-29',113),
	(3,5,1,'2013-05-13',115),
	(4,4,3,'2014-12-22',114);
INSERT INTO Delivery
VALUES
	(1001,1,111),
	(1002,2,113),
	(1003,3,115);
SELECT * FROM Items;
SELECT * FROM Customers;
SELECT * FROM Orders;
SELECT * FROM Delivery;

SELECT Customers.custid,custname,address,state FROM Customers, Orders
WHERE Orders.custid = Customers.custid;

SELECT Customers.custid, custname, address, state FROM Customers, Delivery
WHERE Delivery.custid = Customers.custid;

SELECT orderdate FROM Customers, Orders
WHERE Orders.custid = Customers.custid AND custname LIKE 'j%';

SELECT itemname, price FROM Items AS i, Customers AS c, Orders AS o
WHERE i.itemid = o.itemid and c.custid = o.custid AND c.custname LIKE 'mickey';

SELECT c.* FROM Customers AS c, Orders AS o
WHERE o.custid = c.custid AND orderdate >= '2013-01-01' AND 
	c.custid NOT IN (SELECT custid FROM Delivery);

(SELECT i.itemid FROM Items AS i, Orders AS o
WHERE i.itemid = o.itemid)
	UNION
(SELECT i.itemid from Items AS i, Orders AS o
WHERE i.itemid = o.itemid AND o.orderid NOT IN
	(SELECT orderid FROM Delivery));

(SELECT custname FROM Customers AS c, Orders AS o
WHERE o.custid = c.custid)
	INTERSECT
(SELECT custname FROM Customers AS c, Delivery AS d
WHERE d.custid = c.custid);

(SELECT custname FROM Customers AS c, Orders AS o
WHERE o.custid = c.custid)
	EXCEPT
(SELECT custname FROM Customers AS c, Delivery AS d 
WHERE d.custid = c.custid);

INSERT INTO Orders VALUES (5, 2, 1, '2012-05-25', 115);
SELECT * FROM Customers WHERE custid=(
	SELECT custid FROM Orders GROUP BY custid ORDER BY COUNT(*) DESC LIMIT 1
);

SELECT c.* FROM Customers AS c, Items AS i, Orders AS o
WHERE o.itemid = i.itemid AND c.custid = o.custid AND price > 5000;

(SELECT custname, address FROM Customers)
	EXCEPT
(SELECT c.custname, c.address FROM Customers AS c, Orders as o, Items as i
WHERE o.itemid = i.itemid AND c.custid = o.custid AND itemname = 'Samsung Galaxy S4');

SELECT * FROM Customers LEFT OUTER JOIN Orders ON Customers.custid = Orders.custid;
SELECT * FROM Customers RIGHT OUTER JOIN Orders ON Customers.custid = Orders.custid;

SELECT COUNT(*), state FROM Customers 
GROUP BY state;

SELECT * FROM Items
WHERE price IN (
	SELECT price FROM Items
	GROUP BY price
	HAVING price > (
		SELECT AVG(price) FROM Items
		GROUP BY category
	)
);