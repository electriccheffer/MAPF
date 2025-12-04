#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

TEST(TestAStar,TrivialTestAlwaysPasses){

	EXPECT_TRUE(true); 

}

TEST(TestAStar,TestHeuristic){

	float precision = .03f;
	ObstaclePosition2D position(0.0,0.0); 
	ObstaclePosition2D otherPosition(2.0,2.0); 
	SLDistanceHeuristic2D heuristic(position,otherPosition); 
	float distanceResult = heuristic.calculate(); 
	float distanceExpected = 2.82; 
	EXPECT_NEAR(distanceResult,distanceExpected,precision);

}

TEST(TestAStar,TestHeuristic3D){

	float precision = .03f;
	ObstaclePosition3D position(0.0,0.0,0.0); 
	ObstaclePosition3D otherPosition(2.0,2.0,2.0); 
	SLDistanceHeuristic3D heuristic(position,otherPosition); 
	float distanceResult = heuristic.calculate(); 
	float distanceExpected = 3.46; 
	EXPECT_NEAR(distanceResult,distanceExpected,precision);

}
