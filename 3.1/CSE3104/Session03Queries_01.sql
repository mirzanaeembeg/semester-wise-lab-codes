--create database mydb;

create table student
(
	id int primary key, 
	fname varchar(255),
	lname varchar(255),
	cgpa float(10),
	city varchar(255)
);


insert into student values (1, 'Paul', 'Anderson', 3.6 , 'Rome');
insert into student values (2, 'Peter', 'Jackson', 3.3 , 'Venice');
insert into student values (4, 'Tom', 'Russel', 3.7 , 'Madrid');
insert into student values (3, 'Hugh', 'Albon', 3.1 , 'Brisbon');
insert into student values (5, 'Betty', 'Nesord', 3.8 , 'London');
insert into student values (6, 'Karim', 'Khan', 3.1 , 'London');
insert into student values (7, 'Rahim', 'Khan', 3.2 , 'London');
insert into student values (8, 'Rudy', 'Kahn', 3.2 , 'Munich');

select * from student;
select cgpa from student;

select count(*) from student;

select avg(cgpa) from student;
select max(cgpa) from student;
select min(cgpa) from student;
select sum(cgpa) from student;

select avg(cgpa) as AvgCGPA from student;
select max(cgpa) as MaxCGPA from student;
select min(cgpa) as MinCGPA from student;
select sum(cgpa) as CGPA_SUM from student;

-- select first(cgpa) from student;
-- select last(cgpa) from student;
select top 1 cgpa from student order by id asc;
select top 1 cgpa from student order by id desc;

create table order_table
(
	order_id int primary key, 
	customer_id int,
	customer_name varchar(255),
	product_id int,
	cost float(10),
	city varchar(255)
);


insert into order_table values (1, 1, 'Anderson', 2 , 10, 'Rome');
insert into order_table values (2, 1, 'Anderson', 3 , 13, 'Rome');
insert into order_table values (3, 1, 'Anderson', 4 , 15, 'Rome');
insert into order_table values (4, 2, 'Russel', 2 , 10, 'Milan');
insert into order_table values (5, 2, 'Russel', 3 , 13, 'Milan');
insert into order_table values (6, 3, 'Sainz', 2 , 10, 'London');

select * from order_table;

select customer_name, sum(cost) as SumOfCost from order_table group by customer_name;
select customer_name, avg(cost) as AvgCost from order_table group by customer_name;
select customer_name, max(cost) as MaxCost from order_table group by customer_name;

select customer_name, avg(cost) as AvgCost from order_table 
	group by customer_name 
	having avg(cost)>=11;

select customer_name, avg(cost) as AvgCost from order_table 
	where city='Rome' or City ='Milan'
	group by customer_name 
	having avg(cost)>=11;

select customer_name, avg(cost) as AvgCost from order_table 
	where city in ('Rome')
	group by customer_name 
	having avg(cost)>=11;

create table city
(
	city_id int primary key, 
	city_name varchar(255),
	country_name varchar(255)
);

insert into city values (1, 'Rome', 'Italy');
insert into city values (4, 'Milan', 'Italy');
insert into city values (2, 'Venice', 'Italy');
insert into city values (3, 'Liverpool', 'UK');
insert into city values (5, 'Manchester', 'UK');
insert into city values (6, 'London', 'UK');
insert into city values (7, 'Brisbon', 'UK');

select customer_name, avg(cost) as AvgCost from order_table 
	where city in (select city_name from city where country_name='Italy')
	group by customer_name 
	having avg(cost)>=11;
drop table student;
drop table order_table;
drop table city;