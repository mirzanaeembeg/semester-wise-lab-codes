DROP TABLE History;
DROP TABLE Accounts;

CREATE TABLE Accounts (
    AccountNumber INT PRIMARY KEY,
    AccountHolder VARCHAR(100) NOT NULL,
    Balance DECIMAL(10, 2) NOT NULL
);

INSERT INTO Accounts (AccountNumber, AccountHolder, Balance)
	VALUES
		(101, 'John Doe', 5000.00),
		(102, 'Jane Smith', 7500.50),
		(103, 'Bob Johnson', 12000.25),
		(104, 'Alice Brown', 3000.75);

SELECT * FROM Accounts;

CREATE TABLE History
(
	AccountNumber int foreign key references accounts(AccountNumber), 
	Amount int, 
	TransactionDate DateTime
);

-- without transaction

UPDATE Accounts SET Balance = Balance - 100 WHERE AccountNumber = 101;
UPDATE Accounts SET Balance = Balance + 100 WHERE AccountNumber = 102;
SELECT * FROM Accounts;

INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (101, -100, GETDATE());
INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (102, 100, GETDATE());
SELECT * FROM History;

DELETE FROM History;
DELETE FROM Accounts;

SELECT * FROM Accounts;
SELECT * FROM History;

-- with transaction
BEGIN TRANSACTION;

INSERT INTO Accounts (AccountNumber, AccountHolder, Balance)
	VALUES
		(101, 'John Doe', 5000.00),
		(102, 'Jane Smith', 7500.50),
		(103, 'Bob Johnson', 12000.25),
		(104, 'Alice Brown', 3000.75);

Commit;

select * from Accounts;

BEGIN TRANSACTION;

UPDATE Accounts SET Balance = Balance - 100 WHERE AccountNumber = 101;
UPDATE Accounts SET Balance = Balance + 100 WHERE AccountNumber = 102;

INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (101, -100, GETDATE());
INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (102, 100, GETDATE());

SELECT * FROM Accounts;
SELECT * FROM History;

ROLLBACK;
SELECT * FROM Accounts;
SELECT * FROM History;

BEGIN TRANSACTION;

UPDATE Accounts SET Balance = Balance - 100 WHERE AccountNumber = 101;
UPDATE Accounts SET Balance = Balance + 100 WHERE AccountNumber = 102;

INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (101, -100, GETDATE());
INSERT INTO History(AccountNumber, Amount, TransactionDate) VALUES (102, 100, GETDATE());

SELECT * FROM Accounts;
SELECT * FROM History;

commit;
SELECT * FROM Accounts;
SELECT * FROM History;

/*
A transaction is a sequence of operations performed on a database 
as a single logical unit of work. The effects of all the SQL statements 
in a transaction can be either all committed (applied to the database) 
or all rolled back (undone from the database).
*/
