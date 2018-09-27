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

	ListOfStop Elevator_1;
	ListOfInSideRequest Elevator_1;
	ListOfOutsideRequest Elevator_1;

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

	ListOfInSideRequest(const int& data_item, ListOfInSideRequest* prev_val = NULL, ListOfInSideRequest* next_val = NULL) :FloorForRequest(data_item), prev(prev_val), next(next_val) {}
};

struct ListOfOutsideRequest
{
	int floorAt;
	string direction;

	ListOfOutsideRequest(int floor_at, string direct) {};
	ListOfOutsideRequest(int floor_at = NULL, string direct = NULL);

};


#endif
