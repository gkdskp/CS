/* SQL script
To execute: Run `source /path/to/dbsetup.sql` in mysql
*/

CREATE DATABASE Users;

USE Users;

CREATE TABLE Profile (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    uname VARCHAR(30),
    lname VARCHAR(30),
    email VARCHAR(50),
    passwd VARCHAR(50),
    age INT,
    uaddress VARCHAR(500),
    city VARCHAR(30),
    zip INT,
    joindate DATETIME
);