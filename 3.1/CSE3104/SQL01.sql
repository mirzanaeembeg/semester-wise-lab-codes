drop database mydb;
create database mydb;
drop table students;


CREATE TABLE Students (
    ID int NOT NULL  identity(1,1) PRIMARY KEY,
	Email varchar(50) unique check (Email like '%@aust.edu'),
    LastName varchar(255) NOT NULL,
    FirstName varchar(255) Default 'Mr.',
    Age int  CHECK (Age>=20),
);

insert into students values ('1@aust.edu','Abcd','XYZ',22);
insert into students values ('2@nsu.edu','Abce','XYY',21); /* invalid */
insert into students (EMAIL,FIRSTNAME,AGE) values ('4@aust.edu','ERT',24); /* invalid */
insert into students values ('5@aust.edu','Abcd','XYZ',24);
insert into students values ('7@aust.edu','Abcd','jkl',19); /* invalid */
insert into students(EMAIL,LASTNAME,AGE) values ('6@aust.edu','Abcd',24);

select * from students; 

drop table customerInfo;
create table customerInfo
(           
	CustomerID	int,
	CustomerName varchar(50),
	ContactName	varchar(50),
	CustomerAddress	varchar(50),
	City varchar(50),
	PostalCode	varchar(50),
	Country varchar(50)
);

insert into customerInfo values (1, 'Alfreds Futterkiste',	'Maria Anders','Obere Str. 57',	'Berlin','12209','Germany');
insert into customerInfo values (2,	'Ana Trujillo Emparedados y helados','Ana Trujillo'	,'Avda. de la Constitución 2222','México D.F.','05021', 'Mexico');
insert into customerInfo values (3,	'Antonio Moreno Taquería',	'Antonio Moreno','Mataderos 2312','México D.F.', '05023',	'Mexico');
insert into customerInfo values (4, 'Around the Horn','Thomas Hardy','120 Hanover Sq.','London','WA1 1DP','UK');
insert into customerInfo values (5,	'Berglunds snabbköp', 'Christina Berglund',	'Berguvsvägen 8','Luleå','S-958 22','Sweden');

insert into customerInfo (CustomerID, CustomerName, CustomerAddress	,City,PostalCode,Country) 
	values (6,'Maria Anders','Obere Str. 57','Berlin','12209','Germany');
insert into customerInfo (CustomerID, CustomerName,ContactName,City,PostalCode,Country) 
	values (7,	'Maria Anders','Abc',	'Berlin','12209', 'Germany');
insert into customerInfo (CustomerID, CustomerName,ContactName,customerAddress,City,PostalCode) 
	values (8,	'Maria Anders'	,'Abc',	'Obere Str. 57','Berlin','12209');

select *from customerInfo;

/*
	In SQL, a view is a virtual table based on 
	the result-set of an SQL statement.
*/
CREATE VIEW [Germany Customers] AS 
	SELECT * FROM customerInfo 
	WHERE Country = 'Germany';

select * from [Germany Customers];

/*
	A stored procedure is a prepared SQL code 
	that one can save, so the code can be 
	reused over and over again.
*/

CREATE PROCEDURE dbo.customerDetail
   @CustomerID INT

AS
BEGIN
    SELECT * FROM customerInfo
    WHERE CustomerID = @CustomerID;
END;

Exec dbo.customerDetail @CustomerID=2;