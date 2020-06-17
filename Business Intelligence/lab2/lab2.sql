select sum(case when jobno=1000 then 1 else 0 end) as MANAGER, 
       sum(case when jobno=1001 then 1 else 0 end) as FINANCIAL_DIRECTOR, 
       sum(case when jobno=1002 then 1 else 0 end) as EXECUTIVE_DIRECTOR, 
       sum(case when jobno=1003 then 1 else 0 end) as SALESMAN, 
       sum(case when jobno=1004 then 1 else 0 end) as CLERK, 
       sum(case when jobno=1005 then 1 else 0 end) as DRIVER, 
       sum(case when jobno=1006 then 1 else 0 end) as PRESIDENT 
from career; 

select max(case when deptname='ACCOUNTING' then empname else null end) as ACCOUNTING, 
       max(case when deptname='RESEARCH' then empname else null end) as RESEARCH, 
       max(case when deptname='SALES' then empname else null end) as SALES, 
       max(case when deptname='OPERATIONS' then empname else null end) as OPERATIONS 
from ( 
    select deptname, empname, row_number() over(partition by deptname order by empname) row_number
    from emp join (career join dept using (deptno)) using (empno) 
    ) 
    group by row_number; 
    
select job.jobname, case job.jobno 
    when 1000 then emp_count.manager 
    when 1001 then emp_count.FINANCIA_DIRECTOR 
    when 1002 then emp_count.EXECUTIVE_DIRECTOR 
    when 1003 then emp_count.SALESMAN 
    when 1004 then emp_count.CLERK 
    when 1005 then emp_count.DRIVER 
    when 1006 then emp_count.PRESIDENT 
end as EMPCOUNT 
from (select sum(case when jobno=1000 then 1 else 0 end) as MANAGER, 
       sum(case when jobno=1001 then 1 else 0 end) as FINANCIA_DIRECTOR, 
       sum(case when jobno=1002 then 1 else 0 end) as EXECUTIVE_DIRECTOR, 
       sum(case when jobno=1003 then 1 else 0 end) as SALESMAN, 
       sum(case when jobno=1004 then 1 else 0 end) as CLERK, 
       sum(case when jobno=1005 then 1 else 0 end) as DRIVER, 
       sum(case when jobno=1006 then 1 else 0 end) as PRESIDENT 
from career) emp_count, job; 

select case row_number 
    when 1 then cast(jobno as char(4)) 
    when 2 then jobname 
    when 3 then cast(minsalary as char(5)) 
end jobs 
from (select j.jobno, j.jobname, j.minsalary, 
    row_number() over(partition by jobno order by j.jobno) row_number 
    from job j, (select *  
    from emp) four_rows 
where manager_id = 7790 
); 

select empno, empname, case lag(manager_id) over(order by manager_id) 
    when manager_id then null  
    else manager_id 
    end as manager_id 
from emp; 