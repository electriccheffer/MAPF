#include "../include/Map.hpp"
#include <cmath>
#include <iomanip>
#include <map>

MapTuple2D::MapTuple2D(ObstaclePosition2D& position,DiscreteInterval2D& interval):
	MapTuple(position,interval){}

long long MapTuple2D::getHash()const{

	std::vector<float> positions = this->position.getPosition();
	float space = this->interval.getSpace(); 	
	long long xIndex = static_cast<long long>(positions[0]/space); 
	long long yIndex = static_cast<long long>(positions[1]/space); 
	long long hashKey = xIndex * M_SHIFT_2 + yIndex; 
	return hashKey; 	
}

MapTuple3D::MapTuple3D(ObstaclePosition3D& position,DiscreteInterval3D& interval):
	MapTuple(position,interval){}

long long MapTuple3D::getHash()const{

	std::vector<float> positions = this->position.getPosition();
	float space = this->interval.getSpace(); 	
	long long xIndex = static_cast<long long>(positions[0]/space); 
	long long yIndex = static_cast<long long>(positions[1]/space); 
	long long zIndex = static_cast<long long>(positions[2]/space); 
	long long hashKey = xIndex * M_SHIFT_2 + yIndex*M_SHIFT_3 + zIndex; 
	return hashKey; 	
}

