-- creating a database
--create database mydb;

-- creating a table employees
create table employees
(
	employee_id int primary key, 
	department_id int,
	job_id varchar(255),
	first_name varchar(255),
	last_name varchar(255),
	salary float(25)
);

-- creating a table departments
create table departments
(
	department_id int primary key, 
	department_name varchar(255)
);

-- inserting values into the departments table 
insert into departments values (1, 'Development');
insert into departments values (2, 'QA');
insert into departments values (3, 'HR');

-- inserting values into the employees table 
insert into employees values (1, 1, 'Developer', 'John', 'Doe', 50000);
insert into employees values (2, 1, 'Lead', 'Jack', 'Hill', 60000);
insert into employees values (3, 1, 'Manager', 'Josef', 'Karl', 65000);
insert into employees values (4, 2, 'Analyst', 'Noah', 'Simmons', 40000);
insert into employees values (5, 2, 'Analyst', 'Alice', 'Samson', 40000);
insert into employees values (6, 2, 'Manager', 'Rafael', 'Knox', 50000);
insert into employees values (7, 3, 'Executive', 'Amy', 'Swanson', 35000);
insert into employees values (8, 1, 'Developer', 'Frank', 'Robert', 50000);
insert into employees values (9, 1, 'Lead', 'Mike', 'Nathan', 60000);
insert into employees values (10, 1, 'Manager', 'Lucas', 'Fox', 65000);
insert into employees values (11, 2, 'Analyst', 'Akira', 'Momo', 45000);
insert into employees values (12, 2, 'Analyst', 'Frieren', 'Haruka', 46000);
insert into employees values (13, 3, 'Executive', 'Moly', 'Cooper', 35000);
insert into employees values (14, 3, 'Manager', 'Amanda', 'Raj', 45000);

-- creating managers tables
create table managers
(
	employee_id int,
	department_id int,
	first_name varchar(255),
	last_name varchar(255)
);

-- populating the managers table 
insert into managers values (3, 1, 'Josef', 'Karl');
insert into managers values (6, 2, 'Rafael', 'Knox');
insert into managers values (10, 1, 'Lucas', 'Fox');
insert into managers values (14, 3, 'Amanda', 'Raj');

-- displaying all records of employees table
select * from employees;

-- displaying all records of departments table
select * from departments;

-- displaying all records of managers table
select * from managers;

-- displaying the salary of Alice
select salary from employees where first_name = 'Alice';

-- displaying the employee names whose salary is more than 40000
select first_name, last_name from employees where salary > 40000;

-- displaying the employee names whose salary is greater than Alice's salary
select first_name, last_name from employees where salary > 
	(select salary from employees where first_name = 'Alice');

-- displaying the employees whose job_id is same as Alice
select first_name, last_name, salary from employees where job_id =  
	(select job_id from employees where first_name = 'Alice');

-- displaying the employees whose jod_id is same as Alice 
-- but salary is greater
select first_name, last_name from employees 
	where 
	job_id = (select job_id from employees where first_name = 'Alice')
	and
	salary > (select salary from employees where first_name = 'Alice');

-- lowest salary in the company
select min(salary) from employees;

-- employees who get the lowest salary in the company
select first_name, last_name from employees where
	salary = (select min(salary) from employees);

-- minimum salaries of each department 
select department_id, min(salary) from employees group by department_id;

-- departments whose minimum salary is greater than the minimum salary of HR dept
select department_id, min(salary) from employees group by department_id
	having min(salary) > 
	(
		select min(salary) from employees where department_id =
			(select department_id from departments where department_name='HR')
	);

-- different salaries of department 3
select salary from employees where department_id=3;

-- employees whose salary is more than any employee of department 3
select first_name, last_name, salary from employees where salary >
	ANY (select salary from employees where department_id=3);

-- employees whose salary is more than all employee of department 3
select first_name, last_name, salary from employees where salary >
	ALL (select salary from employees where department_id=3);

-- employees who are not managers
select first_name, last_name, job_id from employees where employee_id not in
	(select employee_id from managers);

-- display the names and salaries of managers
select first_name, last_name, salary from employees where job_id = 'manager';
select first_name, last_name, salary from employees where employee_id in
	(select employee_id from managers);

-- employees who have more salary than at least one other employee
select e1.employee_id 
	from employees e1, employees e2 
	where 
	e1.salary > e2.salary;
select distinct e1.employee_id 
	from employees e1, employees e2 
	where 
	e1.salary > e2.salary;
drop table employees;
drop table managers;
drop table departments;