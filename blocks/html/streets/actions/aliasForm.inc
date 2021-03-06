<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Street $this->street
 */
?>
<h1>Add Alias</h1>
<script type="text/javascript">
function handleAliasStreet(form) {
	if (FRAMEWORK.checkRequiredFields()) {
		FRAMEWORK.getChangeLog(form,'alias','<?php echo BASE_URL; ?>');
	}
}
</script>
<form method="post" action="<?php echo BASE_URL; ?>/streets/actions.php"
	onsubmit="handleAliasStreet(this); return false;">
	<fieldset><legend>Street Information</legend>
		<?php include APPLICATION_HOME.'/blocks/html/streets/partials/notesField.inc'; ?>
	</fieldset>
	<fieldset><legend>New Street Name</legend>
  		<input name="street_id" type="hidden" value="<?php echo $this->street->getStreet_id(); ?>" />
		<input name="action" type="hidden" value="alias" />
		<?php
			include APPLICATION_HOME.'/blocks/html/streets/partials/streetNameTypeSelector.inc';
			include APPLICATION_HOME.'/blocks/html/streets/partials/streetNameFields.inc';
		?>
		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel"
			onclick="document.location.href='<?php echo $this->street->getURL(); ?>';">
			Cancel
		</button>
	</fieldset>
</form>
