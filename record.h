#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <ctime>

#include "session.h"


using namespace std;

#DEFINE MAX_SESSIONS 8

class Record {

    public:
    Record();
    void saveRecords(Session s);
    void createRecord(Session* s);
    String convertToString(Session* s);
    String getCurrDate();
    



    private:
    Session sessions[MAX_SESSIONS];
    int numSessions;


};

#endif