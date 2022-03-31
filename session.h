#ifndef SESSION_H
#define SESSION_H

#include "defs.h"

class Session {

    public:
    Session();
    ~Session();
    void selectGroup();
    int selectSessionNum(groupType group);
    
    private:
    groupType selectedGroup;
    int userDesignedSessionTime;

};
#endif