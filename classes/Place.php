<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class Place
{
    private $data = [];

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
                $sql = PlaceGateway::SQL.' and p.id=?';
                $result = $zend_db->fetchRow($sql, [$id]);
            }
            if ($result) {
                foreach ($result as $field=>$value) {
                    if ($value) {
                        $this->data[$field] = $value;
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
	/**
	 * Returns any field stored in $data
	 *
	 * @param string $fieldname
	 */
	private function get($fieldname)
	{
		if ( isset($this->data[$fieldname])) {
			return $this->data[$fieldname];
		}
	}

    public function getId()                   { return $this->get('id');                   }
    public function getPlace_name()           { return $this->get('place_name');           }
    public function getShort_name()           { return $this->get('short_name');           }
    public function getStatus()               { return $this->get('status');               }
    public function getLandmark_flag()        { return $this->get('landmark_flag');        }
    public function getVicinity()             { return $this->get('vicinity');             }
    public function getDispatch_citycode()    { return $this->get('dispatch_citycode');    }
    public function getLocation_description() { return $this->get('location_description'); }
    public function getX_coordinate()         { return $this->get('x_coordinate');         }
    public function getY_coordinate()         { return $this->get('y_coordinate');         }
    public function getLatitude()             { return $this->get('latitude');             }
    public function getLongitude()            { return $this->get('longitude');            }
    public function getPublic_entity()        { return $this->get('public_entity');        }
    public function getUse_type()             { return $this->get('use_type');             }
    public function getSub_class()            { return $this->get('sub_class');            }
    public function getMap_label1()           { return $this->get('map_label1');           }
    public function getMap_label2()           { return $this->get('map_label2');           }
    public function getComments()             { return $this->get('comments');             }
    public function getAddress_location_id()  { return $this->get('address_location_id');  }
    public function getStreet_address_id()    { return $this->get('street_address_id');    }
    public function getStreet_id()            { return $this->get('street_id');            }
    public function getStreetaddress()        { return $this->get('streetaddress');        }

    public function getLocation() { return new Location($this->getAddress_location_id()); }
    public function getAddress () { return new Address ($this->getStreet_address_id());   }
    public function getStreet  () { return new Street  ($this->getStreet_id());           }

    //----------------------------------------------------------------
    // Custom functions
    //----------------------------------------------------------------
    /**
     * @return string
     */
    public function getUrl() { return BASE_URL.'/places/view.php?place_id='.$this->getId(); }
}