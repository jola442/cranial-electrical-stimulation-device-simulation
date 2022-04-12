#include "session.h"
#include <iostream>

using namespace std;
Session::Session()
{
    intensity = 1;
    type = NON;
    duration = 0;
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


//int Session::nextSession()
//{
//    if(type == MET)
//    {
//        type = SUBDELTA;
//    }

//    else if(type == SUBDELTA)
//    {
//        type = DELTA;
//    }

//    else if(type == DELTA)
//    {
//        type = THETA;
//    }
//    else
//    {
//        type = MET;
//    }
//    //cout<<type<<endl;
//    return type;
//}

//int Session::previousSession()
//{
//    if(type == MET)
//    {
//        type = THETA;
//    }

//    else if(type == THETA)
//    {
//        type = DELTA;
//    }

//    else if(type == DELTA)
//    {
//        type = SUBDELTA;
//    }
//    else
//    {
//        type = MET;
//    }

//    //cout<<type<<endl;
//    return type;
//}

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
