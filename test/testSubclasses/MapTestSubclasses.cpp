#include "../../include/Map.hpp"
#include "../../include/Obstacles.hpp"

class TestMapTuple2D:public MapTuple2D{

	public:
		TestMapTuple2D(ObstaclePosition2D& position, DiscreteInterval2D& interval)
			:MapTuple2D(position,interval){}
		ObstaclePosition2D getFloor(){
		
			return this->lowerBound(); 		
		}			

};
