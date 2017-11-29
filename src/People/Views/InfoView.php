<?php
/**
 * @copyright 2016-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Application\People\Views;

use Blossom\Classes\Block;
use Blossom\Classes\Template;

class InfoView extends Template
{
    public function __construct(array $vars)
    {
        $format = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        parent::__construct('default', $format, $vars);

		$this->blocks[] = new Block('people/info.inc', ['person'=>$this->person]);
    }
}