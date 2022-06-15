#include "OneWire.h"
#include "DallasTemperature.h"
#include "dotDevice.h"

OneWire onewire(26);
DallasTemperature sensor(&onewire);

float temp_in_c;

//const char* ssid = "NOWTVTVLYK";
const char* ssid = "NETGEAR35";
//const char* password = "hmmUwXL81gXC";
const char* password = "magicalfinch482";
//const char *server = "ws://ec2-52-15-138-171.us-east-2.compute.amazonaws.com:1234";
const char *server = "192.168.1.2:1234";
const char* gid = "pbEGMqBP";

dotDevice server_con(ssid, password, server);

#pragma pack(1)
    struct data_packet_struct
    {
        char gid[8] = { 'p', '' } ;
        short int command[2];
        short int avg[2];
        short int t0[2];
        short int v0[2];
        short int t1[2];
        short int v1[2];
        short int t2[2];
        short int v2[2];
        short int t3[2];
        short int v3[2];
        short int t4[2];
        short int v4[2];
        short int t5[2];
        short int v5[2];
        short int t6[2];
        short int v6[2];
        short int t7[2];
        short int v7[2];
        short int t8[2];
        short int v8[2];
        short int t9[2];
        short int v9[2];
        short int t10[2];
        short int v10[2];
        short int t11[2];
        short int v11[2];
        short int t12[2];
        short int v12[2];
        short int t13[2];
        short int v13[2];
        short int t14[2];
        short int v14[2];
        short int t15[2];
        short int v15[2];
        
    }data_packet;
#pragma pop(1)

void setup() {
  
    Serial.begin(115200);
    sensor.begin();
    server_con.connect();

    //data_packet.p1 = gid;
    data_packet.command = 1;
    
}


void loop() {
  sensor.requestTemperatures();
  temp_in_c = sensor.getTempCByIndex(0);
  Serial.println(temp_in_c);
  //Serial.print("sizeof(data_packet) = %lu\n", sizeof(data_packet));
  
  Serial.println(p1.gid);

}
