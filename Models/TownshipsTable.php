<?php
/**
 * @copyright 2009-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Application\Models;

use Blossom\Classes\TableGateway;

class TownshipsTable extends TableGateway
{
    public function __construct() { parent::__construct('townships', __namespace__.'\Township'); }

    public function find($fields=null, $order=['name'], $itemsPerPage=null, $currentPage=null)
    {
        return parent::find($fields, $order, $itemsPerPage, $currentPage);
    }
}
