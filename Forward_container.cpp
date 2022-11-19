#include <iostream>

template <typename T>
class Forward_container {

public:
	Forward_container() : _size{0}, array{new T[_size]} {}

	~Forward_container(){

		delete[] array;
	}
	
	void push_back(const T& value){

		T* new_array = new T[_size + 1];

		for(size_t i=0; i<_size; ++i){
			new_array[i] = array[i]; }
			
		new_array[_size] = value;
		delete[] array;

		array = new_array; 
		_size++; 
	}
	
	bool erase(size_t position){

		if (position >= _size) {
			return false;
		}

		for (size_t i = position; i<_size; ++i) 
		{
			array[i] = array[i + 1];
		}

		_size--;

		return true;
	}

	void insert(size_t position, const T &value){

		if(position == _size) {

			push_back(value);
		}

		else{

			T* new_array = new T[_size + 1];

			for(size_t i=0; i<_size; ++i){

				if(i<position){
					new_array[i] = array[i]; }

				else if(i>position){
					new_array[i] = array[i-1]; }

				else{
					new_array[i] = value; }
			}

			new_array[_size] = array[_size - 1];

			delete[] array;

			array = new_array; 
			_size++; 
		}
		
	}


	T& operator[](size_t index){

		if (index >= _size) {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    	}

   		 return array[index];
	}

	size_t size() {return _size;}

	void print() {

		for(size_t i=0; i<_size; ++i){
		std::cout << array[i] << " ";  }

		std::cout << "\n";
	}

private:
	size_t _size;
	T* array;
};   

int main()
{
	Forward_container<int> container; 

	for(int i=0; i<10; i++){
		container.push_back(i);}
	
	std::cout << "Initial container members: " << std::endl;
	container.print();
	std::cout << "Container size: " << container.size() << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Erasing the third, fifth and seventh elements from container" << std::endl;
	container.erase(3);
	container.erase(5);
	container.erase(7);
	container.print();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "Inserting 10 --> BEGIN, 20 --> MIDDLE and 30 --> END of container" << std::endl;
	container.insert(0, 10);
	container.insert(4, 20);
	container.insert(container.size(), 30);
	container.print();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	int* ptr = &container[0];
	std::cout << "Cheking the operator[] overload: " << *ptr << std::endl;

}