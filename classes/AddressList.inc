<?php
	class AddressList extends PDOResultIterator
	{
		private $joins = "";
		private $where = "";

		public function __construct($fields=null) { if (is_array($fields)) $this->find($fields); }

		public function find($fields=null,$sort="a.id")
		{
			global $PDO;

			$options = array();
			if (isset($fields['id'])) { $options[] = "a.id='$fields[id]'"; }
			if (isset($fields['place_id'])) { $options[] = "a.place_id='$fields[place_id]'"; }
			if (isset($fields['segment_id'])) { $options[] = "a.segment_id='$fields[segment_id]'"; }
			if (isset($fields['number'])) { $options[] = "a.number='$fields[number]'"; }
			if (isset($fields['suffix'])) { $options[] = "a.suffix='$fields[suffix]'"; }
			if (isset($fields['addressType'])) { $options[] = "a.addressType='$fields[addressType]'"; }
			if (isset($fields['city_id'])) { $options[] = "a.city_id='$fields[city_id]'"; }
			if (isset($fields['zip'])) { $options[] = "a.zip='$fields[zip]'"; }
			if (isset($fields['zipplus4'])) { $options[] = "a.zipplus4='$fields[zipplus4]'"; }
			if (isset($fields['status_id'])) { $options[] = "a.status_id='$fields[status_id]'"; }
			if (isset($fields['active'])) { $options[] = "a.active='$fields[active]'"; }
			if (isset($fields['censusBlockFIPSCode'])) { $options[] = "a.censusBlockFIPSCode='$fields[censusBlockFIPSCode]'"; }
			if (isset($fields['statePlaneX'])) { $options[] = "a.statePlaneX='$fields[statePlaneX]'"; }
			if (isset($fields['statePlaneY'])) { $options[] = "a.statePlaneY='$fields[statePlaneY]'"; }
			if (isset($fields['latitude'])) { $options[] = "a.latitude='$fields[latitude]'"; }
			if (isset($fields['longitude'])) { $options[] = "a.longitude='$fields[longitude]'"; }
			if (isset($fields['startDate'])) { $options[] = "a.startDate='$fields[startDate]'"; }
			if (isset($fields['endDate'])) { $options[] = "a.endDate='$fields[endDate]'"; }
			if (isset($fields['notes'])) { $options[] = "a.notes='$fields[notes]'"; }

			# Searching on street name information requires some joins
			if (isset($fields['direction_id']) || isset($fields['name']) || isset($fields['suffix_id']) || isset($fields['postDirection_id']))
			{
				$this->joins.= "left join streets on a.street_id=streets.id
								left join streetNames on streets.id=streetNames.street_id
								left join names on streetNames.name_id=names.id";
				if (isset($fields['direction_id'])) { $options[] = "direction_id='$fields[direction_id]'"; }
				if (isset($fields['name'])) { $options[] = "name='$fields[name]'"; }
				if (isset($fields['suffix_id'])) { $options[] = "suffix_id='$fields[suffix_id]'"; }
				if (isset($fields['postDirection_id'])) { $options[] = "postDirection_id='$fields[postDirection_id]'"; }
			}

			if (count($options)) { $this->where = " where ".implode(" and ",$options); }
			$sql = "select a.id from addresses a {$this->joins} {$this->where} order by $sort";

			$result = $PDO->query($sql);
			if ($result)
			{
				foreach($result as $row) { $this->list[] = $row['id']; }
			}
			else { $e = $PDO->errorInfo(); throw new Exception($sql.$e[2]); }
		}


		protected function loadResult($key) { return new Address($this->list[$key]); }
	}
?>