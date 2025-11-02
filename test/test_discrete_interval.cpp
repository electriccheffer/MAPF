#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true); 

}

TEST(TestDiscreteInterval,GetSpaceInterval){

	float space = .1; 
	DiscreteInterval interval = {space}; 
	float spaceResult = interval.getSpace(); 
	EXPECT_EQ(space,spaceResult); 
}

