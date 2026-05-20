--DROP DATABASE begDB;
CREATE DATABASE begDB;
CREATE TABLE customers (customer_id int, name varchar(255), age int);
SELECT * FROM customers;
INSERT INTO customers (customer_id, name, age) values (1, 'Bob',55);
INSERT INTO customers (customer_id, name) values (2, 'Rob');
INSERT INTO customers values (3, 'Bob', 54);
SELECT name FROM customers;
SELECT DISTINCT name FROM customers;
SELECT name FROM customers WHERE age = 55;
UPDATE customers SET age = 56 WHERE name = 'Bob';
UPDATE customers SET age = 51 WHERE name = 'Rob';
DELETE FROM customers WHERE name = 'Bob';
DELETE from customers; /* all fiel delete from table */
DROP TABLE customers;  /*delete whole table*/