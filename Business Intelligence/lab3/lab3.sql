select case grouping(deptname) 
        when 0 then deptname 
        else 'Total' 
    end deptname, 
    count(*) emp_count 
from emp join career using(empno) join dept using(deptno) 
group by rollup(deptname); 




select deptname, jobname, 
    case grouping(deptname) || grouping(jobname) 
        when '00' then 'Total by dept and job' 
        when '01' then 'Total by dept' 
        when '10' then 'Total by job' 
        when '11' then 'Grand total' 
    end category, 
    count(*) "Employers" 
from emp join career using(empno) join job using(jobno) join dept using(deptno) 
group by cube(deptname, jobname) 
order by grouping(deptname), grouping(jobname); 



select deptname, jobname, 
    case grouping(deptname) || grouping(jobname) 
        when '00' then 'Total by dept and job' 
        when '01' then 'Total by dept' 
        when '10' then 'Total by job' 
        when '11' then 'Grand total' 
    end category, 
    avg(salvalue) "Employers" 
from emp join career using(empno) join job using(jobno) join dept using(deptno) join salary using(empno)
group by cube(deptname, jobname) 
order by grouping(deptname), grouping(jobname); 




select deptname, jobname, 
    count(*) "Employers", 
    grouping(deptname) dept_subtotal, 
    grouping(jobname) job_subtotal 
from emp join career using(empno) join job using(jobno) join dept using(deptno) 
group by cube(deptname, jobname) 
order by grouping(deptname), grouping(jobname); 



select empname, deptname, 
    count(*) over(partition by deptname) as deptname_emp_cnt, 
    jobname, 
    count(*) over(partition by jobname) as jobname_emp_cnt, 
    count(*) over() as total 
from emp join career using(empno) join job using(jobno) join dept using(deptno); 



select startdate, salvalue, empno, 
    sum(salvalue) over(order by startdate range between 90 preceding and current row) as "Spending pattern" 
from emp join career using(empno) join salary using(empno); 



select jobname, 
    count(*) as "num", 
    concat(to_char(ratio_to_report(sum(salvalue)) over() * 100, '90.0'), '%') "% of all salaries" 
from emp join career using(empno) join job using(jobno) join salary using(empno) 
group by jobname; 