#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

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

TEST(TestDimension,TestInvalidDimensionZero){

	float height = 0.00; 
	float width = 0.00; 
	EXPECT_THROW({ObstacleDimension2D dimension(height,width);},ObstacleDimensionError);
}

TEST(TestDimension,TestPrint){

	float height = .25; 
	float width = .25; 	
	ObstacleDimension2D dimension(height,width);
	std::cout << dimension << std::endl; 
}

TEST(TestDimension,TestEqualityTrue){

	float height = .25; 
	float width = .25; 	
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D otherDimension(height,width); 
	EXPECT_EQ(dimension,otherDimension);
}

TEST(TestDimension,TestEqualityFalse){

	float height = .25; 
	float width = .25; 
	float otherWidth = .5; 
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D otherDimension(height,otherWidth); 
	EXPECT_FALSE((dimension==otherDimension));
}

TEST(TestDimension,TestNonEqualityTrue){

	float height = .25; 
	float width = .25; 
	float otherWidth = .5; 
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D otherDimension(height,otherWidth); 
	EXPECT_NE(dimension,otherDimension);
}

TEST(TestDimension,TestNonEqualityFalse){

	float height = .25; 
	float width = .25; 
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D otherDimension(height,width); 
	EXPECT_FALSE((dimension!=otherDimension));
}

TEST(TestDimension,TestBadNumber){

	float height = .1; 
	float width = .1; 	
	ObstacleDimension2D dimension(height,width);
	ObstacleDimension2D otherDimension(height,width); 
	EXPECT_EQ(dimension,otherDimension);

}
