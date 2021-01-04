
<?php
if (!empty($_POST['temp'])) {
	
	//database info
	$dbServer = 'localhost';
	$dbUser = 'root';
	$dbPassword = '';
	$db = 'aqm';

	//connecting to the database
	$conn = mysqli_connect($dbServer,$dbUser,$dbPassword,$db);

	//sensor value
	$data = $_POST['temp'];
	$sql = "INSERT INTO sensordata (value,time,date) VALUES (".$data.",CURRENT_TIME,CURRENT_DATE);";
	$result = mysqli_query($conn,$sql);
	
	
	
}

/*
$dbServer = 'localhost';
$dbUser = 'root';
$dbPassword = '';
$db = 'aqm';

$conn = mysqli_connect($dbServer,$dbUser,$dbPassword,$db);



$previousDate = date("Y-m-d");
$dateUpdate = str_replace('-', '/', $previousDate);
$date = date('Y-m-d',strtotime($dateUpdate . "+1 days"));



$sql = "SELECT * FROM sensordata WHERE date = '".$previousDate."';";
$result = mysqli_query($conn,$sql);

while (	$row = mysqli_fetch_assoc($result)){
	echo $row['value'];
}

echo $date;
*/
?>