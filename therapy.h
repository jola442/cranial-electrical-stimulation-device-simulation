#ifndef THERAPY_H
#define THERAPY_H

#include "defs.h"

class Therapy {

    public:
    Therapy(string="none"; float=0; float=0);
    ~Therapy();
    void setIntensity(int);
    void populateTherapies(Therapy* therapies[MAX_THERAPY_COUNT]);

    private:
    string name;
    float minFreq;
    float maxFreq;
    int intensity;
    // int duration;
   

};
#endif