#include "session.h"
#include <iostream>

using namespace std;
Session::Session()
{
    intensity = 0;
    type = NON;
}

int Session::increaseIntensity()
{
    if(intensity<8)
    {
        intensity = intensity +1;
        //cout<<intensity<<endl;
    }
    return intensity;
}


int Session::decreaseIntensity()
{
    if(intensity>0)
    {
        intensity = intensity - 1;
        //cout<<intensity<<endl;
    }

    return intensity;
}


int Session::nextSession()
{
    if(type == META)
    {
        type = SUBDELTA;
    }

    else if(type == SUBDELTA)
    {
        type = DELTA;
    }

    else if(type == DELTA)
    {
        type = THETA;
    }
    else
    {
        type = META;
    }
    //cout<<type<<endl;
    return type;
}

int Session::previousSession()
{
    if(type == META)
    {
        type = THETA;
    }

    else if(type == THETA)
    {
        type = DELTA;
    }

    else if(type == DELTA)
    {
        type = SUBDELTA;
    }
    else
    {
        type = META;
    }

    //cout<<type<<endl;
    return type;
}

void Session::setType(sessionNumType newType){
    type = newType;
}
