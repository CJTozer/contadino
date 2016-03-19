#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include "resources.h"

typedef ResourceCollection Cost;
typedef ResourceCollection Reward;

class Action {
public:
    Cost cost;
    Reward reward;

    Action(Cost cost, Reward reward) : cost(cost), reward(reward) {}
};

#endif
