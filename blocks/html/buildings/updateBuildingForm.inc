<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Building $this->building
 */
?>
<h1>Update Building</h1>
<form method="post" action="<?php echo $_SERVER['SCRIPT_NAME']; ?>">
	<fieldset><legend>Building Info</legend>
		<input name="building_id" type="hidden" value="<?php echo $this->building->getBuilding_id(); ?>" />
		<table>

			<tr><td><label for="building-building_type_id" class="required">Type</label></td>
				<td><select name="building[building_type_id]" id="building-building_type_id">
					<?php
						$list = new BuildingTypeList();
						$list->find();
						foreach ($list as $type) {
							$name = View::escape($type->getDescription());
							$selected = ($this->building->getBuilding_type_id()==$type->getId())
										? 'selected="selected"'
										: '';
							echo "<option value=\"{$type->getId()}\" $selected>$name</option>";
						}
					?>
					</select>
				</td>
			</tr>

			<tr><td><label for="building-gis_tag">Gis Tag</label></td>
				<td><input name="building[gis_tag]" id="building-gis_tag" value="<?php echo View::escape($this->building->getGis_tag()); ?>" />
				</td>
			</tr>

			<tr><td><label for="building-building_name">Name</label></td>
				<td><input name="building[building_name]" id="building-building_name" value="<?php echo View::escape($this->building->getBuilding_name()); ?>" />
				</td>
			</tr>

			<tr><td><label for="building-effective_start_date">Start Date</label></td>
				<td><input name="building[effective_start_date]"
							id="building-effective_start_date"
							size="10" maxlength="10"
							value="<?php echo $this->building->getEffective_start_date('n/j/Y'); ?>" />
					(m/d/Y)
				</td>
			</tr>
			<tr><td><label for="building-effective_end_date">End Date</label></td>
				<td><input name="building[effective_end_date]"
							id="building-effective_end_date"
							size="10" maxlength="10"
							value="<?php echo $this->building->getEffective_end_date('n/j/Y'); ?>" />
				</td>
			</tr>
			<tr><td><label for="building-status_code">Status</label></td>
				<td><select name="building[status_code]" id="building-status_code">
					<?php
						$list = new BuildingStatusList();
						$list->find();
						foreach ($list as $status) {
							$name = View::escape($status->getDescription());
							$selected = ($this->building->getStatus_code()==$status->getId())
										? 'selected="selected"'
										: '';
							echo "<option value=\"{$status->getId()}\" $selected>$name</option>";
						}
					?>
					</select>
				</td>
			</tr>

		</table>

		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel" onclick="document.location.href='<?php echo BASE_URL; ?>/buildings';">
			Cancel
		</button>
	</fieldset>
</form>