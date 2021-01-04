
$(document).ready(function init(){
	setTimeout(init,3000)
	$.ajax({

		url: "http://localhost/Air_Quality_Monitoring_Device_API/data.php",
		method: "GET",
		success: function(data){	
			var time = [];
			var value = [];
			time.push(0);
			value.push(0);

			for(var i in data){
				time.push(data[i].time);
				value.push(data[i].value);
			}

			var chartdata = {
				labels: time,
				datasets: [
					{
						label: 'Air Quality Measurements',
						backgroundColor: 'blue',
						borderColor: '#0098e6',
						hoverBackgroundColor: 'green',
						hoverBorderColor: 'blue',
						fill: false,
						pointRadius: 4,
						data: value
						
					}
				]
			};

			var ctx = $("#chartcanvas");

			var graph = new Chart(ctx,{
				type: 'line',
				data: chartdata,
				options: {
				  animation: false,
				  responsive : true,
				  scales: {
				  	xAxes: [{
				      scaleLabel: {
				        display: true,
				        labelString: 'Time',
				        fontStyle: 'bold',
				        fontSize: 15,
				        type: 'time',
				        time:{
				        	unit: 'minute'
				        }

				      }
				    }],

				    yAxes: [{
				      scaleLabel: {
				        display: true,
				        labelString: 'values (ppm)',
				        fontStyle: 'bold',
				        fontSize: 15
				      }
				    }]
				  }     
				}

			});

		},
		error: function(data){
			console.log(data);
		}

	});


	
});



/*
var time = [];
var value = [];
var chartdata;

var ctx = document.getElementById("chartcanvas");

var graph;
var counter = 0;

$(document).ready(function init(){
	
	$.ajax({
		url: "http://localhost/Air_Quality_Monitoring_Device_API/data.php",
		method: "GET",
		success: function(data){	
			time.push(0);
			value.push(0);
			for(var i in data){
				time.push(data[i].time);
				value.push(data[i].value);
				counter = i;
			}

			chartdata = {
				labels: time,
				datasets: [
				{
					label: 'Air Quality Measurements',
					backgroundColor: 'blue',
					borderColor: '#0098e6',
					hoverBackgroundColor: 'green',
					hoverBorderColor: 'blue',
					fill: false,
					pointRadius: 4,
					data: value

				}
				]
			};
			graph = new Chart(ctx,{
				type: 'line',
				data: chartdata,
				options: {					
					scales: {
						xAxes: [{
							scaleLabel: {
								display: true,
								labelString: 'Time',
								fontStyle: 'bold',
								fontSize: 15,
								type: 'time',
								time:{
									unit: 'minute'
								}

							}
						}],

						yAxes: [{
							scaleLabel: {
								display: true,
								labelString: 'values (ppm)',
								fontStyle: 'bold',
								fontSize: 15
							}
						}]
					}     
				}

			});
		}
	});
});

var getData = function() {
  	$.ajax({
    	url: "http://localhost/Air_Quality_Monitoring_Device_API/data.php",
    	type:"GET",
    	success: function(data) {
    	console.log(data);
  
    	graph.data.labels.push(data[counter].time);
      	graph.data.datasets[0].data.push(data[counter].value);
		graph.update();
      	counter++;
    	}
  	});
};

// get new data every 3 seconds
setInterval(getData, 500);
*/