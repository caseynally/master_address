<?php
	class StreetNameList extends PDOResultIterator
	{
		public function __construct($fields=null) { if (is_array($fields)) $this->find($fields); }

		public function find($fields=null,$sort="id")
		{
			global $PDO;

			$options = array();
			if (isset($fields['id'])) { $options[] = "id=$fields[id]"; }
			if (isset($fields['street_id'])) { $options[] = "street_id=$fields[street_id]"; }
			if (isset($fields['name_id'])) { $options[] = "name_id=$fields[name_id]"; }
			if (isset($fields['streetNameType_id'])) { $options[] = "streetNameType_id=$fields[streetNameType_id]"; }

			if (count($options)) { $where = " where ".implode(" and ",$options); } else { $where = ""; }
			$sql = "select id from streetNames $where order by $sort";

			$result = $PDO->query($sql);
			if ($result)
			{
				foreach($result as $row) { $this->list[] = $row['id']; }
			}
			else { $e = $PDO->errorInfo(); throw new Exception($sql.$e[2]); }
		}


		protected function loadResult($key) { return new StreetName($this->list[$key]); }
	}
?>