#include "record.h"

Record::Record()
{
    numSessions = 0;
}

void Record::saveRecords(Session* s)
{
    Session* temp = new Session();
    temp->setType(s->getType());
    temp->setIntensity(s->getIntensity());
    temp->setDuration(s->getDuration());

    if(numSessions < MAX_SESSIONS)
    {
        sessions[numSessions] = temp;
        numSessions++;
        return;
    }
   
   return;
}

string Record::createRecord(Session* s)
{
    string date = getCurrDate();
    string type = convertToString(s);
    string temp = "";

    temp = temp +  " Date: " + date +
    " Session: " + type + "\n" +
    " Intensity: " + to_string(s->getIntensity()) + "\n" +
    " Duration: " + to_string(s->getDuration()) + "\n";


    cout << temp << endl;
    return temp;

}

string Record:: convertToString(Session* s)
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
}

string Record::getCurrDate()
{
    time_t now = time(0);
    string date_time = ctime(&now);

   return date_time;
}