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

TEST(TestMapTuple,TestMapTuple2DHashID){

	float xPosition = 2.4; 
	float yPosition = 4.2; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition); 
	MapTuple2D mapTuple(position,interval);
	long long expectedHash = 1572906; 
	long long hashResult = mapTuple.getHash(); 
}

TEST(TestMapTuple,TestMapTuple2DHashIDNegative){

	float xPosition = -2.4; 
	float yPosition = 4.2; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition); 
	MapTuple2D mapTuple(position,interval);
	long long expectedHash = -1572822; 
	long long hashResult = mapTuple.getHash(); 
}

TEST(TestMapData,RetrievePositionTrue){

	float xPosition = 2.4; 
	float yPosition = 4.2; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition); 
	MapData<ObstaclePosition2D,DiscreteInterval2D,MapTuple2D> mapData(interval); 
	mapData.add(position);
      	bool inMap = mapData.get(position); 
	EXPECT_TRUE(inMap); 

}

TEST(TestMapData,RetrievePositionFalse){

	float xPosition = 2.4; 
	float yPosition = 4.2; 
	float spaceInterval = .1; 
	float height = spaceInterval; 
	float width = spaceInterval;	
	ObstacleDimension2D dimension(height,width);
	DiscreteInterval2D interval(spaceInterval,dimension); 	
	ObstaclePosition2D position(xPosition,yPosition);
        float otherX = 2.33; 
     	float otherY = 2.3; 
	ObstaclePosition2D otherPosition(otherX,otherY);	
	MapData<ObstaclePosition2D,DiscreteInterval2D,MapTuple2D> mapData(interval); 
	mapData.add(position);
      	bool inMap = mapData.get(otherPosition);
	EXPECT_FALSE(inMap); 

}
