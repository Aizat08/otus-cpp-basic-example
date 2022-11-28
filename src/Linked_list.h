#include<iostream>

template<typename T>
class LinkedList{

private:
	struct Node{

		T item;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	Node* head_node; 
	Node* current;  
	size_t size_; 

public:
	LinkedList() : size_(0), head_node(new Node()), current(nullptr) {}
	~LinkedList(){
		delete head_node;
		delete current;
	}

	void push_back(const T& value){

		Node* new_node = new Node();
		new_node->prev = current;
		new_node->next = nullptr;
		new_node->item = value;
		current = new_node;

		if(size_ == 0){
			head_node->next = current;	
		}

	    if(size_ != 0){
			(current->prev)->next = current;
		}

		size_++;

	}

	void insert(const T& value, size_t position){

		if(position == size_){
			push_back(value);
		} 

		else{

			if(position == 0){
				Node* node_zero = new Node();
				node_zero->item = value;
				node_zero->next = head_node->next;
				head_node->next = node_zero;
				size_++;

			}

			else{	
				Node* middle_node = new Node();
				middle_node->item = value;
				Node* temp;
		
				temp = head_node->next;
			
				for(size_t i=0; i<position; i++){
					temp = temp->next;
				}

				middle_node->next = temp;
				middle_node->prev = temp->prev;
				(middle_node->next)->prev = middle_node;
				(middle_node->prev)->next = middle_node;

				size_++;
			}
		}
		
	}

	bool erase(size_t position){

		if(position >= size_) {
			return false;
		}

		if(position == size_ - 1){
			Node* node_to_delete;
			node_to_delete = head_node->next;
			for(size_t i=0; i<position; i++){
				node_to_delete = node_to_delete->next;
			}
			delete node_to_delete;
			size_--;
		}
		
		else{ 
			
			if(position == 0){
				head_node->next = (head_node->next)->next;
				(head_node->next)->prev = nullptr;

			size_--;
			}

			else{
				Node* node;
				node = head_node->next;
				for(size_t i=0; i<position; i++){
					node = node->next; 
				}
				(node->next)->prev = node->prev;
				(node->prev)->next = node->next;
				delete node;

				size_--;
			}
		}

		return true;
	}

	size_t findElement(size_t position){
		Node* print_node;
		print_node = head_node->next;

		if(position == 0){
			return print_node->item;
		}

		else{

			for(size_t i=0; i<position; i++){
				print_node = print_node->next;
			}

			return print_node->item;
		}
	}

	size_t size(){
		return size_;
	}
};


