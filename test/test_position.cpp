#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true); 

}

TEST(PositionTest,NormalCase){

	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate); 
	std::vector<float> resultPositionVector = position.getPosition(); 
	EXPECT_EQ(expectedPositionVector,resultPositionVector); 
}

TEST(PositionTest,EqualityTestTrue){
	
	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate);
	ObstaclePosition2D otherPosition(xCoordinate,yCoordinate); 
	EXPECT_EQ(position,otherPosition); 
}

TEST(PositionTest,EqualityTestFalse){
	
	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	float otherXCoordinate = 1.3; 
	float otherYCoordinate = -1.2; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate);
	ObstaclePosition2D otherPosition(otherXCoordinate,otherYCoordinate); 
	EXPECT_FALSE((position==otherPosition));

}

TEST(PositionTest,NonEqualityTestNotEqual){	
	
	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	float otherXCoordinate = 1.3; 
	float otherYCoordinate = -1.2; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate);
	ObstaclePosition2D otherPosition(otherXCoordinate,otherYCoordinate); 
	EXPECT_NE(position,otherPosition);
}

TEST(PositionTest,NonEqualityTestEqual){	
	
	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate);
	ObstaclePosition2D otherPosition(xCoordinate,yCoordinate); 
	EXPECT_FALSE((position!=otherPosition));
}


