
#pragma once
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std; 

struct Elevator(){
	string tendency;
  int current_floor;
  ListOfStop<int>;
  ListOfInSideRequest<int>;

};

struct ListOfStop{
int FloorToStop;
ListOfStop*next, prev;

ListOfStop(const int& data_item, ListOfStop* prev_val =NULL, ListOfStop* next_val = NULL) :FloorToStop(data_item), prev(prev_val), next(next_val) {}
};

struct ListOfInSideRequest{
int FloorForRequest;
ListOfInSideRequest*next, prev;

ListOfInSideRequest(const int& data_item, ListOfInSideRequest* prev_val =NULL, ListOfInSideRequest* next_val = NULL) :FloorForRequest(data_item), prev(prev_val), next(next_val) {}
};
