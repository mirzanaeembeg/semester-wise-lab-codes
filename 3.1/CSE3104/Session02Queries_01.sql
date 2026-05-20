--drop database mydb;

create database mydb;

--drop table customers;

create table customers
(
	customer_id int,
	customer_name varchar(255),
	customer_age int
);

select * from customers;

insert into customers values (1, 'Bob', 56);
insert into customers (customer_id, customer_name) values (2, 'Rob');
insert into customers values (3, 'Bob', 53);



drop table customers;

create table customers
(
	customer_id int,
	customer_name varchar(255) NOT NULL,
	customer_age int NOT NULL,
	customer_city varchar(255) NULL
);

select * from customers;

insert into customers values (1, 'Bob', 56, null);
--insert into customers (customer_id, customer_name) values (2, 'Rob');
insert into customers (customer_id, customer_name, customer_age) values (2, 'Rob', 51);
insert into customers values (3, 'Bob', 53, 'Paris');






drop table customers;

create table customers
(
	customer_id int NOT NULL UNIQUE,
	customer_name varchar(255) NOT NULL UNIQUE,
	customer_age int NOT NULL,
	customer_city varchar(255) NULL
);

select * from customers;

insert into customers values (1, 'Bob', 56, null);
insert into customers (customer_id, customer_name, customer_age) values (2, 'Rob', 51);
--insert into customers values (3, 'Bob', 51, 'Paris');
insert into customers values (3, 'Don', 51, 'Paris');






drop table customers;

create table customers
(
	customer_id int PRIMARY KEY,
	customer_name varchar(255) NOT NULL,
	customer_age int NOT NULL,
	customer_city varchar(255) NULL
);


select * from customers;

insert into customers values (1, 'Bob', 56, null);
insert into customers (customer_id, customer_name, customer_age) values (2, 'Rob', 51);
insert into customers values (3, 'Don', 51, 'Paris');
--insert into customers values (3, 'Tom', 50, 'Tokyo');






drop table customers;

create table customers
(
	customer_id int,
	customer_name varchar(255) NOT NULL,
	customer_age int NOT NULL,
	customer_city varchar(255) NULL,
	UNIQUE (customer_name),
	PRIMARY KEY (customer_id)
);


select * from customers;

insert into customers values (1, 'Bob', 56, null);
insert into customers (customer_id, customer_name, customer_age) values (2, 'Rob', 51);
insert into customers values (3, 'Don', 51, 'Paris');
--insert into customers values (3, 'Tom', 50, 'Rome');






drop table customers;

create table customers
(
	customer_id int NOT NULL,
	customer_name varchar(255) NOT NULL,
	customer_age int NULL,
	customer_city varchar(255) NOT NULL,
	UNIQUE (customer_name),
	CONSTRAINT PK_ID PRIMARY KEY (customer_id, customer_city)
);


select * from customers;

insert into customers values (1, 'Bob', 56, 'Manitoba');
insert into customers (customer_id, customer_name, customer_city) values (2, 'Rob', 'Manitoba');
insert into customers values (3, 'Don', 51, 'Paris');
insert into customers values (1, 'Kim', 46, 'Tokyo');
insert into customers values (1, 'Jim', 56, 'Manitoba');






drop table customers;

create table customers
(
	customer_id int NOT NULL,
	customer_name varchar(255) NOT NULL,
	customer_age int NULL,
	customer_city varchar(255) NOT NULL
);

ALTER TABLE customers ADD UNIQUE (customer_name);
ALTER TABLE customers ADD PRIMARY KEY (customer_id);


select * from customers;

insert into customers values (1, 'Bob', 56, 'Manitoba');
insert into customers (customer_id, customer_name, customer_city) values (2, 'Rob', 'Manitoba');
insert into customers values (3, 'Don', 51, 'Paris');
--insert into customers values (3, 'Tom', 51, 'Paris');






drop table customers;

create table customers
(
	customer_id int NOT NULL,
	customer_name varchar(255) NOT NULL,
	customer_age int NULL,
	customer_city varchar(255) NOT NULL
);

ALTER TABLE customers ADD UNIQUE (customer_name);
ALTER TABLE customers ADD CONSTRAINT PK_ID PRIMARY KEY(customer_id, customer_city);


select * from customers;

insert into customers values (1, 'Bob', 56, 'Manitoba');
insert into customers (customer_id, customer_name, customer_city) values (2, 'Rob', 'Manitoba');
insert into customers values (3, 'Don', 51, 'Paris');
insert into customers values (1, 'Kim', 46, 'Tokyo');






drop table customers;

create table customers
(
	customer_id int PRIMARY KEY,
	customer_name varchar(255) NOT NULL,
	customer_age int NULL,
	customer_city varchar(255) NOT NULL
);

create table products
(
	product_id int PRIMARY KEY,
	product_name varchar(255)
);

create table orders
(
	order_id int PRIMARY KEY, 
	customer_id int FOREIGN KEY references customers(customer_id),
	product_id int FOREIGN KEY references products(product_id),
	product_quantity int
);

select * from products;
select * from customers;
select * from orders;

insert into products values (1, 'Lamp');
insert into products values (2, 'Pen');


insert into customers values (1, 'Bob', 56, 'Manitoba');
insert into customers values (2, 'Rob', 49, 'Osaka');
insert into customers values (3, 'Don', 51, 'Paris');
insert into customers values (4, 'Kim', 46, 'Tokyo');

insert into orders values (1, 2, 1, 10);
--insert into orders values (1, 5, 1, 10);



--drop table customers;
--drop table products;
--drop table orders;


create table persons
(	
	PID int NOT NULL CHECK(PID>0),
	First_Name varchar(255),
	Last_Name varchar(255) NOT NULL,
	Age int NOT NULL,
	Salary int NOT NULL,
	Credit_Score int NOT NULL
);

ALTER TABLE persons ADD CHECK (Age>18);
ALTER TABLE persons ADD Constraint Check_Persons CHECK (Salary>50000 AND Credit_Score>700);

select * from persons;

insert into persons values (1, 'Ken', 'Kaneki', 27, 53000, 740);
--insert into persons values (2, 'Hideyoshi', 'Nagachika', 27, 48000, 740);

ALTER TABLE persons DROP Constraint Check_Persons;

insert into persons values (2, 'Hideyoshi', 'Nagachika', 27, 48000, 740);


drop table persons;


CREATE TABLE students
(
	ID int NOT NULL,
	Semester int DEFAULT 1,
	CGPA float(53) NOT NULL 
);

ALTER TABLE students ADD CONSTRAINT def_const DEFAULT 0.0 FOR CGPA;

select * from students;

insert into students (id) values (1);
insert into students (id, semester) values (1, 2);
insert into students (id, semester, cgpa) values (1, 2, 3.5);

ALTER TABLE students DROP CONSTRAINT def_const;
--insert into students (id, semester) values (2, 4);


drop table students;


create table faculty
(
	ID int IDENTITY(1,1) PRIMARY KEY,
	Name varchar(255) NOT NULL,
	Designation varchar(255) NOT NULL
);

select * from faculty;

insert into faculty values ('Md. Siam Ansary', 'Lecturer');
insert into faculty values ('Prof. Dr. A', 'Professor');

DROP TABLE faculty;