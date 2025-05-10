#include "GPS.h"

#define PI 3.14159265358979323846f
#define EARTH_RADIUS 6371000 // Radius of Earth in metres
char *sep_GPS[12];
char GPS[80] = "$GPRMC";  
char GPS_logName[6] = "$GPRMC"; // GPS log name
char GPS_test[150] = "$GPRMC,203522.00567,A,5109.0262308,N,11401.8407342,E,0.004,133.4,130522,0.0,E,D*2B";
double lat;
double lon;
double speed;


void GPS_read(){
   // char receivedChar;
    char flag = 1;
 
    do{
        flag = 1;
        for(int i=0; i<6; i++){
            if(UART_Read(UART2) != GPS_logName[i]){  //change uart function to ours.
                flag = 0;
                break;
            }
        }
        
    }while(flag ==0);
 
    int i = 6;
    char x;
    while ((x = UART_Read(UART2)) !='\n')
    {
        GPS[i] = x;
        ++i;
    }
//    printf("%s\n", GPS);
 
 
    char * token = strtok(GPS_test, ",");
 
    sep_GPS[0] = token;
    int j=1;
    while(token!=NULL){
        token = strtok(NULL, ",");
        sep_GPS[j] = token;
        ++j;
    }
    
    lat = atof(sep_GPS[3]);
    lon = atof(sep_GPS[5]);
 
    if(sep_GPS[4][0] == 'S'){
        lat = -lat;
    }
    if(sep_GPS[6][0]=='W'){
        lon = -lon;
    }
    //double speed = atof(sep_GPS[7]);
		return;
}

float toDegrees(float angle) {
    int degrees = (int)angle/100;
    float minutes = angle - (float)degrees * 100;
    return degrees + (minutes / 60);
}

float toRadians(float angle) {
    return angle * (PI / 180.0);
}

float GPS_getDistance(float lat1, float long1, float lat2, float long2, bool isDegrees) {
    //Convert latitude and longitude from degrees to radians
    if(isDegrees) {
        lat1 = toRadians(lat1);
        lat2 = toRadians(lat2);
        long1 = toRadians(long1);
        long2 = toRadians(long2);
    }
    else {
        lat1 = toRadians(toDegrees(lat1));
        lat2 = toRadians(toDegrees(lat2));
        long1 = toRadians(toDegrees(long1));
        long2 = toRadians(toDegrees(long2));
    }
    // Haversine formula
    float dlong = long2 - long1;
    float dlat = lat2 - lat1;

    float a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) 
        * pow(sin(dlong / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // Distance in metres
}

