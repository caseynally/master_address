<?php
/**
 * @copyright 2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
declare (strict_types=1);
namespace Application\Subdivisions\Views;

use Blossom\Classes\Block;
use Blossom\Classes\Template;

class InfoView extends Template
{
    public function __construct(array $vars)
    {
        $format   = !empty($_REQUEST['format']) ? $_REQUEST['format'] : 'html';
        $template = $format == 'html' ? 'two-column' : 'default';
        parent::__construct($template, $format, $vars);

        $this->blocks[] = new Block('subdivisions/info.inc', ['subdivision'=>$this->subdivision]);
        #$this->blocks['panel-one'][] = new Block('address/list.inc', ['addresses'=>$this->subdivision->getAddresses()]);
    }
}