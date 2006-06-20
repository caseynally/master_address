<?php
	class PlaceType
	{
		private $id;
		private $type;
		private $description;



		public function __construct($id=null)
		{
			global $PDO;

			if ($id)
			{
				$sql = "select * from placeTypes where id=$id";
				$result = $PDO->query($sql);
				if ($result)
				{
					if ($row = $result->fetch())
					{
						$this->id = $id;
						$this->type = $row['type'];
						$this->description = $row['description'];

						$result->closeCursor();
					}
					else { throw new Exception($sql); }
				}
				else { $e = $PDO->errorInfo(); throw new Exception($sql.$e[2]); }
			}
			else
			{
				# This is where the code goes to generate a new, empty instance.
				# Set any default values for properties that need it here
			}
		}


		public function save()
		{
			# Check for required fields here.  Throw an exception if anything is missing.
			if (!$this->type) { throw new Exception("missingRequiredFields"); }


			$fields = array();
			$fields[] = "type='{$this->type}'";
			if ($this->description) { $fields[] = "description='{$this->description}'"; } else { $fields[] = "description=null"; }
			$fields = implode(",",$fields);


			if ($this->id) { $this->update($fields); }
			else { $this->insert($fields); }
		}

		private function update($fields)
		{
			global $PDO;

			$sql = "update placeTypes set $fields where id={$this->id}";
			if (false === $PDO->exec($sql)) { $e = $PDO->errorInfo(); throw new Exception($sql.$e[2]); }
		}

		private function insert($fields)
		{
			global $PDO;

			$sql = "insert placeTypes set $fields";
			if (false === $PDO->exec($sql)) { $e = $PDO->errorInfo(); throw new Exception($sql.$e[2]); }
			$this->id = $PDO->lastInsertID();
		}


		public function getId() { return $this->id; }
		public function getType() { return $this->type; }
		public function getDescription() { return $this->description; }


		public function setType($string) { $this->type = sanitizeString($string); }
		public function setDescription($string) { $this->description = sanitizeString($string); }
	}
?>