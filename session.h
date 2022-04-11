#ifndef SESSION_H
#define SESSION_H


typedef enum {MET, SUBDELTA, DELTA, THETA,NON} sessionNumType;
class Session {

    public:
        Session();
        int increaseIntensity();
        int decreaseIntensity();
        int nextSession();
        int previousSession();
        float duration;
        void setType(sessionNumType newType);
        sessionNumType getType();
        float getDuration();
        int getIntensity();

    private:
        int intensity;
        sessionNumType type;
};
#endif
