-- These are in GIS
create sequence buildings_status_code_seq start with 6 nocache;

create trigger buildings_status_code_trigger
before insert on buildings_status_lookup
for each row
begin
select buildings_status_code_seq.nextval into :new.status_code from dual;
end;
/

-- These are in ENG
create sequence address_status_code_seq start with 6 nocache;

create trigger address_status_code_trigger
before insert on mast_address_status_lookup
for each row
begin
select address_status_code_seq.nextval into :new.status_code from dual;
end;
/

create sequence street_status_code_seq start with 5 nocache;

create trigger street_status_code_trigger
before insert on mast_street_status_lookup
for each row
begin
select street_status_code_seq.nextval into :new.status_code from dual;
end;
/


create trigger subunit_id_trigger
before insert on mast_address_subunits
for each row
begin
select subunit_id_s.nextval into :new.subunit_id from dual;
end;
/

create trigger contact_id_trigger
before insert on mast_addr_assignment_contact
for each row
begin
select contact_id_s.nextval into :new.contact_id from dual;
end;
/

create trigger street_trigger
before insert on mast_street
for each row
begin
select street_id_s.nextval into :new.street_id from dual;
end;
/

create trigger mast_address_trigger
before insert on mast_address
for each row
begin
select street_address_id_s.nextval into :new.street_address_id from dual;
end;
/

create trigger gov_jur_trigger
before insert on governmental_jurisdiction_mast
for each row
begin
select gov_jur_id_s.nextval into :new.gov_jur_id from dual;
end;
/

drop sequence plat_id_s;
create sequence plat_id_s start with 1796 nocache;

create trigger plat_id_trigger
before insert on plat_master
for each row
begin
select plat_id_s.nextval into :new.plat_id from dual;
end;
/
