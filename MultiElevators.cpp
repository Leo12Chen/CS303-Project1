#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "request.h"
#include "Elevator.h"
using namespace std;

int main(){

 vector<Elevator> upElevator;          //have vectors to store the elevators and sort them by three tendency
 vector<Elevator> downElevator;
 vector<Elevator> nonusingElevator;
 
 UpRequestList<int>;
 DownRequestList<int>;
 
struct UpRequestList{
  int FloorRequestAt;
  UpRequestList*next, prev;

UpRequestList(const int& data_item, UpRequestList* prev_val =NULL, UpRequestList* next_val = NULL) :FloorRequestAt(data_item), prev(prev_val), next(next_val) {}
};

struct DownRequestList{
  int FloorRequestAt;
  DownRequestList*next, prev;

DownRequestList(const int& data_item, DownRequestList* prev_val =NULL, DownRequestList* next_val = NULL) :FloorRequestAt(data_item), prev(prev_val), next(next_val) {}
};
 

return 0;
}

