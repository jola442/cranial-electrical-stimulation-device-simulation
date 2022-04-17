#ifndef SESSION_H
#define SESSION_H


typedef enum {NON,MET, SUBDELTA, DELTA, THETA} sessionNumType;
class Session {

    public:
        Session();
        int increaseIntensity();
        int decreaseIntensity();
        void setType(sessionNumType newType);
        sessionNumType getType();
        float getDuration();
        int getIntensity();
        void setDuration(float dur);
        void setIntensity(int inten);

    private:
        int intensity; //intensity variable
        sessionNumType type; //type of session
        float duration; //duration of the session
};
#endif
