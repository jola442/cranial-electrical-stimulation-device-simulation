#ifndef SESSION_H
#define SESSION_H


class Session {

    public:
        Session();
        int increaseIntensity();
        int decreaseIntensity();
        void recordSession();

    private:
        int intensity;
};
#endif