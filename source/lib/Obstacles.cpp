#include "../../include/Obstacles.hpp"
#include "../../include/errors/ObstacleErrors.hpp"

ObstacleDimension::ObstacleDimension(const std::vector<float>& dimensions):dimensions(dimensions){}

std::vector<float>& ObstacleDimension::getDimension(){

	return this->dimensions; 
}

ObstacleDimension2D::ObstacleDimension2D(float height, float width):
					ObstacleDimension({height,width}){

	if(height <=  0.00 || width <= 0.00){
	
		throw ObstacleDimensionError("dimensions may not be zero or negative");
	
	}	
}

ObstacleDimension3D::ObstacleDimension3D(float height, float width, float depth):
					ObstacleDimension({height,width,depth}){

	if(height <=  0.00 || width <= 0.00 || depth <= 0.00){
	
		throw ObstacleDimensionError("dimensions may not be zero or negative");
	
	}

}


ObstaclePosition::ObstaclePosition(const std::vector<float>& positionCoordinates)
					:positionCoordinates(positionCoordinates){}

std::vector<float>& ObstaclePosition::getPosition(){

	return this->positionCoordinates; 
} 

ObstaclePosition2D::ObstaclePosition2D(float xCoordinate, float yCoordinate):
					ObstaclePosition({xCoordinate,yCoordinate}){}

ObstaclePosition3D::ObstaclePosition3D(float xPosition, float yPosition,float zPosition):
					ObstaclePosition({xPosition,yPosition,zPosition}){}

