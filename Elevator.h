#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "List.h"
#include <iostream>
#include <string>
using namespace std;

struct Elevator {
	string direction;                 //the direction of the Elevator is going;
	int current_floor;                //the current floor of Elevator is at;
        List<int> ListOfStop;             //List of the floors which Elevator will stop
};




#endif
