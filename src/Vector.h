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

		if (position > _size) {
			 return false;
		}

		if (position == _size){
			position = _size - 1;
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

		if (index > _size) {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    	}

    	if(index == _size){
    		index = _size - 1;
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