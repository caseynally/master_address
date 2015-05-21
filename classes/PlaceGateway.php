<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class PlaceGateway
{
    const SQL = "select distinct p.*, l.street_address_id, a.street_id,
                    rtrim(a.street_number || ' ' || a.street_number_suffix) || ' ' ||
                    rtrim(n.street_direction_code) || ' ' ||
                    n.street_name || ' ' ||
                    n.street_type_suffix_code || ' ' ||
                    rtrim(n.post_direction_suffix_code) as streetaddress
                from gis.places p
                join gis.place_point_of_interest i on p.id=i.place_id
                join eng.address_location        l on p.address_location_id=l.location_id
                join eng.mast_address            a on l.street_address_id=a.street_address_id
                join eng.mast_street             s on a.street_id=s.street_id
                join eng.mast_street_names       n on s.street_id=n.street_id
                where i.publish_flag = 'Y'
                    and l.subunit_id is null
                    and l.active='Y'
                    and n.street_name_type='STREET'";

    public static $fields = [
        'id',
        'place_name',
        'short_name',
        'status',
        'landmark_flag',
        'vicinity',
        'dispatch_citycode',
        'address_location_id',
        'location_description',
        'x_coordinate',
        'y_coordinate',
        'latitude',
        'longitude',
        'public_entity',
        'use_type',
        'sub_class',
        'map_label1',
        'map_label2',
        'comments',
        'street_address_id',
        'street_id',
        'streetaddress'
    ];
    /**
     * Populates the collection
     *
     * @param array $fields
     * @param string $order
     * @return array An array of Person objects
     */
    public static function find($fields=null, $order='p.place_name')
    {
        $sql = self::SQL;

        $params = [];
        if (!isset($_SESSION['USER'])) {
            $sql.= ' and i.publish_flag=?';
            $params[] = 'Y';
        }

        if (count($fields)) {
            foreach ($fields as $key=>$value) {
                if (in_array($key, self::$fields) && $value) {
                    $sql.= " and p.$key=?";
                    $params[] = $value;
                }
            }
        }

        $sql.= " order by $order";
        $zend_db = Database::getConnection();
        $result = $zend_db->fetchAll($sql, $params);
        $out = [];
        foreach ($result as $row) {
            $out[] = new Place($row);
        }
        return $out;
    }

    /**
     * @return array
     */
    public static function getUse_types()
    {
        $zend_db = Database::getConnection();
        $sql = "select use_type from gis.place_use_types order by use_type";
        $result = $zend_db->fetchCol($sql);
        return $result;
    }

    /**
     * @return array
     */
    public static function getStatuses()
    {
        $zend_db = Database::getConnection();
        $sql = "select distinct status from gis.places order by status";
        $result = $zend_db->fetchCol($sql);
        return $result;
    }
}
