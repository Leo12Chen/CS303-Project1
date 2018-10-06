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
#include "Queue.h"

using namepace std;

void RecieveInsideRequest(Elevator elevator,Queue queue,int requestFloorTo){ //this fuction take care of people push the button inside of the elevator
     if(elevator.direction == "up" && requestFloorTo > elevator.current_floor) // when elevator going up and people request the floor higher than current
        elevator.ListOfStop.AscendInsert(requestFloorTo);                      // add it to stop list
     else if (elevator.direction == "down" && requestFloorTo < elevator.current_floor)//when elevator going down and request floor lower than current
        elevator.ListOfStop.DescendInsert(requestFloorTo);                    //add it to stop list
     else {
         Request request = new Request("stop",requestFloorTo);                //other than those, we put them in the queue for waiting
         queue.push(requst);
     }        
}

void RecieveOutSideRequest(Request request, Queue queue){   //whenever we got request from outside, push it into queue
    queue.push(request);
}

void pushOutSideRequestToStoppingList(Elevator elevator,Queue queue){//deal with request in queue
     elevator.ListOfStop.pushback(queue.front());                    //check the top of queue and push it to the stop list
     queue.pop();                                                    //pop it
     Queue TempQ = new Queue();
     while(queue.empty()!=true){                                     //check wether there are any request we can stop by on the way
        if(queue.front().direction == "stop"){                       //for those insiderequest we pushed into the queue
          if(elevator.direction == "up"&& elevator.curret_floor < queue.front().current_floor){  // if they are on the way push it to the list and pop it from the queue
             elevator.ListOfStop.AscendInsert(queue.front().current_floor;)
          }
          else if(elevator.direction == "down" && elevator.current_floor> queue.front().current_floor){
             elevator.ListOfStOP.DescendInsert(queue.front().current_floor;)
          }           
        }
        else if(elevator.direction == "up" && queue.front().direction == "up" && (elevator.ListOfStop.tail->data) > (queue.front().current_floor) > (elevator.current_floor) ){
          elevator.ListOfStop.AscendInsert(queue.front().current_floor);
          queue.front();
        }
        else if(elevator.direction == "down" && queue.top().direction == "down" && (elevator.ListOfStop.tail->data) < (queue.front().current_floor) < (elevator.current_floor) ){
          elevator.ListOfStop.DescendInsert(queue.front().current_floor);
          queue.pop();
        }
        else{                        //for those request we cant make it by the way, we push it to a temp queue and make a new queue for pending request
          tempQ.push(queue.front());
          queue.pop()
        }
        queue=tempQ;
     }     
}



int main(){
   Elevator singleElevator = new Elevator();
   Queue RequestQueue = new Queue();
   Request request = new Request();
 
   RecieveOutSideRequest(request,queue);
   RecieveInSideRequest(singleElevator,RequestQueue,requestFloorTo);
 
   if (singleElevator.ListOfStop.empty() == false){  //when elevator is running
      if (singleElevator.current_floor==singleElevator.ListOfStop->head->data) //when it reaches the floor in the stop list
          singleElevator.ListOfStop.popfront();                                //pop it from list
      else if(singleElevator.ListOfStop.head->data > singleElevator.current_floor) //elevator's direction is decided by head of stop list
          singleElevator.direction == "up";
      else
          singleElevator.direction == "down";
   }
 
   if (singleElevator.ListOfStop.empty() == true){           //when elevator stop list is empty
      if(Request Queue.empty()!= true)                       //if there pending queue is not empty
       pushOutSideRequestToStoppingList(singleElevator,queue); //push pending request to the elevator
      else
       singleElevator.direction = "stop";                   //if both list and queue are empty, elevator will take a break
   }
   

   
 



return 0;
}
