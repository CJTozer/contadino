#ifndef BOARDSPACE_H_INCLUDED
#define BOARDSPACE_H_INCLUDED

#include "action.h"

class BoardSpace
{
public:
    Action* action;

    void refresh();
};

#endif
