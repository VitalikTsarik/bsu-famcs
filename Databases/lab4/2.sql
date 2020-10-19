create or replace TRIGGER place_index_update
BEFORE UPDATE OF PLACE_INDEX ON PLACE 
BEGIN
  raise_application_error(-20001, 'Cow place index can not be updated');
END;


CREATE OR REPLACE TRIGGER milking_and_diet_update BEFORE
    UPDATE OF milking, diet_id ON condition
BEGIN
    raise_application_error(-20001, 'Milking time and diet can not be updated');
END;