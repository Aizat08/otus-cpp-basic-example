#include "Vector.h"
#include <gtest/gtest.h>
#include <iostream>

//Testing the emtiness of vector
TEST(Vector1, Empty){

	const size_t size_ = 0;
	Forward_container<size_t> vect;

	ASSERT_EQ(vect.size(), size_);
}

//testing insert to the beginning of vector
TEST(Vector2, Insert){

	const size_t size_ = 10;
	Forward_container<size_t> vect;

	for(size_t i=0; i<size_; i++){
		vect.push_back(i);
	}

	vect.insert(0, 22);
	ASSERT_EQ(vect[0], 22);
	ASSERT_NE(vect.size(), size_);
}

//testing the removal of the elements from the head
//and tail of the vector
TEST(Vector3, Erase){

	const size_t size_ = 10;
	Forward_container<size_t> vect;

	for(size_t i=0; i<size_; i++){
		vect.push_back(i);
	}

	vect.erase(0);
	ASSERT_TRUE(vect[0] == 1);

	vect.erase(vect.size());
	ASSERT_EQ(vect[vect.size()], 8);
	ASSERT_NE(vect.size(), size_);

}

//testing throwing an exception
TEST(Vector4, Throw){

	const size_t size_ = 5;
	Forward_container<size_t> vect;

	for(size_t i=0; i<size_; i++){
		vect.push_back(i);
	}

	ASSERT_THROW(vect[size_ + 2], std::out_of_range);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



