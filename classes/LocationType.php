<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class LocationType
{
	private $location_type_id;
	private $description;

	private $location_type;

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
	 * @param int|array $location_type_id
	 */
	public function __construct($location_type_id=null)
	{
		if ($location_type_id) {
			if (is_array($location_type_id)) {
				$result = $location_type_id;
			}
			else {
				$zend_db = Database::getConnection();
				$sql = 'select * from addr_location_types_master where location_type_id=?';
				$result = $zend_db->fetchRow($sql,array($location_type_id));
			}

			if ($result) {
				foreach ($result as $field=>$value) {
					if ($value) {
						$this->$field = $value;
					}
				}
			}
			else {
				throw new Exception('locations/unknownLocationType');
			}
		}
		else {
			
			// This is where the code goes to generate a new, empty instance.
			// Set any default values for properties that need it here
		}
	}

	/**
	 * Throws an exception if anything's wrong
	 * @throws Exception $e
	 */
	public function validate()
	{
		// Check for required fields here.  Throw an exception if anything is missing.
		if (!$this->location_type_id || !$this->description) {
			throw new Exception('missingRequiredFields');
		}
	}

	/**
	 * Saves this record back to the database
	 */
	public function save()
	{
		$this->validate();

		$zend_db = Database::getConnection();
		$sql = 'select count(*) from addr_location_types_master where location_type_id=?';
		$count = $zend_db->fetchOne($sql,$this->location_type_id);

		if ($count) {
			$this->update();
		}
		else {
			$this->insert();
		}
	}

	private function update()
	{
		$zend_db = Database::getConnection();
		$data = array('description'=>$this->description);
		$zend_db->update('addr_location_types_master',
						$data,
						"location_type_id='{$this->location_type_id}'");
	}

	private function insert()
	{
		$data = array('location_type_id'=>$this->location_type_id,
						'description'=>$this->description);

		$zend_db = Database::getConnection();
		$zend_db->insert('addr_location_types_master',$data);
	}

	//----------------------------------------------------------------
	// Generic Getters
	//----------------------------------------------------------------
	/**
	 * Alias for getLocation_type_id()
	 * @return string
	 */
	public function getId()
	{
		return $this->getLocation_type_id();
	}

	/**
	 * @return string
	 */
	public function getLocation_type_id()
	{
		return $this->location_type_id;
	}

	/**
	 * @return string
	 */
	public function getDescription()
	{
		return $this->description;
	}

	//----------------------------------------------------------------
	// Generic Setters
	//----------------------------------------------------------------
	/**
	 * @param string $string
	 */
	public function setLocation_type_id($string)
	{
		$this->location_type_id = preg_replace('/[^a-zA-Z0-9\s]/','',$string);
	}

	/**
	 * @param string $string
	 */
	public function setDescription($string)
	{
		$this->description = trim($string);
	}


	//----------------------------------------------------------------
	// Custom Functions
	// We recommend adding all your custom code down here at the bottom
	//----------------------------------------------------------------
	public function __toString()
	{
		return $this->getLocation_type_id();
	}
}
