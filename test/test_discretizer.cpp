#include <gtest/gtest.h>
#include <vector>
#include "../include/Obstacles.hpp"
#include "../include/errors/ObstacleErrors.hpp"
#include <iostream>
std::vector<ObstaclePosition2D> descretePointsFactory();

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

std::vector<ObstaclePosition2D> descretePointsFactory(){
	std::vector<ObstaclePosition2D> points = {
		
		ObstaclePosition2D(0.0,0.0),ObstaclePosition2D(.01,0.0),
		ObstaclePosition2D(.02,0.0),ObstaclePosition2D(.03,0.0),
		ObstaclePosition2D(.04,0.0),ObstaclePosition2D(.05,0.0),
		ObstaclePosition2D(.06,0.0),ObstaclePosition2D(.07,0.0),
		ObstaclePosition2D(.08,0.0),ObstaclePosition2D(.09,0.0),
		ObstaclePosition2D(.1,0.0),
		ObstaclePosition2D(.1,0.01),
		ObstaclePosition2D(.1,0.02),ObstaclePosition2D(.1,0.03),
		ObstaclePosition2D(.1,0.04),ObstaclePosition2D(.1,0.05),
		ObstaclePosition2D(.1,0.06),ObstaclePosition2D(.1,0.07),
		ObstaclePosition2D(.1,0.08),ObstaclePosition2D(.1,0.09),
		ObstaclePosition2D(.1,.1),
		ObstaclePosition2D(0.0,.01),ObstaclePosition2D(0.0,.02),
		ObstaclePosition2D(0.0,.03),ObstaclePosition2D(0.0,.04),
		ObstaclePosition2D(0.0,.05),ObstaclePosition2D(0.0,.06),
		ObstaclePosition2D(0.0,.07),ObstaclePosition2D(0.0,.08),
		ObstaclePosition2D(0.0,.09),
		ObstaclePosition2D(0.0,0.1),
		ObstaclePosition2D(.01,.1),ObstaclePosition2D(.02,.1),
		ObstaclePosition2D(.03,.1),ObstaclePosition2D(.04,.1),
		ObstaclePosition2D(.05,.1),ObstaclePosition2D(.06,.1),
		ObstaclePosition2D(.07,.1),ObstaclePosition2D(.08,.1),
		ObstaclePosition2D(.09,.1)
	}; 

	return points;  


}

