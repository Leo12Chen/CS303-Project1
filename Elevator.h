#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Elevator {
	string direction;
	int current_floor;

	ListOfStop ElevatorStop_1;
	ListOfInSideRequest ElevatorInside_1;
	ListOfOutsideRequest ElevatorOutside_1;
 
	Elevator(string dir, const int& currentFloor, ListOfStop list1 , ListOfInSideRequest list2, ListOfOutsideRequest list3) :
	direction(dir), current_floor(currentFloor), ElevatorStop_1(list1), ElevatorInside_1(list2), ElevatorOutside_1(list3)  {}


};

struct ListOfStop {
	int FloorToStop;
	ListOfStop* next;
	ListOfStop* prev;

	ListOfStop(const int& data_item, ListOfStop* prev_val = NULL, ListOfStop* next_val = NULL) :FloorToStop(data_item), prev(prev_val), next(next_val) {}
};

struct ListOfInSideRequest {
	int FloorRequested;
	ListOfInSideRequest* next;
	ListOfInSideRequest* prev;

	ListOfInSideRequest(const int& data_item, ListOfInSideRequest* prev_val = NULL, ListOfInSideRequest* next_val = NULL) : FloorRequested(data_item), prev(prev_val), next(next_val) {}
};

struct ListOfOutsideRequest
{
	int floorAt;
	string direction;

	ListOfOutsideRequest(int floor_at, string direct) {};
	ListOfOutsideRequest(int floor_at = NULL, string direct = NULL);

};


#endif
