<?php
/**
 * @copyright 2009-2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
declare (strict_types=1);
namespace Application\Models\TableGateways;

use Blossom\Classes\TableGateway;

class StreetTypesTable extends TableGateway
{
    public function __construct() { parent::__construct('street_types', 'Application\Models\Streets\Type'); }

    public function find(array $fields=null, array $order=['name'], int $itemsPerPage=null, int $currentPage=null)
    {
        return parent::find($fields, $order, $itemsPerPage, $currentPage);
    }
}
