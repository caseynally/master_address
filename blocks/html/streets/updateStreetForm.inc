<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */

$directions = new DirectionList();
$directions->find();
$statuses = new StreetStatusList();
$statuses->find();
$towns = new TownList();
$towns->find();

?>
<h1>Update Street</h1>
<form method="post" action="<?php echo $_SERVER['SCRIPT_NAME']; ?>">
	<fieldset><legend>Street Info</legend>
		<input name="street_id" type="hidden" value="<?php echo $this->street->getStreet_id(); ?>" />
		<table>

			<tr><td><label for="street-street_direction_code">Direction</label></td>
				<td><select name="street[street_direction_code]" id="street-street_direction_code">
                <option></option>
                     <?php
                     foreach($directions as $direction){
	                     $selected = ($direction->getId() == $this->street->getStreet_direction_code())?"selected=\"selected\"":"";
	                     echo "<option $selected value=\"{$direction->getId()}\">{$direction->getDescription()}</option>"; 
                      }
                  ?>
                 </select>
				</td>
			</tr>
				
			<tr><td><label for="street-post_direction_suffix_code">Post Direction</label></td>
				<td><select name="street[post_direction_suffix_code]" id="street-post_direction_suffix_code">
                  <option></option>
                     <?php
                     foreach($directions as $direction){
	                     $selected = ($direction->getId() == $this->street->getPost_direction_suffix_code())?"selected=\"selected\"":"";
	                     echo "<option $selected value=\"{$direction->getId()}\">{$direction->getDescription()}</option>"; 
                      }
                  ?>
                 </select>
				</td>
			</tr>
				
			<tr><td><label for="street-town_id">Town</label></td>
				<td><select name="street[town_id]" id="street-town_id">
                     <option></option>
                   <?php
                       foreach($towns as $town){
	                        $selected=($this->street->getTown_id() == $town->getId())?"selected=\"selected\"":"";
	                        echo "<option $selected value=\"{$town->getId()}\">{$town->getDescription()}</option>"; 
                       }
                    ?>
                </select>
				</td>
			</tr>
				
			<tr><td><label for="street-status_code">Status</label></td>
				<td><select name="street[status_code]" id="street-status_code">
                     <option></option>
                     <?php
                       foreach($statuses as $status){
		                   $selected=($this->street->getStatus_code() == $status->getId())?"selected=\"selected\"":"";
	                        echo "<option $selected value=\"{$status->getId()}\">{$status->getDescription()}</option>"; 

                       }
                    ?>
                </select>
				</td>
			</tr>
				
			<tr><td><label for="street-notes">Notes</label></td>
				<td><input name="street[notes]" id="street-notes" value="<?php echo View::escape($this->street->getNotes()); ?>" />
				</td>
			</tr>
				
		</table>

		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel" onclick="document.location.href='<?php echo BASE_URL; ?>/streets';">
			Cancel
		</button>
	</fieldset>
</form>