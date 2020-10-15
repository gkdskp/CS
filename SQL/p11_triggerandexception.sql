CREATE TABLE customer_details (
	cust_id INT UNIQUE,
	cust_name VARCHAR(25),
	address VARCHAR(30)
);

CREATE TABLE emp_details (
	empid INT UNIQUE,
	empname VARCHAR(25),
	SALARY INT
);

CREATE TABLE cust_count (
	count_row INT
);

CREATE OR REPLACE FUNCTION customer_details_insert() RETURNS TRIGGER AS
$customer_details_insert$
	BEGIN
		RAISE NOTICE 'Row inserted';
		RETURN NEW;
	END;
$customer_details_insert$
LANGUAGE plpgsql;

CREATE TRIGGER customer_details_insert
AFTER INSERT ON customer_details
	FOR EACH STATEMENT EXECUTE PROCEDURE customer_details_insert();


CREATE OR REPLACE FUNCTION employee_salary_check() RETURNS trigger AS $employee_salary$
	BEGIN
		IF NEW.salary > 20000 
		THEN
			RAISE NOTICE 'Inserted employee % has salary greater 20000', NEW.empname;
		END IF;
		RETURN NEW;
	END;
$employee_salary$ LANGUAGE plpgsql;

CREATE TRIGGER employee_salary AFTER INSERT OR UPDATE ON emp_details
	FOR EACH ROW EXECUTE PROCEDURE employee_salary_check();
	
INSERT INTO cust_count VALUES(0);

CREATE OR REPLACE FUNCTION cust_count() RETURNS trigger AS $cust_count$
DECLARE
	count INT;
	BEGIN
		SELECT * FROM cust_count INTO count;
		IF (TG_OP = 'DELETE' AND count != 0) THEN
			UPDATE cust_count SET count_row=count_row-1;
		ELSIF (TG_OP = 'INSERT') THEN
			UPDATE cust_count SET count_row=count_row+1;
		END IF;
		RETURN NEW;
	END;
$cust_count$ LANGUAGE plpgsql;

CREATE TRIGGER cust_count_change
AFTER INSERT OR DELETE ON customer_details
	FOR EACH ROW EXECUTE PROCEDURE cust_count();

CREATE TABLE deleted (
	empid INT UNIQUE,
	empname VARCHAR(25),
	SALARY INT
);

CREATE TABLE updated (
	empid INT UNIQUE,
	empname VARCHAR(25),
	SALARY INT
);

CREATE OR REPLACE FUNCTION delete_update() RETURNS trigger AS $delete_update$
BEGIN
	IF(TG_OP = 'DELETE') THEN
		INSERT INTO deleted VALUES (OLD.empid, OLD.empname, OLD.salary);
	ELSIF(TG_OP = 'UPDATE') THEN
		INSERT INTO updated VALUES (OLD.empid, OLD.empname, OLD.salary);
	END IF;
	RETURN NEW;
END;
$delete_update$ LANGUAGE plpgsql;

CREATE TRIGGER delete_update
AFTER UPDATE OR DELETE ON emp_details
	FOR EACH ROW EXECUTE PROCEDURE delete_update();

CREATE OR REPLACE FUNCTION div(a INT, b INT) RETURNS INT AS 
$$
DECLARE
	result INT;
	BEGIN
		IF b = 0 THEN
			RAISE EXCEPTION 'DIVIDE BY ZERO';
		ELSE
			result = a/b;
			RETURN result;
		END IF;
	END;
$$
LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_salary(id INT) RETURNS INT as
$$
DECLARE
	result INT;
BEGIN
	SELECT salary INTO result FROM emp_details WHERE empid=id;
	IF RESULT IS NULL THEN
		RAISE EXCEPTION 'No data foudn';
	ELSE
		RETURN result;
	END IF;
END;
$$
LANGUAGE plpgsql;

CREATE TABLE ebill (
	cname VARCHAR(20),
	preread INT,
	curread INT
);

CREATE OR REPLACE FUNCTION check_reading() RETURNS TRIGGER AS
$checkread$
BEGIN
	IF NEW.preread=NEW.curread THEN
		RAISE EXCEPTION 'Data error % %' ,NEW.preread,NEW.curread;
	ELSE
		RAISE NOTICE 'Data entered';
	END IF;
	RETURN NEW;
END;
$checkread$
LANGUAGE plpgsql;

CREATE TRIGGER check_reading
BEFORE INSERT ON ebill
FOR EACH ROW EXECUTE PROCEDURE check_reading();