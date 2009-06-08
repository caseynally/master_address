<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */

verifyUser('Administrator');

$addrLocationType = new AddrLocationType($_REQUEST['location_type_id']);
if (isset($_POST['addrLocationType'])) {
	foreach ($_POST['addrLocationType'] as $field=>$value) {
		$set = 'set'.ucfirst($field);
		$addrLocationType->$set($value);
	}

	try {
		$addrLocationType->save();
		header('Location: '.BASE_URL.'/addresses');
		exit();
	}
	catch (Exception $e) {
		$_SESSION['errorMessages'][] = $e;
	}
}

$template = new Template();
$template->blocks[] = new Block('addresses/updateAddrLocationTypeForm.inc',array('addrLocationType'=>$addrLocationType));
echo $template->render();