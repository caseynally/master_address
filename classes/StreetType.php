<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class StreetType
{
	private $suffix_code;
	private $description;
    private $id;
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
	 * @param int|array $suffix_code
	 */
	public function __construct($id=null)
	{
		if ($id) {
			if (is_array($id)) {
				$result = $id;
			}
			else {
				$zend_db = Database::getConnection();
				if (is_numeric($id)) {
					$sql = 'select * from mast_street_type_suffix_master where id=?';
					$result = $zend_db->fetchRow($sql,array($id));
				}
				else {
					$sql = "select * from mast_street_type_suffix_master
							where suffix_code=? or description=?";
					$result = $zend_db->fetchRow($sql,array($id,$id));
				}
			}

			if ($result) {
				foreach ($result as $field=>$value) {
					if ($value) {
						$this->$field = $value;
					}
				}
			}
			else {
				throw new Exception('streets/unknownStreetTypeSuffix');
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
		if (!$this->description || !$this->suffix_code) {
			throw new Exception('missingRequiredFields');
		}

	}

	/**
	 * Saves this record back to the database
	 */
	public function save()
	{
		$this->validate();

		$data = array();
		$data['description'] = $this->description;
		$data['suffix_code'] = $this->suffix_code;
		if ($this->id) {
			$this->update($data);
		}
		else {
			$this->insert($data);
		}
	}

	private function update($data)
	{
		$zend_db = Database::getConnection();
		$zend_db->update('mast_street_type_suffix_master',$data,"id={$this->id}");
	}

	private function insert($data)
	{
	  $zend_db = Database::getConnection();
		$zend_db->insert('mast_street_type_suffix_master',$data);
		if (Database::getType()=='oracle') {
		    $this->id = $zend_db->lastSequenceId('suffix_id_seq');
		}
		else {
		    $this->id = $zend_db->lastInsertId('mast_street_type_suffix_master','id');
		}
	}

	//----------------------------------------------------------------
	// Generic Getters
	//----------------------------------------------------------------
	/**
	 * return $string
	 */
	public function getId()
	{
		return $this->id;
	}

	/**
	 * Alias for getSuffix_code()
	 *
	 * @return string
	 */
	public function getCode()
	{
		return $this->getSuffix_code();
	}

	/**
	 * @return string
	 */
	public function getSuffix_code()
	{
		return $this->suffix_code;
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
	public function setDescription($string)
	{
		$this->description = trim($string);
	}

	/**
	 * @param string $string
	 */
	public function setSuffix_code($string)
	{
		$this->suffix_code = trim($string);
	}
	//----------------------------------------------------------------
	// Custom Functions
	// We recommend adding all your custom code down here at the bottom
	//----------------------------------------------------------------
	public function __toString()
	{
		return "{$this->getDescription()}";
	}
}
