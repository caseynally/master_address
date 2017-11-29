<?php
/**
 * @copyright 2017 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 */
namespace Application\Townships;

class Controller
{
    public function index(array $params)
    {
        $table = new TownshipsTable();
        $list  = $table->find();

        return new \Application\Views\Generic\ListView([
            'list'     => $list,
            'plural'   => 'townships',
            'singular' => 'township',
            'fields'   => array_keys(Township::$fieldmap)
        ]);
    }

    public function update(array $params)
    {
        if (!empty($_REQUEST['id'])) {
            try { $township = new Township($_REQUEST['id']); }
            catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
        }
        else { $township = new Township(); }

        if (isset($township)) {
            if (isset($_POST['name'])) {
                try {
                    $township->handleUpdate($_POST);
                    $township->save();
                    header('Location: '.View::generateUrl('townships.index'));
                    exit();
                }
                catch (\Exception $e) { $_SESSION['errorMessages'][] = $e; }
            }
            return new \Application\Views\Generic\UpdateView([
                'form'     => 'townships/updateForm.inc',
                'township' => $township
            ]);
        }
        else {
            return new \Application\Views\NotFoundView();
        }
    }
}