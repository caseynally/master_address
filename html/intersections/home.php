<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$template = isset($_GET['format']) ? new Template('default', $_GET['format']) : new Template();

if ($template->outputFormat === 'html') {
    $template->blocks[] = new Block('intersections/searchForm.inc');
}

if (!empty($_REQUEST['street'])) {
    $list = empty($_REQUEST['intersectingStreet'])
        ? IntersectionGateway::intersections($_REQUEST['street'])
        : IntersectionGateway::intersections($_REQUEST['street'], $_REQUEST['intersectingStreet']);

    $template->blocks[] = new Block('intersections/list.inc', ['intersections'=>$list]);
}

echo $template->render();