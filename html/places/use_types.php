<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$template = (isset($_GET['format']) && $_GET['format']=='json')
    ? new Template('default', $_GET['format'])
    : new Template('two-column');
$template->blocks[] = new Block('places/use_types.inc');
echo $template->render();