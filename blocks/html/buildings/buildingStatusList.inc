<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
?>
<div class="interfaceBox">
	<h1>
		<?php
			if (userHasRole('Administrator')) {
				echo "<a class=\"add button\" href=\"".BASE_URL."/buildings/addBuildingStatus.php\">Add</a>";
			}
		?>
		Building Statuses
	</h1>
	<ul><?php
			foreach ($this->buildingStatusList as $buildingStatus) {
				$editButton = '';
				if (userHasRole('Administrator')) {
					$url = new URL(BASE_URL.'/buildings/updateBuildingStatus.php');
					$url->status_code = $buildingStatus->getStatus_code();
					$editButton = "<a class=\"edit button\" href=\"$url\">Edit</a>";
				}
				echo "<li>$editButton $buildingStatus</li>";
			}
		?>
	</ul>
</div>