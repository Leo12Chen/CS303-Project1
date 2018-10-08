#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cmath>
#include <cstddef>
#include "DNode.h"

class List {
public:
	DNode* head;
	DNode* tail;
	size_t num_items;


	void push_front(const int& item) {
		head = new DNode(item, NULL, head);
		if (head->next != NULL)
			head->next->prev = head;
		if (tail == NULL)
			tail = head;
		num_items++;
	}
	void push_back(const int& item) {
		if (tail != NULL) {
			tail->next = new DNode(item, tail, NULL);
			tail = tail->next;
			num_items++;
		}
		else {
			push_front(item);
		}
	}

	void pop_front() {
		if (head == NULL)
			throw std::invalid_argument
			("List is empty");
		DNode* removed_node = head;
		head = head->next;
		delete removed_node;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
		num_items--;
	}

	void pop_back() {
		if (tail == NULL)
			throw std::invalid_argument
			("List is empty");
		DNode* removed_node = tail;
		tail = tail->prev;
		delete removed_node;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;
		num_items--;
	}

	void remove(const int& item) {
		DNode* current_node = head;

		while (current_node != NULL) {

			if (current_node->data == item) {
				if (current_node->next == NULL)  //the last element in the list
					return pop_back();

				if (current_node == head)       //if the node we are deleting is the head
					head = current_node->next;

				DNode* to_be_deleted = current_node;
				current_node->next->prev = current_node->prev;
				if (current_node->prev != NULL)
					current_node->prev->next = current_node->next;

				current_node = current_node->next;
				delete to_be_deleted;
				num_items--;
			}
			else
				current_node = current_node->next;
		}
	}

	bool empty() {
		if (num_items>0)
			return true;
		else
			return false;
	}

	void AscendInsert(const int& item) {
		DNode* temp = new DNode(item, NULL, head->next);
		if (item < head->data) {               //  when item inserting is smaller than head   
			push_front(item);
		}
		else if (item > head->data&&head->next == NULL) {   //when list only have a head and inserting item is larger than head
			push_back(item);
		}
		else {
			while (temp != NULL) { //when item larger than head and list has more than one elements
				if ((temp->data > temp->prev->data) && (temp->data < temp->next->data)) {//when item find the position it fits in 
					temp->prev->next = temp;  // insert the temp into the list
					temp->next->prev = temp;
					break;
				}
				else
					temp = temp->next;        // keep going next until it find the position
			}
			push_back(item); // when item larger than any element in the list
		}
	}
	void DescendInsert(const int& item) {
		DNode* temp = new DNode(item, NULL, head->next);
		if (item > head->data) {               //  when item inserting is larger than head   
			push_front(item);
		}
		else if (item < head->data&&head->next == NULL) {   //when list only have a head and inserting item is smaller than head
			push_back(item);
		}
		else {
			while (temp != NULL) { //when item smaller than head and list has more than one elements
				if ((temp->data < temp->prev->data) && (temp->data > temp->next->data)) {//when item find the position it fits in 
					temp->prev->next = temp;  // insert the temp into the list
					temp->next->prev = temp;
					break;
				}
				else
					temp = temp->next;        // keep going next until it find the position
			}
			push_back(item); // when item larger than any element in the list
		}
	}
};


#endif
