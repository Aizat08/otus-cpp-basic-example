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

	void print(){
		Node* print_node;
		print_node = head_node->next;
		for(size_t i=0; i<size_; i++){
			T value = print_node->item;
			std::cout << value << " ";
			print_node = print_node->next;
		}

		std::cout << "\n";
	}

	size_t size(){
		return size_;
	}
};

int main(){
	LinkedList<int> list; 

	for(int i=0; i<10; i++){
		list.push_back(i);}
	
	std::cout << "Initial list members: " << std::endl;
	list.print();
	std::cout << "List size: " << list.size() << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Erasing the third, fifth and seventh elements from list" << std::endl;
	list.erase(3);
	list.erase(5);
	list.erase(7);
	list.print();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Inserting 10 --> BEGIN, 20 --> MIDDLE and 30 --> END of list" << std::endl;
	list.insert(30, list.size());
	list.insert(10, 0);
	list.insert(20, 4);
	list.print();
	
}