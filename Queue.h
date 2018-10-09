#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include "DnodeQueue.h"
#include "Request.h"
using namespace std;

class Queue {
private:

	DNodeQueue * FrontRequest;
	DNodeQueue* LastRequest;
	size_t num_items;

public:

	Queue(DNodeQueue* FrontRequest = NULL, DNodeQueue* LastRequest = NULL) :
		FrontRequest(FrontRequest), LastRequest(LastRequest), num_items(0) {}

	
	void printQueue() {

		if (FrontRequest == NULL) {
			cout << "No Item in Queue" << endl;
			return;
		}

		int counter = size();

		cout << "The following items are in the Queue:" << endl;
		while (counter != 0) {
			cout << front().current_floor << " " << front().direction << endl;
			push(front());
			pop();
			counter--;
		}

	}
	
	void push(const Request& item) {
		if (FrontRequest == NULL) {
			LastRequest = new DNodeQueue(item, NULL);
			FrontRequest = LastRequest;
			LastRequest = new DNodeQueue(item, NULL);
			FrontRequest = LastRequest;
		}
		else {
			LastRequest->next = new DNodeQueue(item, NULL);
			LastRequest = LastRequest->next;
		}
		num_items++;
	}

	const Request& front() {
		return FrontRequest->data;
	}

	int size() {
		return num_items;
	}


	void pop() {
		DNodeQueue* old_front = FrontRequest;
		FrontRequest = FrontRequest->next;
		if (FrontRequest == NULL) {
			LastRequest = NULL;
		}
		delete old_front;
		num_items--;
	}

	bool empty() {
		if (num_items == 0)
			return true;
		else
			return false;
	}

	void pop_target(const Request& target) {

		if (FrontRequest == NULL)
			cout << "No Item in Queue" << endl;

		int counter = size();

		bool deleted = false;

		while (counter != 0) {
			if (FrontRequest->data.current_floor != target.current_floor || FrontRequest->data.direction != target.direction) {
				push(FrontRequest->data);
				pop();
				counter--;
			}
			else if (FrontRequest->data.current_floor == target.current_floor && FrontRequest->data.direction == target.direction) {
				pop();
				counter--;
				deleted = true;

			}
		}
		if (deleted == false)
			cout << "This Request does not exist" << endl;
	}
};



#endif
