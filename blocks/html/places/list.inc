<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param PlaceList $this->places
 */
?>
<div class="interfaceBox placeList">
    <h1>Places</h1>
    <form method="get" action="<?php echo BASE_URL; ?>/places">
        <fieldset>
            <table>
                <tr><td><label for="use_type">Use Type</label></td>
                    <td><select name="use_type" id="use_type"><option value=""></option>
                        <?php
                            foreach (Place::getUse_types() as $type) {
                                $selected = (!empty($_GET['use_type']) && $type == $_GET['use_type'])
                                    ? 'selected="selected"'
                                    : '';
                                $t = View::escape($type);
                                echo "<option value=\"$t\" $selected>$t</option>";
                            }

                        ?>
                    </td>
                </tr>
                <tr><td><label for="status">Status</label></td>
                    <td><select name="status" id="status"><option value=""></option>
                        <?php
                            foreach (Place::getStatuses() as $status) {
                                $selected = (!empty($_GET['status']) && $status == $_GET['status'])
                                    ? 'selected="selected"'
                                    : '';
                                $s = View::escape($status);
                                echo "<option value=\"$s\" $selected>$s</option>";
                            }
                        ?>
                    </td>
                </tr>
            </table>
            <button type="submit">Filter</button>
        </fieldset>
    </form>
    <?php
        if (count($this->places)) {
            echo "
            <table>
                <thead>
                    <tr><th>ID</th>
                        <th>Name</th>
                        <th>Status</th>
                        <th>Use Type</th>
                        <th>Vicinity</th>
                    </tr>
                </thead>
                <tbody>
            ";
            foreach ($this->places as $place) {
                $name     = View::escape($place->getShort_name());
                $status   = View::escape($place->getStatus());
                $use      = View::escape($place->getUse_type());
                $vicinity = View::escape($place->getVicinity());

                $url = $place->getUrl();
                echo "
                <tr><th>{$place->getId()}</th>
                    <td><a href=\"$url\">$name</a></td>
                    <td>$status</td>
                    <td>$use</td>
                    <td>$vicinity</td>
                </tr>
                ";
            }
            echo "
                </tbody>
            </table>
            ";
        }
    ?>
</div>