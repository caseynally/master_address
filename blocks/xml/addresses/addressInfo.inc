<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Address $this->address
 */
echo "
<address>
	<id>{$this->address->getId()}</id>
	<streetAddress>{$this->address->getStreetAddress()}</streetAddress>
	<city>{$this->address->getCity()}</city>
	<state>{$this->address->getState()}</state>
	<zip>{$this->address->getZip()}</zip>
	<latitude>{$this->address->getLatitude()}</latitude>
	<longitude>{$this->address->getLongitude()}</longitude>
	<statePlane>
		<x>{$this->address->getState_plane_x_coordinate()}</x>
		<y>{$this->address->getState_plane_y_coordinate()}</y>
	</statePlane>
	<jurisdiction>{$this->address->getJurisdiction()->getDescription()}</jurisdiction>
	<township>{$this->address->getTownship()->getName()}</township>
	<trashDay>{$this->address->getTrashDay()}</trashDay>
	<recycleWeek>{$this->address->getRecycleWeek()}</recycleWeek>
	<censusBlock>{$this->address->getCensus_block_fips_code()}</censusBlock>
";
	$purposes = $this->address->getLocation()->getPurposes();
	if (count($purposes)) {
		echo "<purposes>";
		foreach ($purposes as $purpose) {
			echo "
			<purpose type=\"{$purpose->getType()}\">{$purpose->getDescription()}</purpose>
			";
		}
		echo "</purposes>";
	}
echo "</address>";