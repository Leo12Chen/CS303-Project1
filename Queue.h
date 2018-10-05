#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include "DNode.h"
#include <exception>
using namespace std;

class Queue {
private:

	DNode* FrontRequest;
	DNode* LastRequest;
	size_t num_items;

public:

	Queue(DNode* FrontRequest = NULL, DNode* LastRequest = NULL) :
		FrontRequest(FrontRequest), LastRequest(LastRequest), num_items(0) {}

	void push(const int& item) {
		if (FrontRequest == NULL) {
			LastRequest = new DNode(item, NULL);
			FrontRequest = LastRequest;
			LastRequest = new DNode(item, NULL);
			FrontRequest = LastRequest;
		}
		else {
			LastRequest->next = new DNode(item, NULL);
			LastRequest = LastRequest->next;
		}
		num_items++;
	}

	int& front() {
		return FrontRequest->data;

	}

	int size() {
		return num_items;
	}


	void pop() {
		DNode* old_front = FrontRequest;
		FrontRequest = FrontRequest->next;
		if (FrontRequest == NULL) {
			LastRequest = NULL;
		}
		delete old_front;
		num_items--;
	}

	void pop_target(const int& target) {

		if (FrontRequest == NULL)
			cout << "No Item in Queue" << endl;

		int counter = size();

		bool deleted = false;

		while (counter != 0) {
			if (FrontRequest->data != target) {
				push(FrontRequest->data);
				pop();
				counter--;
			}
			else if (FrontRequest->data == target) {
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
