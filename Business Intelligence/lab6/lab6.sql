select startdate - 10, startdate + 10, add_months(startdate,6), 
add_months(startdate,-6), add_months(startdate,12), add_months(startdate,-12) 
from career join emp using(empno) 
where empname='JOHN KLINTON'; 


select abs((select startdate from career join emp using(empno) where empname='JOHN MARTIN') - 
    (select startdate from career join emp using(empno) where empname='ALEX BOUSH')) as "Date diff" 
from dual; 


select abs(round(months_between((select startdate from career join emp using(empno) where empname='JOHN MARTIN'), 
    (select startdate from career join emp using(empno) where empname='ALEX BOUSH')))) as "months diff", 
    abs(floor(months_between((select startdate from career join emp using(empno) where empname='JOHN MARTIN'), 
    (select startdate from career join emp using(empno) where empname='ALEX BOUSH'))/12)) as "years diff"  
from dual; 


select abs(startdate - (LEAD(startdate,1) OVER (ORDER BY startdate))) 
from career join emp using(empno) join dept using(deptno) 
where deptno=20; 


select empname, 
    add_months(trunc(startdate, 'year'), 12) - trunc(startdate, 'year') 
from career join emp using(empno);  


select to_number(to_char(CURRENT_DATE, 'dd')), to_number(to_char(CURRENT_DATE, 'mm')), to_char(CURRENT_DATE, 'yyyy'), 
    to_number(to_char(CURRENT_DATE, 'hh24')), to_number(to_char(CURRENT_DATE, 'mi')), to_number(to_char(CURRENT_DATE, 'ss'))  
from dual;  


select last_day(CURRENT_DATE), last_day(add_months(CURRENT_DATE,-1)) + 1 
from dual;  


select trunc(CURRENT_DATE, 'year'), add_months(trunc(CURRENT_DATE, 'year'),3), 
    add_months(trunc(CURRENT_DATE, 'year'),6), add_months(trunc(CURRENT_DATE, 'year'),9), 
    add_months(trunc(CURRENT_DATE, 'year'),3) - 1, add_months(trunc(CURRENT_DATE, 'year'),6) - 1, 
    add_months(trunc(CURRENT_DATE, 'year'),9) - 1, add_months(trunc(CURRENT_DATE, 'year'),12) - 1  
from dual;  


select * from ( 
  select trunc(CURRENT_DATE, 'year') + rownum - 1 mondays from dual 
  connect by level <= 366 
) 
where  to_char(mondays, 'fmday') = 'monday'; 


select max(case dow when '1' then d else null end) Mon,  
   max(case dow when '2' then d else null end) Tue, 
   max(case dow when '3' then d else null end) Wed, 
   max(case dow when '4' then d else null end) Thu, 
   max(case dow when '5' then d else null end) Fri, 
   max(case dow when '6' then d else null end) Sat, 
   max(case dow when '7' then d else null end) Sun 
from 
(select rownum d, 
   rownum - 3 + to_number(to_char(trunc(CURRENT_DATE,'MM'),'D')) p, 
   to_char(trunc(CURRENT_DATE,'MM') - 2 + rownum,'D') dow 
from dual 
connect by level <= 31) 
group by trunc(p / 7) 
order by trunc(p / 7); 