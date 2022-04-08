#include "session.h"
#include <iostream>

using namespace std;
Session::Session()
{
    intensity = 0;
}

int Session::increaseIntensity()
{
    if(intensity<8)
    {
        intensity = intensity +1;
        cout<<intensity<<endl;
    }
    return intensity;
}


int Session::decreaseIntensity()
{
    if(intensity>0)
    {
        intensity = intensity - 1;
        cout<<intensity<<endl;
    }

    return intensity;
}

void Session::recordSession() {
    return;
}