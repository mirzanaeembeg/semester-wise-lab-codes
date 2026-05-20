-- database creation 
--create database my_db;

-- creation of a table named persons; primary key is P_Id, short for person id
create table persons(
	P_Id int PRIMARY KEY,
	LastName varchar(255),
	FirstName varchar(255),
	Address varchar(255),
	City varchar(255)
);


-- creation of a table named orders; primary key is O_Id, short for order id
-- different persons will place orders, hence P_Id is a column of this table 
create table orders(
	O_Id int PRIMARY KEY,
	OrderNo int,
	P_Id int
);


-- inserting some records into the persons table 
insert into persons values (1, 'Hansen', 'Ola', 'Timoteivn 10', 'Sandnes');
insert into persons values (2, 'Svendson', 'Tove', 'Borgvn 23', 'Sandnes');
insert into persons values (3, 'Pattersen', 'Kari', 'Storgt 20', 'Stavanger');

-- inserting some records into the orders table 
insert into orders values (1, 77895, 3);
insert into orders values (2, 44678, 3);
insert into orders values (3, 22456, 1);
insert into orders values (4, 24562, 1);
insert into orders values (5, 34764, 15);

-- displaying all the values of the persons table
select * from persons;

-- displaying all records of orders table 
select * from orders;

/* The JOIN keyword is used in SQL to query data from two or more 
   tables, based on a relationship between certain columns in these
   tables. The purpose is to bind data together across table without
   repeating all of the data in every table. */

/* The inner join keyword returns rows when there is 
	at least one match in both tables. For P_Id values 
	1 and 3, there are records in both persons and orders. */
select * from persons inner join orders on persons.P_Id=orders.P_Id;
select * from persons inner join orders on persons.P_Id=orders.P_Id
	order by persons.P_Id;

/* The LEFT JOIN returns all records of left table, even if 
	there are no matches in the right table. */
select * from persons left join orders on persons.P_Id=orders.P_Id;
select * from persons left join orders on persons.P_Id=orders.P_Id
	order by persons.P_Id;

/* The RIGHT JOIN returns all records of right table, even if 
	there are no matches in the left table. */
select * from persons right join orders on persons.P_Id=orders.P_Id;
select * from persons right join orders on persons.P_Id=orders.P_Id
	order by persons.P_Id;
select * from persons right join orders on persons.P_Id=orders.P_Id
	order by orders.P_Id;

/* The FULL JOIN returns rows when there is a match in one of the tables */
select * from persons full join orders on persons.P_Id=orders.P_Id;
select * from persons full join orders on persons.P_Id=orders.P_Id
	order by persons.P_Id;
select * from persons full join orders on persons.P_Id=orders.P_Id
	order by orders.P_Id;

/* A cross join is a type of join that returns the Cartesian product 
   of rows from the tables in the join. In other words, it combines 
   each row from the first table with each row from the second table.*/
SELECT * FROM persons CROSS JOIN orders;

-- The UNION operator is used to combine the result-set of two or more SELECT statements.
SELECT P_ID FROM persons UNION SELECT P_Id FROM orders;
SELECT P_ID FROM persons UNION ALL SELECT P_Id FROM orders;

/* The INTERSECT clause in SQL is used to combine two SELECT statements 
   but the dataset returned by the INTERSECT statement will be the intersection 
   of the data sets of the two SELECT statements */
SELECT P_ID FROM persons intersect SELECT P_Id FROM orders;
SELECT P_Id, LastName FROM persons WHERE P_Id BETWEEN 1 AND 2
	INTERSECT
	SELECT P_Id, LastName FROM persons WHERE LastName like '%sen';

/* The EXCEPT operator in SQL is used to retrieve all the unique records 
   from the left operand (query), except the records that are present in 
   the result set of the right operand (query).*/
SELECT P_ID FROM persons except SELECT P_Id FROM orders;
SELECT P_Id, LastName FROM persons WHERE P_Id BETWEEN 1 AND 2
	EXCEPT
	SELECT P_Id, LastName FROM persons WHERE LastName like '%sen';

drop table orders;
drop table persons;
--drop database mydb;