<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
if (!userIsAllowed('Direction')) {
	$_SESSION['errorMessages'][] = new Exception('noAccessAllowed');
	header('Location: '.BASE_URL.'/streets');
	exit();
}

if (isset($_POST['direction'])) {
	$direction = new Direction();
	foreach ($_POST['direction'] as $field=>$value) {
		$set = 'set'.ucfirst($field);
		$direction->$set($value);
	}

	try {
		$direction->save();
		header('Location: '.BASE_URL.'/streets');
		exit();
	}
	catch(Exception $e) {
		$_SESSION['errorMessages'][] = $e;
	}
}

$template = new Template();
$template->blocks[] = new Block('streets/addDirectionForm.inc');
echo $template->render();