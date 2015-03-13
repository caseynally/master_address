<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class Place
{
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
        'comments'
    ];

    private $id;
    private $place_name;
    private $short_name;
    private $status;
    private $landmark_flag;
    private $vicinity;
    private $dispatch_citycode;
    private $address_location_id;
    private $location_description;
    private $x_coordinate;
    private $y_coordinate;
    private $latitude;
    private $longitude;
    private $public_entity;
    private $use_type;
    private $sub_class;
    private $map_label1;
    private $map_label2;
    private $comments;

    /**
     * Populates the object with data
     *
     * Passing in an associative array of data will populate this object without
     * hitting the database.
     *
     * Passing in a scalar will load the data from the database.
     * This will load all fields in the table as properties of this class.
     * You may want to replace this with, or add your own extra, custom loading
     *
     * @param int|array $direction_code
     */
    public function __construct($id=null)
    {
        if ($id) {
            if (is_array($id)) {
                $result = $id;
            }
            else {
                $zend_db = Database::getConnection();
                $sql = 'select * from gis.places where id=?';
                $result = $zend_db->fetchRow($sql, [$id]);
            }
            if ($result) {
                foreach ($result as $field=>$value) {
                    if ($value) {
                        $this->$field = $value;
                    }
                }
            }
            else {
                throw new Exception('places/unknownPlace');
            }
        }
        else {
            // This is where the code goes to generate a new, empty instance.
            // Set any default values for properties that need it here
        }
    }

    //----------------------------------------------------------------
    // Generic Getters
    //----------------------------------------------------------------
    public function getId()                   { return $this->id;                   }
    public function getPlace_name()           { return $this->place_name;           }
    public function getShort_name()           { return $this->short_name;           }
    public function getStatus()               { return $this->status;               }
    public function getLandmark_flag()        { return $this->landmark_flag;        }
    public function getVicinity()             { return $this->vicinity;             }
    public function getDispatch_citycode()    { return $this->dispatch_citycode;    }
    public function getAddress_location_id()  { return $this->address_location_id;  }
    public function getLocation_description() { return $this->location_description; }
    public function getX_coordinate()         { return $this->x_coordinate;         }
    public function getY_coordinate()         { return $this->y_coordinate;         }
    public function getLatitude()             { return $this->latitude;             }
    public function getLongitude()            { return $this->longitude;            }
    public function getPublic_entity()        { return $this->public_entity;        }
    public function getUse_type()             { return $this->use_type;             }
    public function getSub_class()            { return $this->sub_class;            }
    public function getMap_label1()           { return $this->map_label1;           }
    public function getMap_label2()           { return $this->map_label2;           }
    public function getComments()             { return $this->comments;             }

    //----------------------------------------------------------------
    // Custom functions
    //----------------------------------------------------------------
    /**
     * @return string
     */
    public function getUrl() { return BASE_URL.'/places/view.php?place_id='.$this->id; }

    /**
     * @return Location
     */
    public function getLocation()
    {
        return new Location($this->address_location_id);
    }

    /**
     * @return Address
     */
    public function getAddress()
    {
        $location  = $this->getLocation();
        $addresses = $location->getAddresses(['active'=>'Y']);
        if (count($addresses)) {
            return $addresses[0];
        }
    }
}