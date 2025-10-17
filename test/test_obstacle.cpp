#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true); 

}

TEST(ObstacleTest,TestGetDimension){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 

	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 
	ObstacleDimension2D dimensionResult = obstacle.getDimension();  
	std::cout<<dimension<<std::endl; 
	std::cout<<dimensionResult<<std::endl;
	EXPECT_EQ(dimension,dimensionResult); 
}

TEST(ObstacleTest,TestGetPosition){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 

	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 

	const ObstaclePosition2D& positionResult = obstacle.getPosition();  
	EXPECT_EQ(position,positionResult); 
}

TEST(ObstacleTest,TestEqualityTrue){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 

	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 
	Obstacle2D otherObstacle(position,dimension); 
	EXPECT_EQ(obstacle,otherObstacle); 
}

TEST(ObstacleTest,TestEqualityFalse){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 
	float otherHeight = .5; 
	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 
	ObstacleDimension2D otherDimension (otherHeight,width); 
	Obstacle2D otherObstacle(position,otherDimension); 
	EXPECT_FALSE((obstacle==otherObstacle)); 
}

TEST(ObstacleTest,TestNonEqualityFalse){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 
	float otherHeight = .5; 
	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 
	ObstacleDimension2D otherDimension (otherHeight,width); 
	Obstacle2D otherObstacle(position,otherDimension); 
	EXPECT_NE(obstacle,otherObstacle); 
}

TEST(ObstacleTest,TestNonEqualityTrue){

	float xPosition = 1.0;
	float yPosition = 2.0; 
	float width = .25; 
	float height = .25; 

	ObstacleDimension2D dimension(width,height);
	ObstaclePosition2D position(xPosition,yPosition);
	Obstacle2D obstacle(position,dimension); 
	Obstacle2D otherObstacle(position,dimension); 
	EXPECT_FALSE((obstacle!=otherObstacle)); 
}


