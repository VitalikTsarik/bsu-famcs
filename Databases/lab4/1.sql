CREATE OR REPLACE NONEDITIONABLE TRIGGER check_defected BEFORE
    DELETE ON cow
    FOR EACH ROW
DECLARE
    current_month_quantity  NUMBER;
    previes_month_quantity  NUMBER;
BEGIN
    SELECT
        SUM(quantity)
    INTO current_month_quantity
    FROM
        milk
    WHERE
            cow_id = :old.id
        AND milking_date BETWEEN add_months(trunc(sysdate, 'mm'), - 1) AND trunc(sysdate, 'mm')
    GROUP BY
        id;

    SELECT
        SUM(quantity)
    INTO previes_month_quantity
    FROM
        milk
    WHERE
            cow_id = :old.id
        AND milking_date BETWEEN add_months(trunc(sysdate, 'mm'), - 2) AND add_months(trunc(sysdate, 'mm'), - 1)
    GROUP BY
        id;

    IF ( current_month_quantity / previes_month_quantity > 0.7 ) THEN
        raise_application_error(-20001, 'Cow record can not be deleted. It should have no less than 30% milk quantity decrease to be defected');
    END IF;

END;