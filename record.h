#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <ctime>

#include "session.h"


using namespace std;

#define MAX_SESSIONS 8

class Record {

    public:
    Record();
    void saveRecords(Session* s);
    string createRecord(Session* s);
    string convertToString(Session* s);
    string getCurrDate();
    



    private:
    Session* sessions[MAX_SESSIONS];
    int numSessions;


};

#endif