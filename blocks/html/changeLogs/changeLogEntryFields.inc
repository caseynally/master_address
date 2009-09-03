<?php
/**
 * @copyright 2009 City of Bloomington, Indiana
 * @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param string $this->action
 */
?>
<div><label for="changeLogEntry-action">Action</label>
	<?php echo View::escape(ucfirst($this->action)); ?>
	<input type="hidden" name="changeLogEntry[action]" id="changeLogEntry-action"
			value="<?php echo View::escape($this->action); ?>" />
</div>
<div><p>Before saving, you must specify your rationale for this change:</p>
	<textarea name="changeLogEntry[rationale]" rows="4" cols="50"></textarea>
</div>
<div><label for="changeLogEntry-contact_id">Contact</label>
	<select name="changeLogEntry[contact_id]" id="changeLogEntry-contact_id">
		<option></option>
		<?php
			$list = new ContactList();
			$list->find();
			foreach ($list as $contact) {
				$name = View::escape("{$contact->getFirstname()} {$contact->getLastname()}");
				echo "<option value=\"{$contact->getId()}\">$name</option>";
			}
		?>
	</select>
</div>