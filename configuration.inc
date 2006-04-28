<?php
/*
	Global settings
*/
	define("GLOBAL_INCLUDES","/var/www/libraries/php");	# Where on the filesystem this package of libraries is installed.
														# These are shared among other applications we write, so they
														# are a seperate package we will release.

	define("APPLICATION_HOME","/var/www/sites/master_address");	# Where on the filesystem this is installed
	define("BASE_URL","/master_address");							# The base URL to get to this site on this webserver

	#--------------------------------------------------------------------------
	# Database Setup
	#--------------------------------------------------------------------------
	$PDO = new PDO("mysql:unix_socket=/tmp/mysql.sock;dbname=master_address","username","password",array(PDO::ATTR_ERRMODE=>PDO::ERRMODE_EXCEPTION));

	#--------------------------------------------------------------------------
	# LDAP Configuration
	# This is required in order to use the LDAP authentication
	# If you do not want to use LDAP authentication, you can comment this out
	#--------------------------------------------------------------------------
	define("LDAP_DOMAIN","city.bloomington.in.us");
	define("LDAP_DN","ou=people,o=".LDAP_DOMAIN);
	define("LDAP_USERNAME_ATTRIBUTE","uid");
	define("LDAP_ADMIN_USER","username");
	define("LDAP_ADMIN_PASS","password");
	define("LDAP_SERVER","ldap.bloomington.in.gov");
	define("LDAP_PASSWORD_ATTRIBUTE","userpassword");


	#--------------------------------------------------------------------------
	# Session Startup
	# Make sure to load all class definitions for anything that's going to
	# be stored in the session before we start the session
	#--------------------------------------------------------------------------
	require_once(APPLICATION_HOME."/classes/User.inc");
	session_start();


	# Import global functions that we use for many applications we write
	include(GLOBAL_INCLUDES."/ITSFunctions.inc");
?>