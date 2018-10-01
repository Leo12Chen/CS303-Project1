#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

struct Elevator {
	string direction;
	int current_floor;
        List<int> ListOfStop;
	List<int> InSideRequestList;
	Queue<int> PendingQueue;
};




#endif
