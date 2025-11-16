#include "../../include/Obstacles.hpp"
#include <vector>

class ObstacleDiscretizer2DSubclass : public ObstacleDiscretizer2D{

	public:

		ObstacleDiscretizer2DSubclass(Obstacle2D& obstacle,
						DiscreteInterval2D& interval)
						:ObstacleDiscretizer2D(obstacle,interval){}

		std::vector<ObstaclePosition2D> 
				makeEdgeTestAccess(ObstaclePosition2D& start,
						ObstacleDimension2D& unit,
						ObstaclePosition2D& endPoint){
			
					return this->makeEdge(start,unit,endPoint);
			
			} 

};

