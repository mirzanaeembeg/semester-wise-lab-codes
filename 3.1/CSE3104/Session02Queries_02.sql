--drop database mydb;

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

select * from student order by cgpa asc;
select * from student order by cgpa desc;

select top 2 * from student;

select fname, lname, cgpa from student where lname like '%son';
select fname, lname, cgpa from student where lname like '%so%';
select fname, lname, cgpa from student where fname like '___im';
select fname, lname, cgpa from student where lname like 'K__n';

select * from student where city in ('Rome', 'Venice');

select * from student where cgpa between 3.1 and 3.5;

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

select * from student where city in 
(select city_name from city where country_name ='Italy');

drop table student;