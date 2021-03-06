<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$townList = new TownList();
$townList->find();

$template = new Template();
$template->blocks[] = new Block('towns/townList.inc',array('townList'=>$townList));
echo $template->render();
