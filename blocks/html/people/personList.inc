<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param PersonList $this->personList
 */
?>
<div class="interfaceBox">
	<h1><?php
			if (userIsAllowed('Person')) {
				echo "
				<button type=\"button\" class=\"add\" onclick=\"document.location.href='".BASE_URL."/people/addPerson.php';\">
					Add a person
				</button>
				";
			}
		?>
		People
	</h1>
	<table>
	<?php
		foreach ($this->personList as $person) {
			$editButton = '';

			if (userIsAllowed('Person')) {
				$url = new URL(BASE_URL.'/people/updatePerson.php');
				$url->person_id = $person->getId();
				$editButton = "
				<button type=\"button\" class=\"edit\" onclick=\"document.location.href='$url';\">
					Edit Person
				</a>
				";
			}

			$name = View::escape($person->getFullname());
			echo "
			<tr><td>$editButton</td>
				<td>{$person->getUsername()}</td>
				<td><a href=\"{$person->getURL()}\">$name</a></td>
				<td>{$person->getEmail()}</td>
			</tr>
			";
		}
	?>
	</table>
</div>
