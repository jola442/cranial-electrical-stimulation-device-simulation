#include "record.h"

Record::Record()
{
    numSessions = 0;
}

void Record::saveRecords(Session s)
{
    if(numSessions < MAX_SESSIONS)
    {
        sessions[numSessions] = s;
        numSessions++;
        return;
    }
   
   return;
}

void Record::createRecord(Session* s)
{
    String date = getCurrDate();
    String type = convertToString(s.getType());
    String temp = "";

    temp = temp +  "Date: " + date + "\n"+
    "Session: " + type + "\n" +
    " Intensity: " + s.getIntensity() + "\n" +
    " Duration: " + s.getDuration() + "\n";

    cout << temp << endl;

}

String Record:: convertToString(Session* s)
{
    int num = s->getType();
   switch(num){

    case MET:
        return "MET";
        break;

    case SUBDELTA:
        return "SUBDELTA";
        break;

    case DELTA:
        return "DELTA";
        break;

    case THETA:
        return "THETA";
        break;

    default:
        return "NON";
        break;
}

String Record::getCurrDate()
{
    time_t now = time(0);
    String date_time = ctime(&now);

   return date_time;
}