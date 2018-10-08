#pragma once
#ifndef DNODEQUEUE_H
#define DNODEQUEUE_H

#include <cstddef>
#include <string>
#include "Request.h"
using namespace std;

struct DNodeQueue {
	Request data;
	DNodeQueue* next;
	DNodeQueue* prev;
	DNodeQueue(const Request& data_item, DNodeQueue* prev_val = NULL, DNodeQueue* next_val = NULL) :
		data(data_item), prev(prev_val), next(next_val) {}
};

#endif
