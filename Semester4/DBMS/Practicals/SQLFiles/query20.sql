SELECT CONCAT(UPPER(SUBSTR(Ename,1,1)),
LOWER(SUBSTR(Ename,2,LENGTH(Ename))))
AS Name, LENGTH(Ename) AS Length
FROM EMPLOYEE
WHERE Ename LIKE 'J%' OR 
Ename LIKE 'A%' OR Ename LIKE 'M%';

SELECT UPPER(SUBSTR(Ename,1,1))
AS Name, LENGTH(Ename) AS Length
FROM EMPLOYEE
WHERE Ename LIKE 'J%' OR 
Ename LIKE 'A%' OR Ename LIKE 'M%';