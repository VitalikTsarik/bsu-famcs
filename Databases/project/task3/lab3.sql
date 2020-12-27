-- 1.
SELECT
    milking,
    massage,
    music,
    washing,
    times         AS "Feeding times",
    min_interval  AS "Feeding min interval",
    fodder_name
FROM
         cow
    JOIN condition ON ( cow.condition_id = condition.id )
    JOIN diet ON ( condition.diet_id = diet.id )
WHERE
    name = 'Molly';
    
-- 2.	
SELECT
    DISTINCT name,
    breed,
    birth_date,
    fat * 100 as "Fat, %"
FROM
         cow
    JOIN milk ON ( cow.id = milk.cow_id )
WHERE
    fat < 0.12;
    
-- 3.
SELECT
    name,
    breed,
    birth_date
FROM
    cow
ORDER BY
    birth_date
FETCH FIRST 5 ROWS ONLY;
