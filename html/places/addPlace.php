<?php
/*
	$_POST variables:	place [	jurisdiction_id			mailable		censusBlockFIPSCode
								status_id				livable			statePlaneX
								name					section			statePlaneY
								township_id				quarterSection	latitude
								trashPickupDay_id		class			longitude
								recyclingPickupWeek_id	placeType_id
								startDate
								endDate
							]
*/
	verifyUser("Administrator");

	$place = new Place();
	foreach($_POST['place'] as $field=>$value)
	{
		$set = "set".ucfirst($field);
		$place->set($value);
	}
	try
	{
		$place->save();
		Header("Location: home.php");
	}
	catch (Exception $e)
	{
		$_SESSION['errorMessages'][] = $e;
		Header("Location: addPlaceForm.php");
	}
?>