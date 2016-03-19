#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include "resources.h"

typedef ResourceCollection Cost;
typedef ResourceCollection Reward;

class Action {
public:
    Action(Cost cost, Reward reward) : cost(cost), reward(reward) {}

    Cost cost;
    Reward reward;
};

#endif
