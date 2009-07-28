<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Street $this->street
 */
$street = $this->street;
$name = View::escape($street->getStreetName());
$status = View::escape($street->getStatus()->getDescription());
$town = View::escape($street->getTown()->getDescription());
$notes = View::escape($street->getNotes());
?>
<div class="interfaceBox">
	<h2>Street Information
		<?php
			if (userIsAllowed('Street')) {
				$url = new URL(BASE_URL.'/streets/updateStreet.php');
				$url->street_id = $street->getId();
				echo "<a class=\"edit button\" href=\"$url\">Edit</a>";
			}
		?>
	</h2>
	<table>
	<?php
		echo "
		<tr><th>Name</th><td>$name</td></tr>
		<tr><th>Status</th><td>$status</td></tr>
		<tr><th>Town</th><td>$town</td></tr>
		<tr><th>Notes</th><td>$notes</td></tr>
		";
	?>
	</table>
</div>