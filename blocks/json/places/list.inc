<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param PlaceList $this->places
 */
$places = [];
$block = new Block('places/info.inc');

foreach ($this->places as $place) {
    $block->place = $place;
    $places[] = $block->render('json');
}
echo '['.implode(',', $places).']';
