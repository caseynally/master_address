<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$places = new PlaceList();
$places->find($_GET);

$template = new Template();
$template->blocks[] = new Block('places/list.inc', ['places'=>$places]);
echo $template->render();