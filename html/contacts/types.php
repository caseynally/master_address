<?php
/**
 * @copyright 2009-2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 */
if (!userIsAllowed('Contact')) {
	$_SESSION['errorMessages'][] = new Exception('noAccessAllowed');
	header('Location: '.BASE_URL);
	exit();
}

$template = isset($_GET['format'])
    ? new Template('default', $_GET['format'])
    : new Template();
$template->blocks[] = new Block('contacts/types.inc', ['types' => Contact::getTypes()]);
echo $template->render();
