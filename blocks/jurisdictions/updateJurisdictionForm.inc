<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
<fieldset><legend>Jurisdiction</legend>
	<input name="id" type="hidden" value="<?php echo $this->jurisdiction->getId(); ?>" />

	<table>
	<tr><td><label for="jurisdiction-name">Name</label></td>
		<td><input name="jurisdiction[name]" id="jurisdiction-name" value="<?php echo $this->jurisdiction->getName(); ?>" /></td></tr>
	</table>

	<button type="submit" class="submit">Submit</button>
	<button type="button" class="cancel" onclick="document.location.href='<?php echo BASE_URL; ?>/jurisdictions';">Cancel</button>
</fieldset>
</form>