#include "../LIB/BitMath.h"
#include "../LIB/std_types.h"
#include <math.h>
#include <stdio.h>
#include "../MCAL/UART.h"
#include <string.h>
#include <stdlib.h>

void GPS_read();
float toDegrees(float angle);
float toRadians(float angle);
float GPS_getDistance(double lat1, double long1, double lat2, double long2, bool isDegrees);
