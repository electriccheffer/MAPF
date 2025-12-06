#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/Map.hpp"
#include "./testSubclasses/MapTestSubclasses.cpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

TEST(TestMapData,TrivialTestAlwaysPasses){

	EXPECT_TRUE(true); 
}

TEST(TestMapTuple,TestMapTupleLowerBound){
	
	float xPosition = 2.456; 
	float yPosition = 4.245; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition); 
	TestMapTuple2D mapTuple(position,interval);
	ObstaclePosition2D positionResult = mapTuple.getFloor(); 
	ObstaclePosition2D positionExpected(2.4,4.2);
        EXPECT_EQ(positionResult,positionExpected); 	
}

TEST(TestMapTuple,TestMapTupleLowerBoundNegative){

	float xPosition = -2.456; 
	float yPosition = 4.245; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition); 
	TestMapTuple2D mapTuple(position,interval);
	ObstaclePosition2D positionResult = mapTuple.getFloor(); 
	ObstaclePosition2D positionExpected(-2.4,4.2);
        EXPECT_EQ(positionResult,positionExpected);

}
