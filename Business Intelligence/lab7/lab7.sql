select emp1.empname || ' works for ' || emp2.empname as Emp_Manager 
from emp emp1, emp emp2 where emp1.manager_id = emp2.empno;  
 

select empname || ' reports to ' || prior empname 
from emp 
START WITH manager_id is null 
connect by prior empno = manager_id; 


select substr(SYS_CONNECT_BY_PATH(empname, '->'), 3) 
from emp 
where empname = 'JOHN KLINTON' 
START WITH empname = 'CLARK' 
connect by empno = prior manager_id; 


select substr(SYS_CONNECT_BY_PATH(empname, '->'), 3) 
from emp 
START WITH manager_id is null 
connect by prior empno = manager_id; 


select lpad(empname, level - 1 + length(empname), '_') 
from emp 
START WITH manager_id is null 
connect by prior empno = manager_id; 

select empname 
from emp 
START WITH empname = 'ALLEN'  
connect by prior empno = manager_id; 
