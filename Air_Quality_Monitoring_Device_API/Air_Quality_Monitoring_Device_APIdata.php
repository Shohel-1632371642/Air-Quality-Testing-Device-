<?php  
	header("Content-Type: application/json");

	$dbServer = 'localhost';
	$dbUser = 'root';
	$dbPassword = '';
	$db = 'aqm';

	$conn = mysqli_connect($dbServer,$dbUser,$dbPassword,$db);
	
	$sql = "SELECT time,value FROM (
				SELECT * FROM sensordata ORDER BY id DESC LIMIT 15
			) sub ORDER BY id ASC;";
	$result = mysqli_query($conn,$sql);
	$data = array();
	while (	$row = mysqli_fetch_assoc($result)){
		$data[] = $row;
	}
	
	print json_encode($data);

?>