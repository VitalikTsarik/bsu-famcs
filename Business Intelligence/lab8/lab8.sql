update job 
set minsalary = 500
where minsalary = (select min(minsalary) from job);



update job 
set minsalary = minsalary * 1.1 
where jobname != 'FINANCIAL DIRECTOR';


update job 
set minsalary = minsalary*(case when jobname = 'CLERK' then 1.1 else 1.2 end) 
where jobname in ('CLERK', 'FINANCIAL DIRECTOR');


update job 
set minsalary = 0.9*(select minsalary from job where jobname = 'EXECUTIVE DIRECTOR') 
where jobname = 'FINANCIAL DIRECTOR';


update emp 
set empname = LOWER(empname) 
where empname like 'J%';


update emp
set empname = INITCAP(empname) 
where INSTR(empname, ' ') != 0;


update emp
set empname = UPPER(empname);


update dept 
set deptaddr = (select deptaddr from dept where deptname = 'SALES') 
where deptname = 'RESEARCH';


insert into emp values(
    (select max(empno) from emp) + 1,
    'VITALIK TSARIK',
    to_date('01.01.2000', 'dd.mm.yyyy'), 
    null);


insert into career values (
    1000, 
    (select empno from emp where empname = 'VITALIK TSARIK'),
    10,
    sysdate,
    null);


delete from tmp_emp; 
insert into tmp_emp 
(select empno, empname, birthdate, manager_id FROM EMP 
JOIN CAREER C using (EMPNO) 
JOIN JOB J using (JOBNO) 
WHERE J.JOBNAME = 'CLERK' AND C.ENDDATE IS NULL); delete from tmp_emp; 
insert into tmp_emp 
(select empno, empname, birthdate, manager_id FROM EMP 
JOIN CAREER C using (EMPNO) 
JOIN JOB J using (JOBNO) 
WHERE J.JOBNAME = 'CLERK' AND C.ENDDATE IS NULL);


insert into tmp_emp 
(select * from emp where empno in 
(select empno from career where empno in 
(select empno from(select distinct jobno, empno from career) group by empno having count(empno) = 1) 
and enddate is not null and enddate < sysdate));


insert into tmp_emp 
(select empno, empname, birthdate, manager_id from emp
join career using (empno) 
where startdate is null);


create table tmp_job as select * from job;
delete from tmp_job;
insert into tmp_job select * from job 
where jobno not in (select jobno from career where enddate is null);


insert into salary 
(select empno, to_number(EXTRACT(MONTH FROM add_months(sysdate, -1))) as month, 
to_number(EXTRACT(YEAR FROM add_months(sysdate, -1))) as year, 1.2 * (select minsalary from job where jobno=car.jobno) as salvalue 
from career car where enddate is null);


delete from salary where year = EXTRACT(YEAR from sysdate);


delete from career where enddate <= sysdate and enddate is not null;


delete from salary where empno in (select empno from emp join career using (empno) where startdate is null);


delete from salary where empno in (select empno from emp join career using (empno) where startdate is null);








