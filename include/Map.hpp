#ifndef MAP_HPP
#define MAP_HPP
#include "Obstacles.hpp"
#include <cmath>

template<typename Position,typename Interval>
class MapTuple{

	public:
		MapTuple(Position& position,Interval& interval)
						:position(position),interval(interval){} 
	protected:
		Position lowerBound(){
			
			float space = this->interval.getSpace(); 
			std::vector<float> truncatedPositions; 
			std::vector<float> obstaclePositions = this->position.getPosition(); 
			int length = obstaclePositions.size(); 
			for(int index = 0 ; index < length ; index++){
			
				float truncatedDimension = std::trunc(
						obstaclePositions[index]/space) * space; 
				truncatedPositions.push_back(truncatedDimension);	
			}

			return Position(truncatedPositions); 
		}

		Position& position; 
		Interval& interval; 	


}; 

class MapTuple2D:public MapTuple<ObstaclePosition2D,DiscreteInterval2D>{

	public:
		MapTuple2D(ObstaclePosition2D& position,DiscreteInterval2D& interval); 
	protected: 
};

class MapTuple3D:public MapTuple<ObstaclePosition3D,DiscreteInterval3D>{

	public:
	protected: 
}; 

#endif
