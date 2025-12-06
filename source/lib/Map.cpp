#include "../include/Map.hpp"
#include <cmath>
#include <iomanip>

MapTuple2D::MapTuple2D(ObstaclePosition2D& position,DiscreteInterval2D& interval):
	MapTuple(position,interval){}

long long MapTuple2D::getHash(){

	std::vector<float> positions = this->position.getPosition();
	float space = this->interval.getSpace(); 	
	long long xIndex = static_cast<long long>(positions[0]/space); 
	long long yIndex = static_cast<long long>(positions[1]/space); 
	long long hashKey = xIndex * M_SHIFT_2 + yIndex; 
	return hashKey; 	
}
