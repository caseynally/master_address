<?php
	require_once(APPLICATION_HOME."/classes/User.inc");
	require_once(GLOBAL_INCLUDES."/classes/PDOResultIterator.inc");

	class UserList extends PDOResultIterator
	{
		public function find($fields=null,$sort = "username")
		{
			global $PDO;

			if ($fields)
			{
				$options = array();
				$sql = "select distinct users.userID from users";

				if (isset($fields['userID'])) { $options[] = "userID=$fields[userID]"; }
				if (isset($fields['username'])) { $options[] = "username='$fields[username]'"; }
				if (isset($fields['authenticationMethod'])) { $options[] = "authenticationMethod='$fields[authenticationMethod]'"; }
				if (isset($fields['firstname'])) { $options[] = "firstname='$fields[firstname]'"; }
				if (isset($fields['lastname'])) { $options[] = "lastname='$fields[lastname]'"; }
				if (isset($fields['phone'])) { $options[] = "phone='$fields[phone]'"; }
				if (isset($fields['email'])) { $options[] = "email='$fields[email]'"; }
				if (isset($fields['institutionID'])) { $options[] = "institutionID=$fields[institutionID]"; }
				if (isset($fields['departmentID'])) { $options[] = "departmentID=$fields[departmentID]"; }

				# To search on Role, you have to join the userRoles table
				if (isset($fields['role']))
				{
					$sql = " left join userRoles using (userID)";
					$options[] = "role='$fields[role]'";
				}

				$where = " where ".implode(" and ",$options);
				$sql.= "$where order by $sort";
			}
			else { $sql = "select userID from users order by $sort"; }

			foreach($PDO->query($sql) as $row) { $this->list[] = $row['userID']; }
		}

		protected function loadCurrent() { return new User(current($this->list)); }
	}
?>