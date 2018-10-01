#pragma once
#ifndef DNODE_H
#define DNODE_H

#include <cstddef>

struct DNode {
		int data;
		DNode* next;
		DNode* prev;
		DNode(const int& data_item, DNode* prev_val = NULL, DNode* next_val = NULL) :
			data(data_item), prev(prev_val), next(next_val) {}
	}; 
  
#endif
