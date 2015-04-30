<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param PlaceList $this->places
 */
$places = [];
foreach ($this->places as $place) {
    $p = [];
    foreach (Place::$fields as $f) {
        $get = 'get'.ucfirst($f);
        $p[$f] = $place->$get();
    }
    $places[] = $p;
}
echo json_encode($places, JSON_PRETTY_PRINT);
