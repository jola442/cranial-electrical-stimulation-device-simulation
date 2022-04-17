#include "session.h"
#include <iostream>

using namespace std;

//session constructor
Session::Session()
{
    intensity = 1;
    type = NON;
    duration = 0;
}

//increases the intensity of the session
int Session::increaseIntensity()
{
    if(intensity<8)
    {
        intensity = intensity +1;
        //cout<<intensity<<endl;
    }
    return intensity;
}

//decreases the intensity of the session
int Session::decreaseIntensity()
{
    if(intensity>0)
    {
        intensity = intensity - 1;
        //cout<<intensity<<endl;
    }

    return intensity;
}


//sets the type of session
void Session::setType(sessionNumType newType){
    type = newType;
}

sessionNumType Session::getType(){
    return type;
}

float Session::getDuration(){
    return duration;
}

void Session::setDuration(float dur){
    duration = dur;
}

void Session::setIntensity(int inten){
    intensity = inten;
}

int Session::getIntensity(){
    return intensity;
}
