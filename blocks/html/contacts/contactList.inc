<?php
/**
 * @copyright 2009-2014 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param ContactList $this->contactList
 */
?>
<div class="interfaceBox">
	<h1><?php
			if (userIsAllowed('Contact')) {
				echo "
				<button type=\"button\" class=\"add\" onclick=\"document.location.href='".BASE_URL."/contacts/updateContact.php';\">
					Add
				</button>
				";
			}
		?>
		Contacts
	</h1>
	<table>
		<thead>
			<tr><th></th>
				<th>Name</th>
				<th>Notification</th>
				<th>Coordination</th>
                <th>Email</th>
				<th>Phone</th>
				<th>Type</th>
				<th>Organization</th>
				<th>Status</th>
			</tr>
		</thead>
		<tbody>
		<?php
			foreach ($this->contactList as $contact) {
				$editButton = '';
				if (userIsAllowed('Contact')) {
					$url = new URL(BASE_URL.'/contacts/updateContact.php');
					$url->contact_id = $contact->getContact_id();
					$editButton = "
					<button type=\"button\" class=\"edit\" onclick=\"document.location.href='$url';\">
						Edit
					</button>
					";
				}
				$url = new URL(BASE_URL.'/contacts/viewContact.php');
				$url->contact_id = $contact->getContact_id();
				$name = View::escape("{$contact->getFirstname()} {$contact->getLastname()}");
				$name = "<a href=\"$url\">$name</a>";
				$email = View::escape($contact->getEmail());
				$phone = View::escape($contact->getPhone_number());
				echo "
				<tr><td>$editButton</td>
					<td>$name</td>
					<td>{$contact->getNotification()}</td>
					<td>{$contact->getCoordination()}</td>
					<td>$email</td>
					<td>$phone</td>
					<td>{$contact->getType()}</td>
					<td>{$contact->getAgency()}</td>
					<td>{$contact->getStatus()}</td>
				</tr>
				";
			}
		?>
		</tbody>
	</table>
</div>
