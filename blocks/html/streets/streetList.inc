<div class="interfaceBox">
<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param StreetList $this->streetList
 */
if (count($this->streetList)) {
	echo "
	<table>
		<thead>
			<tr>
				<th>Street Name</th>
				<th>Status</th>
				<th>Town</th>
			</tr>
		</thead>
		<tbody>
	";
		foreach ($this->streetList as $street) {
			$name = View::escape($street->getStreetName());
			$status = View::escape($street->getStatus()->getDescription());
			$town = View::escape($street->getTown()->getDescription());
			echo "
			<tr>
				<td><a href=\"{$street->getURL()}\">$name</a></td>
				<td>$status</td>
                <td>$town</td>
			</tr>
			";
		}
	echo "
		</tbody>
	</table>
	";
}
else {
	echo "<h2>No Streets Found</h2>";
}

if (userIsAllowed('Street')) {
	echo "
	<p>Can't find what you're looking for?</p>
	<div>
		<button type=\"button\" onclick=\"document.location.href='".BASE_URL."/streets/addStreet.php';\">
			Add a Street
		</button>
	</div>
	";
}
?>
</div>