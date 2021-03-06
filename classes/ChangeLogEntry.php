<?php
/**
 * A class to encapsulate the information logged whenever someone makes a change
 * to something in the database.  All of the log tables will have these same fields
 *
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class ChangeLogEntry
{
	public $user_id;
	public $action;
	public $contact_id;
	public $notes;
	public $action_date;

	public $type;
	public $id;

	private $user;
	private $contact;

	public static $actions = array( 'add'=>'added','assign'=>'assigned','activate'=>'activated',
									'create'=>'created','propose'=>'proposed','correct'=>'corrected',
									'alias'=>'added alias','change'=>'changed street name',
									'update'=>'updated','move'=>'moved to location',
									'readdress'=>'readdressed','reassign'=>'reassigned',
									'unretire'=>'unretired','retire'=>'retired',
									'verify'=>'verified');

	/**
	 * Creates a new entry for the change log
	 *
	 * Only the User is required.  You must pass the user in the first parameter.
	 * You can pass all the of the data as an array in the first paramter....
	 * Or you can pass the User and the data seperately
	 *
	 * @param User|array $user
	 * @param array $data
	 */
	public function __construct($user,array $data=null)
	{
		if ($user instanceof User) {
			$this->user = $user;
			$this->user_id = $user->getId();
		}
		elseif (is_array($user)) {
			$this->parseArray($user);
		}
		else {
			$this->user_id = $user;
		}

		if ($data) {
			$this->parseArray($data);
		}


		if (!$this->action_date) {
			$this->action_date = new Date();
		}

		if (!$this->user_id) {
			throw new Exception('logEntry/missingUser');
		}

		if (!$this->action) {
			throw new Exception('logEntry/missingAction');
		}
		if (!$this->contact_id) {
			throw new Exception('logEntry/missingContact');
		}
	}

	/**
	 * @param array $data
	 */
	private function parseArray(array $data)
	{
		foreach ($data as $field=>$value) {
			switch ($field) {
				case 'action_date':
					$value = new Date($value);
					break;
				case 'action':
					if (in_array($value,array_keys(self::$actions))) {
						$value = self::$actions[$value];
					}
					elseif (!in_array($value,self::$actions)) {
						throw new Exception('logEntry/unknownAction');
					}
					break;
			}
			$this->$field = $value;
		}
	}

	/**
	 * Returns the array of data, ready to insert into the database
	 *
	 * @return array
	 */
	public function getData()
	{
		return array('user_id'=>$this->user_id,'action'=>$this->action,
					 'contact_id'=>$this->contact_id,'notes'=>$this->notes,
					 'action_date'=>$this->action_date->format('Y-m-d H:i:s'));
	}

	/**
	 * @return User
	 */
	public function getUser()
	{
		if (!$this->user) {
			$this->user = new User($this->user_id);
		}
		return $this->user;
	}

	/**
	 * @return Contact
	 */
	public function getContact()
	{
		if (!$this->contact) {
			$this->contact = new Contact($this->contact_id);
		}
		return $this->contact;
	}

	/**
	 * Returns the object that was the target of this action
	 *
	 * This will only work if it knows the type and id
	 *
	 * @return Address|Street|Subunit
	 */
	public function getTarget()
	{
		if ($this->type) {
			if ($this->id) {
				return new $this->type($this->id);
			}
		}
	}
}