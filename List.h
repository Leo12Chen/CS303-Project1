#include <iostream>
#include <cmath>
#include <cstddef>

class list{
private:
struct DNode {
		int data;
		DNode* next;
		DNode* prev;
		DNode(const Item_Type& data_item, DNode* prev_val = NULL, DNode* next_val = NULL) :
			data(data_item), prev(prev_val), next(next_val) {}
	}; 
  DNode* head;
	DNode* tail;
	size_t num_items;
}
public:
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
  
  void remove(const int& item){
		DNode* current_node = head;

		while (current_node != NULL){

			if (current_node->data == item){
				if (current_node->next == NULL)//the last element in the list
					return pop_back();

				if (current_node == head) //if the node we are deleting is the head
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
  
  bool empty(){	
		if (num_items>0)
     return true;
    else
     return false;    
	}
  
  
}
