<?php
/**
 * @copyright 2015 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Place $this->place
 */
?>
<div class="interfaceBox placeInfo">
    <h2><?php echo View::escape($this->place->getPlace_name()); ?></h2>
    <?php
        $address = $this->place->getAddress();
        if ($address) {
            echo "<h3><a href=\"{$address->getUrl()}\">$address</a></h3>";
        }
    ?>
    <table>
    <?php
        foreach (Place::$fields as $f) {
            $get = 'get'.ucfirst($f);
            $$f = View::escape($this->place->$get());
            echo "<tr><th>$f</th><td>{$$f}</td></tr>";
        }
    ?>
    </table>
</div>