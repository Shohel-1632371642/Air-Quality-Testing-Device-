#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
SoftwareSerial s(D6,D5);
//wifi related variables
const char *ssid = "Lurking Legends";
const char *password = "balegend";
const char* host = "192.168.0.111";
const int port = 80;
//senor related variables
String postData,postVar;
int sensorData;

void setup() {
  s.begin(115200);
  Serial.begin(115200);
  
  postVar = "";
  sensorData = 0;
  postData = "";
  connectWifi();  
}

void loop() {
  s.write("s");
  if (s.available()>0)
  {
      sensorData=s.read();
      Serial.println(sensorData);
  
      
      WiFiClient client;
      Serial.println("Connecting to host");
      if(!client.connect(host, port)){
        Serial.println("...connection failed!");
        Serial.println("Retrying in 5 seconds...");
        delay(5000);
        return;  
      }
      Serial.println("...TCP message fired!");
      
      HTTPClient http;  
      postVar = "temp=";
      
      //Post Data
      postData = postVar + sensorData;
      Serial.println(postData);
    
      http.begin(client, "http://localhost/Air_Quality_Monitoring_Device_API/test.php");              //change the ip to your computer ip address
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
     
      int httpCode = http.POST(postData);
      http.POST(postData);//Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
     
      http.end();  //Close connection
      delay(2000);
  }
}

//function to connect to the wifi
void connectWifi(){
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  Serial.println("Connecting to AP");
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print("."); 
   }
  Serial.println(" connected");
  //If connection successful show IP address in serial monitor 
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}
