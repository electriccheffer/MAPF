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
	ObstacleDimension2D dimensionExpected(height,width);
	DiscreteInterval2D interval(space,dimension);
	ObstacleDimension2D dimensionResult = interval.getDimension(); 
	EXPECT_EQ(dimensionExpected,dimensionResult);	

}

TEST(TestDiscreteInterval,TestEqualityTrue){

	float space = .1; 
	float height = .1; 
	float width = .1; 
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(space,dimension);
	DiscreteInterval2D otherInterval(space,dimension); 
	EXPECT_EQ(interval,otherInterval);
}

TEST(TestDiscreteInterval,TestEqualityFalseSpaceMismatch){

	float space = .1; 
	float height = .1; 
	float width = .1;
        float otherSpace = .2; 	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(space,dimension);
	DiscreteInterval2D otherInterval(otherSpace,dimension); 
	EXPECT_FALSE(interval==otherInterval);
}

