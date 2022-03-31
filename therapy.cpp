#include "therapy.h"

therapy::therapy(string n; float minFreq, float maxFreq)
{
    this->name = n;
    this->minFreq = minFreq;
    this->maxFreq = maxFreq;
    intensity = 0;
}

void therapy::setIntensity(int intensity)
{
    this->intensity = intensity;
}

