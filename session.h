#ifndef SESSION_H
#define SESSION_H


typedef enum {NON,MET, SUBDELTA, DELTA, THETA} sessionNumType;
class Session {

    public:
        Session();
        int increaseIntensity();
        int decreaseIntensity();
//        int nextSession();
//        int previousSession();
        void setType(sessionNumType newType);
        sessionNumType getType();
        float getDuration();
        int getIntensity();
        void setDuration(float dur);
        void setIntensity(int inten);

    private:
        int intensity;
        sessionNumType type;
        float duration;
};
#endif
