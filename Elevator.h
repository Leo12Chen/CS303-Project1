#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

struct Elevator {
	string direction;                 //the direction of the Elevator is going;
	int current_floor;                //the current floor of Elevator is at;
        List<int> ListOfStop;             //List of the floors which Elevator will stop
	List<int> InSideRequestList;      //List of the floors which request by people in the elevator
	Queue<int> PendingQueue;          //Queue of the floors which are pending 
};




#endif
