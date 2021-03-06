<?php
/**
 * @copyright 2009-2016 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @param Subunit $this->subunit (optional)
 */
$subunit = $this->subunit ? $this->subunit : new Subunit();
?>
	<tr><td><label for="sudtype">SUD Type</label></td>
		<td><select name="sudtype" id="sudtype"><option value=""></option>
			<?php
				$types = new SubunitTypeList();
				$types->find();
				foreach ($types as $type) {
					$selected = $type->getSudtype() == $subunit->getSudtype()
											? 'selected="selected"'
											: '';
					echo "<option $selected value=\"{$type->getSudtype()}\">{$type->getDescription()}</option>";
				}
			?>
			</select>
		</td>
	</tr>
	<tr><td><label  for="subunit_identifier">Unit</label></td>
		<td><input name="subunit_identifier" id="subunit_identifier"
					size="30" maxlength="30"
					value="<?php echo View::escape($subunit->getIdentifier()); ?>" />
		</td>
	</tr>
