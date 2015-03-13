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