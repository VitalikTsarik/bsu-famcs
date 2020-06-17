select DEPTADDR from DEPT where DEPTNAME='SALES';

select * from DEPT where DEPTADDR in ('CHICAGO', 'NEW YORK');

select min(SALVALUE) from SALARY where year=2009; 

select count(*) from EMP; 

select JOBNO, case 
    when JOBNAME in ('CLERK', 'DRIVER') then 'WORKER' 
    else JOBNAME 
    end, MINSALARY from JOB; 

select YEAR, round(max(SALVALUE), 2) 
    from SALARY 
    group by YEAR; 

select YEAR, round(avg(SALVALUE), 2)  
    from SALARY 
    group by YEAR 
    having count(*) >= 3; 

select empno, empname, birthdate, manager_id, jobno, deptno, startdate, enddate, month, year, salvalue from EMP 
    cross join CAREER 
    cross join SALARY; 

select EMPNAME, MONTH, YEAR, SALVALUE from EMP 
    join SALARY ON EMP.EMPNO = SALARY.EMPNO 
    order by EMPNAME; 

select EMPNAME, DEPTNAME, JOBNAME, STARTDATE, ENDDATE 
    from CAREER 
    join EMP on EMP.EMPNO = CAREER.EMPNO 
    join JOB on JOB.JOBNO = CAREER.JOBNO 
    join DEPT on DEPT.DEPTNO = CAREER.DEPTNO; 
    
select EMPNAME 
    from CAREER 
    join EMP on EMP.EMPNO = CAREER.EMPNO 
    join JOB on JOB.JOBNO = CAREER.JOBNO 
    join SALARY on SALARY.EMPNO = EMP.EMPNO and SALARY.SALVALUE = JOB.MINSALARY; 

select EMPNAME, case 
    when months_between(CURRENT_DATE, BIRTHDATE)/12 between 20 and 30 then 'A' 
    when months_between(CURRENT_DATE, BIRTHDATE)/12 between 31 and 40 then 'B' 
    when months_between(CURRENT_DATE, BIRTHDATE)/12 between 41 and 50 then 'C' 
    else 'D' 
    end as Age 
    from EMP;  

