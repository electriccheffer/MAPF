#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true); 

}

TEST(TestDimension,TestValidDimension){

	float height = .25; 
	float width = .25; 	
	std::vector<float> dimensionList = {height,width}; 
	ObstacleDimension2D dimension(height,width); 
	std::vector<float> dimensionResult = dimension.getDimension(); 
	EXPECT_EQ(dimensionList,dimensionResult);		
}

TEST(TestDimension,TestInvalidDimensionNegative){

	float height = -.25; 
	float width = -.25; 
	EXPECT_THROW({ObstacleDimension2D dimension(height,width);},ObstacleDimensionError);
}
