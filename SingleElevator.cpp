/*##########################################################################
Project 1c SingleElevator
By Leo Chen and Steven Hoang
##########################################################################
Basic algorithm of the code :
For all activing elevators, they only have three direction, up, down, or stop.When they have up direction, they took all request which
floors above their current_floor and go all way up till the highest floor request, they will stop in the middle by the request's direction 
go up and also they are lower the highest floor request, once they stop elevator will remove the stopping floor from the stoplist.
If Elevator get request for going down or request higher than the highest floor in the stopping list, we will put these request in
the queue for waiting.After reach the highest request floor at, we check our top of queue, to decide the direction and destiniation floor, and
insert all floors we can stop on the way to the stop list and remove them from the queue.

When people get in the elevator they will push the button which we called insiderequest, the floor people request which on the direction
of the elevator will be add to stoplist directly and remove it from request list.If floor people request which is against the direction
of the elevator going, which could happen when people change their mind, we will push this request to the queue for waiting.

For nonusing elevators, if there are any request, compare the current floor and request floor at, decide the tendency of the nonusing
elevators and change it to activing elevators.
##########################################################################



##########################################################################*/
#include <iostream>
#include <cmath>
#include "List.h"
#include "Elevator.h"
#include "Request.h"
#include "Queue.h"

using namespace std; 

void RecieveInsideRequest(Elevator& elevator, Queue& queue, int requestFloorTo) { //this fuction take care of people push the button inside of the elevator
	if (elevator.direction == "up" && requestFloorTo > elevator.current_floor) { // when elevator going up and people request the floor higher than current
		elevator.ListOfStop.AscendInsert(requestFloorTo);                      // add it to stop list
		cout << endl << "Floor " << requestFloorTo << " has been placed into the list of next stops." << endl << endl;
	}
	else if (elevator.direction == "down" && requestFloorTo < elevator.current_floor) {//when elevator going down and request floor lower than current
		elevator.ListOfStop.DescendInsert(requestFloorTo);                    //add it to stop list
		cout << endl << "Floor " << requestFloorTo << " has been placed into the list of next stops." << endl << endl;
	}
	else {
		Request request;
		request.current_floor = requestFloorTo;                         //other than those, we put them in the queue for waiting
		request.direction = "stop";
		queue.push(request);
		cout << endl << "Floor " << requestFloorTo << " has been placed into the Queue for pending." << endl << endl;
	}
}

void RecieveOutSideRequest(Request&request, Queue&queue) {              //whenever we got request from outside, push it into queue
	
	queue.push(request);
}

void checkTheDirectionOfElevator(Elevator&elevator) {
	if (elevator.ListOfStop.empty() != true) {
		if (elevator.ListOfStop.getHeadData() > elevator.current_floor) //elevator's direction is decided by head of stop list
			elevator.direction = "up";
		else
			elevator.direction = "down";
	}
}

bool pushornot(Request request,Elevator&elevator,Queue&queue) {
	if (elevator.direction == "stop") {
		elevator.ListOfStop.push_back(request.current_floor);
		return true;
	}
	else if (elevator.direction == "up"&&request.direction == "up") {
		if ((elevator.ListOfStop.getTailData()) > (request.current_floor) && (request.current_floor) > (elevator.current_floor)) {
			elevator.ListOfStop.AscendInsert(request.current_floor);
			return true;
		}
	}
	else if (elevator.direction == "down"&&request.direction == "down") {
		if ((elevator.ListOfStop.getTailData()) < (request.current_floor) && (request.current_floor) < (elevator.current_floor)) {
			elevator.ListOfStop.DescendInsert(request.current_floor);
			return true;
		}
	}
	else {
		queue.push(request);
		return false;
	}
}

void pushPendingRequestToStoppingList(Elevator&elevator, Queue&queue) {//deal with request in queue
	elevator.ListOfStop.push_back(queue.front().current_floor);        //check the top of queue and push it to the stop list
	queue.pop();                                                       //pop it
	Queue TempQ ;
	while (queue.empty() != true) {                                    //check wether there are any request we can stop by on the way
		if (queue.front().direction == "stop") {                       //for those insiderequest we pushed into the queue
			if (elevator.direction == "up"&& elevator.current_floor < queue.front().current_floor) {  // if they are on the way push it to the list and pop it from the queue
				elevator.ListOfStop.AscendInsert(queue.front().current_floor);
			}
			else if (elevator.direction == "down" && elevator.current_floor > queue.front().current_floor) {
				elevator.ListOfStop.DescendInsert(queue.front().current_floor);
			}
		}
		else if (elevator.direction == "up" && queue.front().direction == "up" && (elevator.ListOfStop.getTailData()) > (queue.front().current_floor) > (elevator.current_floor)) {
			elevator.ListOfStop.AscendInsert(queue.front().current_floor);
			queue.pop();
		}
		else if (elevator.direction == "down" && queue.front().direction == "down" && (elevator.ListOfStop.getTailData()) < (queue.front().current_floor) < (elevator.current_floor)) {
			elevator.ListOfStop.DescendInsert(queue.front().current_floor);
			queue.pop();
		}
		else {                        //for those request we cant make it by the way, we push it to a temp queue and make a new queue for pending request
			TempQ.push(queue.front());
			queue.pop();
		}
		queue = TempQ;
	}
}



