#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "Lurking Legends";  //ENTER YOUR WIFI ssid
const char *password = "balegend";  //ENTER YOUR WIFI password

const char* host = "192.168.0.111";
const int port = 80;
String postData,postVar;
int sensorData;


void setup() {
    Serial.begin(74880);  
    connectWifi();
    postVar = "";
    sensorData = 0;
    postData = "";  

}


void loop() {
SendSensorData();
}
//function to connect to wifi
void connectWifi(){
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to AP");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("."); 
   }
  Serial.println(" connected");
  //If connection successful show IP address in serial monitor 
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}


//function to send sensor data 
void SendSensorData() {

  WiFiClient client;
  Serial.println("Connecting to host");
  if(!client.connect(host, port)){
    Serial.println("...connection failed!");
    Serial.println("Retrying in 5 seconds...");
    delay(5000);
    return;  
  }
  Serial.println("...TCP message fired!");
  
  HTTPClient http;    //Declare object of class HTTPClient
  sensorData = 123;
  postVar = "temp=";
  
  //Post Data
  postData = postVar +  sensorData;
  Serial.println(postData);
  delay(1000);
  http.begin(client, "http://localhost/Air_Quality_Monitoring_Device_API/test.php");              //change the ip to your computer ip address
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  int httpCode = http.POST(postData);
  http.POST(postData);//Send the request
  String payload = http.getString();    //Get the response payload
  delay(1000);
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
 
  http.end();  //Close connection
  
  delay(5000);  //Post Data at every 5 seconds
}
