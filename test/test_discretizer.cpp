#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true); 

}


TEST(TestDiscretizer,GetObstacle){
	
	float positionX = .1; 
	float positionY = .2; 
	float height = .01; 
	float width = .01;
       	float space  = .01; 	
	ObstaclePosition2D position(positionX,positionY); 
	ObstacleDimension2D dimension(height,width);
	Obstacle2D obstacle(position,dimension); 
	DiscreteInterval2D interval(space,dimension); 
	ObstacleDiscretizer2D discretizer(obstacle,interval);
	EXPECT_EQ(discretizer.getObstacle(),obstacle); 
}


TEST(TestDiscretizer,GetInterval){
	
	float positionX = .1; 
	float positionY = .2; 
	float height = .01; 
	float width = .01;
       	float space  = .01; 	
	ObstaclePosition2D position(positionX,positionY); 
	ObstacleDimension2D dimension(height,width);
	Obstacle2D obstacle(position,dimension); 
	DiscreteInterval2D interval(space,dimension); 
	ObstacleDiscretizer2D discretizer(obstacle,interval);
	EXPECT_EQ(discretizer.getInterval(),interval); 
}
