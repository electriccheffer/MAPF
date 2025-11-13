#include <gtest/gtest.h>
#include <vector>
#include <ostream>
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


TEST(PositionTest,TestPrinting){

	float xCoordinate = 1.0;
	float yCoordinate = 2.3; 
	std::vector<float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate);
	std::cout << position << std::endl;  	
}

TEST(PositionTest,TestAddition){
	
	float xPosition = 0.1; 
	float yPosition = 0.2;
	ObstaclePosition2D position(xPosition,yPosition); 
	
	float height = .1; 
	float width =.1; 
	ObstacleDimension2D dimension (width,height); 

	float xResult = .2; 
	float yResult = .3; 
	ObstaclePosition2D positionExpected(xResult,yResult); 
	
	ObstaclePosition2D positionResult = position + dimension; 
	EXPECT_EQ(positionExpected,positionResult); 
}
