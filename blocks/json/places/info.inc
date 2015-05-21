<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Place $this->place
 */
$place = [];
foreach (PlaceGateway::$fields as $f) {
    $get = 'get'.ucfirst($f);
    $place[$f] = $this->place->$get();
}
echo json_encode($place, JSON_PRETTY_PRINT);
