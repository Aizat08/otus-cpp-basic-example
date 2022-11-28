#include "Linked_list.h"
#include <gtest/gtest.h>
#include <iostream>

//Testing push_back
TEST(LinkedList, PushBack){

	const size_t size_ = 10;

	LinkedList<size_t> list;
	for(size_t i=0; i<size_; i++){
		list.push_back(i+2);
	}

	ASSERT_EQ(list.size(), size_);
	ASSERT_TRUE(list.findElement(0) == 2);
	ASSERT_TRUE(list.findElement(5) == 7);
	ASSERT_TRUE(list.findElement(list.size()-1) == 11);
}

//testing insert 
TEST(DoubleList, Insert){

	//arrange 
	const size_t _size = 10;
	LinkedList<size_t> list1;
	
	//little bit creepy ....

	//act 
	for(size_t i=0; i<_size; i++){
		list1.push_back(i);
	}

	ASSERT_EQ(list1.size(), _size);

	list1.insert(77, 0);
	ASSERT_TRUE(list1.size() == _size+1);
	list1.insert(20, 4);
	ASSERT_TRUE(list1.size() == _size+2);
	list1.insert(30, list1.size());
	ASSERT_TRUE(list1.size() == _size+3);

	ASSERT_EQ(list1.findElement(0), 77);
	ASSERT_EQ(list1.findElement(4), 20);
	ASSERT_EQ(list1.findElement(list1.size()-1), 30);
}

//testing erase
TEST(List, Erase){

	//arrange
	const size_t size_ = 10;
	LinkedList<size_t> my_list;

	//act 
	for(size_t i=0; i<size_; i++){
		my_list.push_back(i);
	}

	my_list.erase(0);
	my_list.erase(4);
	my_list.erase(my_list.size());

	ASSERT_EQ(my_list.findElement(0), 1);
	ASSERT_EQ(my_list.findElement(4), 6);
	ASSERT_TRUE(my_list.size() == size_-3);
	
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}






