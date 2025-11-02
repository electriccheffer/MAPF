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
	float height = .1; 
	float width = .1; 
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval interval = {space,dimension}; 
	float spaceResult = interval.getSpace(); 
	EXPECT_EQ(space,spaceResult); 
}

TEST(TestDiscreteInterval,GetDimension){

	float space = .1; 
	float height = .1; 
	float width = .1; 
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D dimensionResult(height,width);
	DiscreteInterval interval(space,dimension);
	EXPECT_EQ(dimension,dimensionResult);	

}
