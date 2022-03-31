#include "session.h"

void session::selectGroup() {

    // also need to accommodate the group lit icon.

    // Press power button to select group
    if(selectedGroup == 2) { // last group type
        selectedGroup = 0;
    } else if (selectedGroup < 2) {
        selectedGroup++;

    }

    if (selectedGroup == 2) {
        // take input as QT
        // Save input in userDesignedSessionTime
        // Display that on the page
        // .typedQTInput = userDesignedSessionTime;
        
    }

    // whenver power button is pressed and released, group type will change
    // .onClickPower is just a temporary function, here you have to add the UI



void session::selectSessionNum(groupType group) {

   // whenver a certain group is selected, the session 
}