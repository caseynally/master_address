<?php
/*
	$_POST variables:	townshipID
						name
						abbreviation
						quarterCode
*/
	verifyUser("Administrator");

	require_once(APPLICATION_HOME."/classes/Township.inc");
	$township = new Township($_POST['townshipID']);
	$township->setName($_POST['name']);
	$township->setAbbreviation($_POST['abbreviation']);
	$township->setQuarterCode($_POST['quarterCode']);

	try
	{
		$township->save();
		Header("Location: home.php");
	}
	catch (Exception $e)
	{
		$_SESSION['errorMessages'][] = $e;
		Header("Location: updateTownshipForm.php?townshipID=$_POST[townshipID]");
	}
?>