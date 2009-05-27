grant select,insert,update,delete on eng.address_location to master_address;
grant select,insert,update,delete on eng.addr_jurisdiction_master to master_address;
grant select,insert,update,delete on eng.addr_location_purpose_mast to master_address;
grant select,insert,update,delete on eng.addr_location_purposes to master_address;
grant select,insert,update,delete on eng.addr_location_rel_types_mast to master_address;
grant select,insert,update,delete on eng.addr_location_relationships to master_address;
grant select,insert,update,delete on eng.addr_location_types_master to master_address;
grant select,insert,update,delete on eng.governmental_jurisdiction_mast to master_address;
grant select,insert,update,delete on eng.mast_addr_assignment_contact to master_address;
grant select,insert,update,delete on eng.mast_address to master_address;
grant select,insert,update,delete on eng.mast_address_annexation to master_address;
grant select,insert,update,delete on eng.mast_address_assignment_hist to master_address;
grant select,insert,update,delete on eng.mast_address_location_change to master_address;
grant select,insert,update,delete on eng.mast_address_location_status to master_address;
grant select,insert,update,delete on eng.mast_address_sanitation to master_address;
grant select,insert,update,delete on eng.mast_address_status to master_address;
grant select,insert,update,delete on eng.mast_address_status_lookup to master_address;
grant select,insert,update,delete on eng.mast_address_subunit_status to master_address;
grant select,insert,update,delete on eng.mast_address_subunits to master_address;
grant select,insert,update,delete on eng.mast_street to master_address;
grant select,insert,update,delete on eng.mast_street_addr_jurisdictions to master_address;
grant select,insert,update,delete on eng.mast_street_direction_master to master_address;
grant select,insert,update,delete on eng.mast_street_gov_jurisdictions to master_address;
grant select,insert,update,delete on eng.mast_street_name_type_master to master_address;
grant select,insert,update,delete on eng.mast_street_names to master_address;
grant select,insert,update,delete on eng.mast_street_plat to master_address;
grant select,insert,update,delete on eng.mast_street_section to master_address;
grant select,insert,update,delete on eng.mast_street_state_road to master_address;
grant select,insert,update,delete on eng.mast_street_status_lookup to master_address;
grant select,insert,update,delete on eng.mast_street_subdivision to master_address;
grant select,insert,update,delete on eng.mast_street_townships to master_address;
grant select,insert,update,delete on eng.mast_street_type_suffix_master to master_address;
grant select,insert,update,delete on eng.newmaststreet to master_address;
grant select,insert,update,delete on eng.newmaststreetalias to master_address;
grant select,insert,update,delete on eng.newmaststreethistory to master_address;
grant select,insert,update,delete on eng.newmaststreetnames to master_address;
grant select,insert,update,delete on eng.plat_master to master_address;
grant select,insert,update,delete on eng.quarter_section_master to master_address;
grant select,insert,update,delete on eng.state_road_master to master_address;
grant select,insert,update,delete on eng.subdivision_master to master_address;
grant select,insert,update,delete on eng.subdivision_names to master_address;
grant select,insert,update,delete on eng.towns_master to master_address;
grant select,insert,update,delete on eng.township_master to master_address;
grant select,insert,update,delete on eng.trash_pickup_master to master_address;
grant select,insert,update,delete on eng.trash_recycle_week_master to master_address;

grant select,insert,update,delete on eng.people to master_address;
grant select,insert,update,delete on eng.users to master_address;
grant select,insert,update,delete on eng.roles to master_address;
grant select,insert,update,delete on eng.user_roles to master_address;


grant select on eng.gov_jur_id_s to master_address;
grant select on eng.jurisdiction_id_s to master_address;
grant select on eng.location_change_id_s to master_address;
grant select on eng.location_id_s to master_address;
grant select on eng.location_purpose_id_s to master_address;
grant select on eng.people_id_seq to master_address;
grant select on eng.plat_id_s to master_address;
grant select on eng.roles_id_seq to master_address;
grant select on eng.street_address_id_s to master_address;
grant select on eng.street_id_s to master_address;
grant select on eng.subdivision_id_s to master_address;
grant select on eng.subdivision_name_id_s to master_address;
grant select on eng.subunit_id_s to master_address;
grant select on eng.town_id_s to master_address;
grant select on eng.township_id_s to master_address;
grant select on eng.users_id_seq to master_address;




