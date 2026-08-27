CREATE TABLE Shifts(
    shift_id INT PRIMARY KEY,
    shift_name VARCHAR(50),
    shift_start TIME,
    shift_end TIME
);

INSERT INTO Shifts Values 
(1,'Morning', '07:00','15:00'),
(2,'Day','10:00','18:00'),
(3, 'Night', ' 20:00','8:00');

--- Employee table 

CREATE TABLE Employees(
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(100),
    dept   VARCHAR(50),
    shift_id INT NOT NULL REFERENCES Shifts(shift_id)


);

----Session Table 
CREATE TABLE Sessions (
    session_id INT IDENTITY PRIMARY KEY ,
    emp_id INT NOT NULL REFERENCES Employee (emp_id),

    login_time DATETIME NOT NULL DEFAULT GETDATE(),
    logout_time DATETIME NULL,
    session_token VARCHAR(64) NOT NULL

);



CREATE UNIQUE INDEX UX_Sessions_OneActive 
ON Sessions (emp_id)
WHERE logout_time IS NULL;
----  LOGIN PROCEDURE 

CREATE PROCEDURE sp_Login
 @login_emp_id INT ,
 @ token   VARCHAR (64)

 AS BEGIN 
   SET NOCOUNT ON;
-----Step 0 : Employee must exist 
  IF NOT EXISTS (SELECT 1 FROM Employees WHERE emp_id = @login_emp_id)
  BEGIN 
    SELECT 'DENIED: UNKNOWN EMPLOYEE ID' AS result ;
    RETURN ;

  END


 ---- Step 1 : auto-expire stale session (crash /never logged out)

 UPDATE Sessions
 SET logout_time =GETDATE()
 WHERE emp_id= @login_emp_id
  AND logout_time IS NULL
  AND login_time < DATEADD(HOUR,-12,GATEDATE());
--------- step 2 Try to claim session slot


BEGIN TRY 

INSERT INTO Sessions (emp_id,session_token)
VALUES (@login_emp_id,@token);
END TRY 
BEGIN TRY 
BEGIN CATCH

SELECT 'DENIED : already logged in else where .Logout first ' AS result;
RETURN;
END CATCH

------ STEP 3 LOGIN SUCCEEDED\


SELECT 
e.emp_id,
e.emp_name,
e.dept,
s.shift_name,
s.shift_start,
s.shift_end,
CASE WHEN (s.shift_start <s.shift_end
 AND CAST(GETDATE() AS TIME ) >= s.shift_start
 AND CAST(GENERATE() AS TIME < s.shift_end ))
 OR (s.shift_start >s.shift_end
   AND (CAST(GETDATE() AS TIME )>=s.shift_start\
   OR CAST (GETDATE()AS TIME ) <s.shift_end))

THEN 'ON SHIFT'
ELSE 'OFF SHIFT '

END AS login_status,
'LOGIN OK ' AS result 

FROM Employees e
JOIN Shifts s ON s.shift_id = e.shift_id
WHERE e.emp_id =@login_emp_id ;

END;





