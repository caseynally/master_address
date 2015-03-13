<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
try {
    if (empty($_GET['place_id'])) { throw new \Exception('places/unknownPlace'); }
    $place = new Place($_GET['place_id']);
}
catch (\Exception $e) {
    $_SESSION['errorMessages'][] = $e;
    header('Location: '.BASE_URL.'/places');
}

$template = new Template();
$template->blocks[] = new Block('places/info.inc', ['place'=>$place]);
echo $template->render();