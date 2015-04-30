<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
?>
<div class="interfaceBox">
    <h1>Use Types</h1>
    <ul>
    <?php
        foreach (Place::getUse_types() as $type) {
            echo "<li>$type</li>";
        }
    ?>
    </ul>
</div>