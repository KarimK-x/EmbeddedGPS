#include "BitMath.h"
#include "std_types.h"
#include "math.h"
#include "stdio.h"
#include "UART.h"
#include <string.h>
#include "stdio.h"
#include <stdlib.h>

void GPS_read();
float toDegrees(float angle);
float toRadians(float angle);
float GPS_getDistance(float lat1, float long1, float lat2, float long2, bool isDegrees);
