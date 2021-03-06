<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Street $this->street
 */
$url = new URL(BASE_URL.'/streets/actions.php');
?>
<h1>Change Street Name</h1>
<script type="text/javascript">
function handleChangeStreet(form) {
	if (FRAMEWORK.checkRequiredFields()) {
		FRAMEWORK.getChangeLog(form,'change','<?php echo BASE_URL; ?>');
	}
}
</script>
<form method="post" action="<?php echo $url; ?>"
	onsubmit="handleChangeStreet(this); return false;">
	<fieldset><legend>Street Information</legend>
		<?php include APPLICATION_HOME.'/blocks/html/streets/partials/notesField.inc'; ?>
	</fieldset>
	<fieldset><legend>Renumber Addresses</legend>
		<p>Do you want to re-number the addresses on this street?</p>
		<?php
			$url->street_id = $this->street->getId();
			$url->action = 'change';
			if (isset($_REQUEST['renumber']) && $_REQUEST['renumber']=='yes') {
				$yesChecked = 'checked="checked"';
				$noChecked = '';
			}
			else {
				$yesChecked = '';
				$noChecked = 'checked="checked"';
			}
		?>
		<label><input type="radio" name="renumber" value="yes" <?php echo $yesChecked; ?>
				onclick="document.location.href='<?php echo $url; ?>;renumber=yes';" />
				Yes
		</label>
		<label><input type="radio" name="renumber" value="no" <?php echo $noChecked; ?>
				onclick="document.location.href='<?php echo $url; ?>';" />
				No
		</label>
	</fieldset>
	<fieldset><legend>New Street Name</legend>
  		<input name="street_id" type="hidden" value="<?php echo $this->street->getId(); ?>" />
		<input name="action" type="hidden" value="change" />
		<?php
			include APPLICATION_HOME.'/blocks/html/streets/partials/streetNameFields.inc';
		?>
		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel"
				onclick="document.location.href='<?php echo $this->street->getURL(); ?>';">
			Cancel
		</button>
	</fieldset>
	<?php
		if ($yesChecked) {
			include APPLICATION_HOME.'/blocks/html/streets/partials/renumberAddressesForm.inc';
		}
	?>
</form>
