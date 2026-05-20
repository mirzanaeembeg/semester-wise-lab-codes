/*
	A trigger is a set of SQL statements that reside in system memory 
	with unique names. It is a specialized category of stored procedure 
	that is called automatically when a database server event occurs. 
	Each trigger is always associated with a table.
*/

drop table Employee;

CREATE TABLE Employee  
(  
  Id INT PRIMARY KEY,  
  Name VARCHAR(45),  
  Salary INT,  
  Gender VARCHAR(12),  
  DepartmentId INT  
);

INSERT INTO Employee VALUES (1,'Steffan', 82000, 'Male', 3),  
							(2,'Amelie', 52000, 'Female', 2),  
							(3,'Antonio', 25000, 'male', 1),  
							(4,'Marco', 47000, 'Male', 2),  
							(5,'Eliana', 46000, 'Female', 3);

SELECT * FROM Employee; 

drop table Employee_Audit_Test;

CREATE TABLE Employee_Audit_Test  
(    
	Id int IDENTITY(1,1),   
	Audit_Action text   
);

CREATE TRIGGER trInsertEmployee   
ON Employee  
FOR INSERT  
AS  
BEGIN  
  Declare @Id int  
  SELECT @Id = Id from inserted  
  INSERT INTO Employee_Audit_Test  
  VALUES ('New employee with Id = ' + CAST(@Id AS VARCHAR(10)) + ' is added at ' + CAST(Getdate() AS VARCHAR(22)))  
END  

INSERT INTO Employee VALUES (6,'Peter', 62000, 'Male', 3);

SELECT * FROM Employee_Audit_Test;

CREATE TRIGGER trDeleteEmployee   
ON Employee  
FOR DELETE  
AS  
BEGIN  
  Declare @Id int  
  SELECT @Id = Id from deleted  
  INSERT INTO Employee_Audit_Test  
  VALUES ('An existing employee with Id = ' + CAST(@Id AS VARCHAR(10)) + ' is deleted at ' + CAST(Getdate() AS VARCHAR(22)))  
END  

DELETE FROM Employee WHERE Id = 6; 

SELECT * FROM Employee_Audit_Test;