create synonym master_address.address_location for eng.address_location;
create synonym master_address.addr_location_purpose_mast for eng.addr_location_purpose_mast;
create synonym master_address.addr_location_purposes for eng.addr_location_purposes;
create synonym master_address.addr_location_rel_types_mast for eng.addr_location_rel_types_mast;
create synonym master_address.addr_location_relationships for eng.addr_location_relationships;
create synonym master_address.addr_location_types_master for eng.addr_location_types_master;
create synonym master_address.governmental_jurisdiction_mast for eng.governmental_jurisdiction_mast;
create synonym master_address.mast_addr_assignment_contact for eng.mast_addr_assignment_contact;
create synonym master_address.mast_address for eng.mast_address;
create synonym master_address.mast_address_annexation for eng.mast_address_annexation;
create synonym master_address.mast_address_assignment_hist for eng.mast_address_assignment_hist;
create synonym master_address.mast_address_location_change for eng.mast_address_location_change;
create synonym master_address.mast_address_location_status for eng.mast_address_location_status;
create synonym master_address.mast_address_sanitation for eng.mast_address_sanitation;
create synonym master_address.mast_address_status for eng.mast_address_status;
create synonym master_address.mast_address_status_lookup for eng.mast_address_status_lookup;
create synonym master_address.mast_address_subunit_status for eng.mast_address_subunit_status;
create synonym master_address.mast_address_subunits for eng.mast_address_subunits;
create synonym master_address.mast_street for eng.mast_street;
create synonym master_address.mast_street_addr_jurisdictions for eng.mast_street_addr_jurisdictions;
create synonym master_address.mast_street_direction_master for eng.mast_street_direction_master;
create synonym master_address.mast_street_gov_jurisdictions for eng.mast_street_gov_jurisdictions;
create synonym master_address.mast_street_name_type_master for eng.mast_street_name_type_master;
create synonym master_address.mast_street_names for eng.mast_street_names;
create synonym master_address.mast_street_plat for eng.mast_street_plat;
create synonym master_address.mast_street_section for eng.mast_street_section;
create synonym master_address.mast_street_state_road for eng.mast_street_state_road;
create synonym master_address.mast_street_status_lookup for eng.mast_street_status_lookup;
create synonym master_address.mast_street_subdivision for eng.mast_street_subdivision;
create synonym master_address.mast_street_townships for eng.mast_street_townships;
create synonym master_address.mast_street_type_suffix_master for eng.mast_street_type_suffix_master;
create synonym master_address.newmaststreet for eng.newmaststreet;
create synonym master_address.newmaststreetalias for eng.newmaststreetalias;
create synonym master_address.newmaststreethistory for eng.newmaststreethistory;
create synonym master_address.newmaststreetnames for eng.newmaststreetnames;
create synonym master_address.plat_master for eng.plat_master;
create synonym master_address.quarter_section_master for eng.quarter_section_master;
create synonym master_address.state_road_master for eng.state_road_master;
create synonym master_address.subdivision_master for eng.subdivision_master;
create synonym master_address.subdivision_names for eng.subdivision_names;
create synonym master_address.towns_master for eng.towns_master;
create synonym master_address.township_master for eng.township_master;
create synonym master_address.trash_pickup_master for eng.trash_pickup_master;
create synonym master_address.trash_recycle_week_master for eng.trash_recycle_week_master;

create synonym master_address.people for eng.people;
create synonym master_address.users for eng.users;
create synonym master_address.roles for eng.roles;
create synonym master_address.user_roles for eng.user_roles;


create synonym master_address.gov_jur_id_s for eng.gov_jur_id_s;
create synonym master_address.location_change_id_s for eng.location_change_id_s;
create synonym master_address.location_id_s for eng.location_id_s;
create synonym master_address.location_purpose_id_s for eng.location_purpose_id_s;
create synonym master_address.people_id_seq for eng.people_id_seq;
create synonym master_address.plat_id_s for eng.plat_id_s;
create synonym master_address.roles_id_seq for eng.roles_id_seq;
create synonym master_address.street_address_id_s for eng.street_address_id_s;
create synonym master_address.street_id_s for eng.street_id_s;
create synonym master_address.subdivision_id_s for eng.subdivision_id_s;
create synonym master_address.subdivision_name_id_s for eng.subdivision_name_id_s;
create synonym master_address.subunit_id_s for eng.subunit_id_s;
create synonym master_address.town_id_s for eng.town_id_s;
create synonym master_address.township_id_s for eng.township_id_s;
create synonym master_address.users_id_seq for eng.users_id_seq;


grant select,insert,update,delete on gis.annexations to master_address;
grant select,insert,update,delete on gis.building_address_location to master_address;
grant select,insert,update,delete on gis.building_types_master to master_address;
grant select,insert,update,delete on gis.buildings to master_address;
grant select,insert,update,delete on gis.buildings_status_lookup to master_address;
grant select,insert,update,delete on gis.mast_address_parcel to master_address;
grant select,insert,update,delete on gis.parcel to master_address;
grant select,insert,update,delete on gis.precinct_address_location to master_address;
grant select,insert,update,delete on gis.voting_precincts to master_address;


grant select on gis.building_id_s to master_address;
grant select on gis.building_type_id_s to master_address;


create synonym master_address.annexations for gis.annexations;
create synonym master_address.building_address_location for gis.building_address_location;
create synonym master_address.building_types_master for gis.building_types_master;
create synonym master_address.buildings for gis.buildings;
create synonym master_address.buildings_status_lookup for gis.buildings_status_lookup;
create synonym master_address.mast_address_parcel for gis.mast_address_parcel;
create synonym master_address.parcel for gis.parcel;
create synonym master_address.precinct_address_location for gis.precinct_address_location;
create synonym master_address.voting_precincts for gis.voting_precincts;


create synonym master_address.building_id_s for gis.building_id_s;
create synonym master_address.building_type_id_s for gis.building_type_id_s;