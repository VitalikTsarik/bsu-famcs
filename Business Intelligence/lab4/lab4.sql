select ceil(row_number() over(order by empno)/5.0) grp, 
    month, 
    year, 
    salvalue 
from salary; 



select ntile(10) over(order by empno) grp, 
    month, 
    year, 
    salvalue 
from salary 
order by grp; 



select empno, 
    lpad('-', count(*), '-') count 
from salary 
group by empno 
order by count desc; 




select max(empno_7369) empno_7369, 
    max(empno_7499) empno_7499,  
    max(empno_7789) empno_7789,  
    max(empno_7790) empno_7790 
from (
    select row_number() over(partition by empno order by empno) rn, 
        case when empno=7369 then '|' else ' ' end empno_7369, 
        case when empno=7499 then '|' else ' ' end empno_7499, 
        case when empno=7789 then '|' else ' ' end empno_7789, 
        case when empno=7790 then '|' else ' ' end empno_7790
    from salary 
) 
group by rn 
order by 1, 2, 3, 4; 
