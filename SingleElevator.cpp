##########################################################################
Project 1c SingleElevator
By Leo Chen and Steven Hoang
##########################################################################
Basic algorithm of the code: 
 For all activing elevators, they only have three direction, up, down, or stop. When they have up direction, they took all request which
 floors above their current_floor and go all way up till the highest floor request, they will stop in the middle by the request's direction 
 go up and also they are lower the highest floor request, once they stop elevator will remove the stopping floor from the stoplist. 
 If Elevator get request for going down or request higher than the highest floor in the stopping list, we will put these request in 
 the queue for waiting. After reach the highest request floor at, we check our top of queue, to decide the direction and destiniation floor, and
 insert all floors we can stop on the way to the stop list and remove them from the queue.
 
 When people get in the elevator they will push the button which we called insiderequest, the floor people request which on the direction
 of the elevator will be add to stoplist directly and remove it from request list. If floor people request which is against the direction
 of the elevator going, which could happen when people change their mind, we will push this request to the queue for waiting.
 
 For nonusing elevators, if there are any request, compare the current floor and request floor at, decide the tendency of the nonusing
 elevators and change it to activing elevators.
##########################################################################



##########################################################################
#include <iostream>
#include "stdafx.h"
#include <cmath>
#include "List.h"
#include "Elevator.h"
#include "Request.h"

using namepace std;

int main(){




return 0;
}