int main() {
	Queue RequestQueue;
	Elevator singleElevator;
	//singleElevator.current_floor = 1;
	//singleElevator.direction = "Stop";
	
	int requestFloorTo;
//	RecieveOutSideRequest(request, RequestQueue);
//	RecieveInsideRequest(singleElevator, RequestQueue, requestFloorTo);
	int choice = 0;
	int counter = 0;
	Request request;
	/*
	request.current_floor = 0;
	request.direction = "up";
	RecieveOutSideRequest(request, RequestQueue);
	cout << RequestQueue.front().current_floor << RequestQueue.front().direction << endl;*/
	while (counter == 0) {
		
		cout << "You have to insert request manually since our project will only take care of how elevator take care of request" << endl;
		cout << "1.Set the elevator's floor" << endl;
		cout << "2.Set a outside request" << endl;
		cout << "3.Set a inside request" << endl;
		cout << "4.Show elevator current information" << endl;
		cout << "5.Show the pending request queue!" << endl;
		cout << "6.Stop the simulator" << endl<<endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "Which floor is our awesome elevator at now?" << endl;
			int cfloor;
			cin >> cfloor;
			singleElevator.current_floor = cfloor;
			singleElevator.direction = "stop";
			cout << "Our elevator is at" << cfloor << " now!" << endl << endl;
			if (singleElevator.ListOfStop.empty() != true) {
				if (singleElevator.current_floor == singleElevator.ListOfStop.getHeadData()) {     //when it reaches the floor in the stop list
					singleElevator.ListOfStop.pop_front();
				}
			}
			if (singleElevator.ListOfStop.empty() == true) {            //when elevator stop list is empty
				if (RequestQueue.empty() != true)                       //if there pending queue is not empty
					pushPendingRequestToStoppingList(singleElevator, RequestQueue); //push pending request to the elevator
				else
					singleElevator.direction = "stop";                   //if both list and queue are empty, elevator will take a break
			}

			break; }

		case 2: {
			cout << "Okay we need to know which floor you are at and which direction you wanna go and we will tell you how elevator will handle this request" << endl;
			cout << "Elevator is at " << singleElevator.current_floor << " and its direction is " << singleElevator.direction << endl;
			cout << "Tell me where you at now" << endl;
			int cfloor;
			cin >> cfloor;
			cout << "Tell me which direction you wanna go(up or down,they are only choice my friend)" << endl;
			string direc;
			cin >> direc;
			Request request;
			request.current_floor = cfloor;
			request.direction = direc;
			//cout << singleElevator.direction << endl;


			//cout << crequest.current_floor << crequest.direction << endl;


			//RecieveOutSideRequest(request, RequestQueue);

			//cout << RequestQueue.front().current_floor << RequestQueue.front().direction << endl;

			if (pushornot(request, singleElevator, RequestQueue) == true) {
				cout << "the request has been insert to stoplist of elevator, it will stop by you in this round" << endl;
				//pushPendingRequestToStoppingList(singleElevator, RequestQueue);
			}
			else {
				cout << "Your request won't be insert to stoplist now, it will be inserted into queue and take care of it later" << endl;
			}
			checkTheDirectionOfElevator(singleElevator);

			//	singleElevator.ListOfStop.printList();
				//cout << "##################" << endl;

				//cout << singleElevator.ListOfStop.getHeadData() <<"    "<< singleElevator.current_floor << endl;

				/*if (singleElevator.ListOfStop.head->data > singleElevator.current_floor) //elevator's direction is decided by head of stop list
					singleElevator.direction == "up";
				else
					singleElevator.direction == "down";*/




					//	if (singleElevator.ListOfStop.empty() == false) {                                 //when elevator is running

					//	}



			break;
		}
		case 3: {
			cout << endl << "Which floor would you like to go to?" << endl << endl;
			cin >> requestFloorTo;
			RecieveInsideRequest(singleElevator, RequestQueue, requestFloorTo);
			system("pause");
			cout << endl;
			system("CLS");
			break;
		}
		case 4: {
			cout << "Elevator is now at the " << singleElevator.current_floor << " and the direction of it is " << singleElevator.direction << endl;
			cout << "The floors elevator gonna to stop:" << endl;
			singleElevator.ListOfStop.printList();
			cout << endl << endl;
			break;

		}
		case 5: {
			cout << "Here is the pending requests in the queue, first-in-first-out!" << endl;
			RequestQueue.printQueue();
			system("pause");
			break;
		}
		case 6: {
				system("CLS");
				cout << "Thank you for using our Elevator Simulator!" << endl;
				system("pause");
				counter = 1;
				break;
		}
		default:
			cout << "Come on read carefully! Hit the right number!" << endl<<endl;
		}


		
	}
	



	return 0;
}
