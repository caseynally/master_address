<?php
/*
	$_GET variables:	id
						return_url
*/
	verifyUser("Administrator");

	include(GLOBAL_INCLUDES."/xhtmlHeader.inc");
	include(APPLICATION_HOME."/includes/banner.inc");
	include(APPLICATION_HOME."/includes/menubar.inc");
	include(APPLICATION_HOME."/includes/sidebar.inc");

	$street = new Street($_GET['id']);
?>
<div id="mainContent">
	<?php include(GLOBAL_INCLUDES."/errorMessages.inc"); ?>

	<h2>Edit Street: <?php echo $street->getId(); ?></h2>
	<form method="post" action="updateStreet.php">
	<fieldset><legend>Street Info</legend>
		<input name="street[id]" type="hidden" value="<?php echo $street->getId(); ?>" />
		<input name="return_url" type="hidden" value="<?php echo $_GET['return_url']; ?>" />
		<table>
		<tr><td><label for="street-status_id">Status</label></td>
			<td><select name="street[status_id]" id="street-status">
				<?php
					$list = new StatusList();
					$list->find();
					foreach($list as $status)
					{
						if ($street->getStatus_id() != $status->getId()) { echo "<option value=\"{$status->getId()}\">{$status->getStatus()}</option>"; }
						else { echo "<option value=\"{$status->getId()}\" selected=\"selected\">{$status->getStatus()}</option>"; }
					}
				?>
				</select>
			</td>
		</tr>
		<tr><td colspan="2">
				<div><label for="street-notes">Notes</label></div>
				<textarea name="street[notes]" id="street-notes" rows="3" cols="60"><?php echo $street->getNotes(); ?></textarea>
		</td></tr>
		</table>
		<button type="submit" class="submit">Submit</button>
		<button type="button" class="cancel" onclick="document.location.href='<?php echo $_GET['return_url']; ?>';">Cancel</button>
	</fieldset>

	</form>
</div>
<?php
	include(APPLICATION_HOME."/includes/footer.inc");
	include(GLOBAL_INCLUDES."/xhtmlFooter.inc");
?>