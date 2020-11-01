CREATE OR REPLACE TRIGGER check_milk AFTER
    INSERT ON milk
    FOR EACH ROW
DECLARE
    previous_milking_date DATE;
BEGIN
    SELECT
        milking_date
    INTO previous_milking_date
    FROM
        milk
    WHERE
        cow_id = :new.id
    ORDER BY
        milking_date DESC
    FETCH FIRST 1 ROWS ONLY;

    IF (
        previous_milking_date != NULL
        AND previous_milking_date - :new.milking_date != 1
    ) THEN
        raise_application_error(-20003, 'Milk should be tested daily');
    END IF;

END;