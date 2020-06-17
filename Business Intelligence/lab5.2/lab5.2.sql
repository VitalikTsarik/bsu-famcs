select empname, year, month, salvalue, 
    sum(salvalue) over(partition by empno order by empno, year, month range unbounded preceding) as "Cumulative salary" 
from salary join emp using(empno); 


select month, sum(salvalue) over(order by month range between 3 preceding and current row) as "Salary expenses for period" 
from salary 
where year=2010;  


select empname, year, month, avg(salvalue) 
    over(partition by empno order by year, month rows 3 preceding) as "Salary for period 3 month" 
from salary join emp using(empno); 


select empname, salvalue, 
    sum(salvalue) over(order by empno range unbounded preceding) as "Cumulative average" 
from salary join emp using(empno) 
where year=2016 and month=1; 
