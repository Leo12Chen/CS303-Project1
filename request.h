##################################################################
/*
Leo please take a look at this code and determine the best course of action. I'm not 100% sure how your algorithm works,
So I just wrote this code really quick. Edit as needed. Thanks!
NO WHERE NEAR DONE BTW!
*/
##################################################################

#pragma once
#ifndef REQUEST_H
#define REQUEST_H

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std; 

struct request
{
	request* floorAt;
	
	string tendency;

	request(request* floor_at = NULL, string tenden = NULL);
	request(request* floor_at, string tenden) {};

};

//insert a new request after a given request

void insertRequestAfter(struct request* prev_request, string tenden)
{

	if (prev_request == NULL) {
		throw::exception("No request is currently in the queue");
		return;
	}

	struct request* new_request = new request;

	new_request->tendency = tenden;

	new_request->floorAt = prev_request;

	if (new_request->floorTo != NULL)
		new_request-> floorAt = new_request;
}



#endif
