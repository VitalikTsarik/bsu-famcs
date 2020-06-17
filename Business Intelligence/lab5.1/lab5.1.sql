select avg(salvalue) as "Average salary", year, rank() over(order by year) rank 
from salary 
group by year; 


select sum(salvalue) as "Sum salary", year, month, dense_rank() over(order by year, month) rank 
from salary 
group by year, month; 



select salvalue, empname, year, month, 
    rank() over(partition by empname order by year, month) rank 
from salary join emp using(empno); 


select avg(salvalue), year, month, rank() 
    over(partition by grouping_id(year,month) order by year, month) rank 
from salary 
group by cube(year,month); 


select jobname, empname, salvalue, 
    cume_dist() over(partition by jobname order by salvalue) 
from salary join emp using(empno) join career using(empno) join job using(jobno); 


select jobname, empname, salvalue, 
    percent_rank() over(partition by jobname order by salvalue) 
from salary join emp using(empno) join career using(empno) join job using(jobno); 


select empno, empname, ntile(3) over(order by empno)  
from emp 
order by empno; 


select salvalue, row_number() over(order by empno)  
from salary; 
