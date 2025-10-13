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
	std::vector<float,float> expectedPositionVector = {xCoordinate,yCoordinate}; 
	ObstaclePosition2D position(xCoordinate,yCoordinate); 
	std::vector<float,float> resultPositionVector = position.getPosition(); 
	EXPECT_EQ(expectedPositionVector,resultPositionVector); 
}
