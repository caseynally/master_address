<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Annexation $this->annexation
 */
?>
<h1>Update Annexation</h1>
<form method="post" action="<?php echo $_SERVER['SCRIPT_NAME']; ?>">
	<fieldset><legend>Annexation Info</legend>
		<input name="annexation_id" type="hidden" value="<?php echo $this->annexation->getId(); ?>" />
		<table>

			<tr><td><label for="annexation-ordinance_number" class="required">Ordinance</label></td>
				<td><input name="annexation[ordinance_number]" id="annexation-ordinance_number" value="<?php echo View::escape($this->annexation->getOrdinance_number()); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-township_id">Township</label></td>
				<td><select name="annexation[township_id]" id="annexation-township_id">
						<option></option>
						<?php
							$list = new TownshipList();
							$list->find();
							foreach ($list as $township) {
								$name = View::escape($township->getName());
								$selected = $this->annexation->getTownship_id()==$township->getId()
											? 'selected="selected"'
											: '';
								echo "<option value=\"{$township->getId()}\" $selected>$name</option>";
							}
						?>
					</select>
				</td>
			</tr>

			<tr><td><label for="annexation-name">Name</label></td>
				<td><input name="annexation[name]" id="annexation-name" value="<?php echo View::escape($this->annexation->getName()); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-passed_date">Passed Date</label></td>
				<td><input name="annexation[passed_date]"
							id="annexation-passed_date"
							size="10" maxlength="10"
							value="<?php echo $this->annexation->getPassed_date('n/j/Y'); ?>" />
					(m/d/Y)
				</td>
			</tr>
			<tr><td><label for="annexation-effective_start_date">Effective Start Date</label></td>
				<td><input name="annexation[effective_start_date]"
							id="annexation-effective_start_date"
							size="10" maxlength="10"
							value="<?php echo $this->annexation->getEffective_start_date('n/j/Y'); ?>" />
					(m/d/Y)
				</td>
			</tr>

			<tr><td><label for="annexation-annexation_type">Type</label></td>
				<td><input name="annexation[annexation_type]" id="annexation-annexation_type" value="<?php echo View::escape($this->annexation->getAnnexation_type()); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-acres">Acres</label></td>
				<td><input name="annexation[acres]" id="annexation-acres" value="<?php echo View::escape($this->annexation->getAcres()); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-square_miles">Square Miles</label></td>
				<td><input name="annexation[square_miles]" id="annexation-square_miles" value="<?php echo View::escape($this->annexation->getSquare_miles()); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-estimate_population">Population</label></td>
				<td><input name="annexation[estimate_population]" id="annexation-estimate_population" value="<?php echo $this->annexation->getEstimate_population(); ?>" />
				</td>
			</tr>

			<tr><td><label for="annexation-dwelling_units">Dwelling Units</label></td>
				<td><input name="annexation[dwelling_units]" id="annexation-dwelling_units" value="<?php echo $this->annexation->getDwelling_units(); ?>" />
				</td>
			</tr>

		</table>

		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel" onclick="document.location.href='<?php echo BASE_URL; ?>/annexations';">
			Cancel
		</button>
	</fieldset>
</form>