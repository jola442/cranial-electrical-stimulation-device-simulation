#include <iostream>
#include <string>

#DEFINE BATTERY_DRAIN_RATE 0.4

#DEFINE MAX_THERAPY_COUNT 4

using namespace std;

typedef enum {C_20_MIN, C_45_MIN, C_USER_MIN} groupType;

typedef enum {DELTA, THETA, ALPHA, BETA1} sessionNumType;
