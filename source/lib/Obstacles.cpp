#include "../../include/Obstacles.hpp"
#include "../../include/errors/ObstacleErrors.hpp"

ObstacleDimension::ObstacleDimension(const std::vector<float>& dimensions):dimensions(dimensions){}

const std::vector<float>& ObstacleDimension::getDimension()const{

	return this->dimensions; 
}

bool ObstacleDimension::operator==(const ObstacleDimension& otherDimension)const{

	unsigned int dimension = this->dimensions.size(); 
	std::vector<float> otherDimensionVector = otherDimension.getDimension(); 
	for(int index = 0 ; index < dimension ; index++){
	
		if(this->dimensions[index] != otherDimensionVector[index]){
		
			return false; 
		}
	
	}
	return true;	
}

bool ObstacleDimension::operator!=(const ObstacleDimension& otherDimension)const{
	
	return !(*this == otherDimension);

}

void ObstacleDimension::print(std::ostream& os)const{
	
	unsigned int dimension = this->dimensions.size(); 

	os << "Obstacle Dimensions: ("; 
	for(unsigned int index = 0;index < dimension;index++){
		
		if(index == dimension-1){
			os << this->dimensions[index];
			os << ")";  
			return; 
		}
		os << this->dimensions[index] << ", "; 
	}	

}

ObstacleDimension2D::ObstacleDimension2D(float height, float width):
					ObstacleDimension({height,width}){

	if(height <=  0.00 || width <= 0.00){
	
		throw ObstacleDimensionError("dimensions may not be zero or negative");
	
	}	
}

bool ObstacleDimension2D::operator==(const ObstacleDimension2D& otherDimension)const{

	return ObstacleDimension::operator==(otherDimension); 

}

bool ObstacleDimension2D::operator!=(const ObstacleDimension2D& otherDimension)const{

	return ObstacleDimension::operator!=(otherDimension); 
}

std::ostream& operator<<(std::ostream& os,const ObstacleDimension2D& dimension){
	dimension.print(os);
	return os; 
}



ObstacleDimension3D::ObstacleDimension3D(float height, float width, float depth):
					ObstacleDimension({height,width,depth}){

	if(height <=  0.00 || width <= 0.00 || depth <= 0.00){
	
		throw ObstacleDimensionError("dimensions may not be zero or negative");
	
	}

}

bool ObstacleDimension3D::operator==(const ObstacleDimension3D& otherDimension)const{

	return ObstacleDimension::operator==(otherDimension); 

}

bool ObstacleDimension3D::operator!=(const ObstacleDimension3D& otherDimension)const{

	return ObstacleDimension::operator!=(otherDimension); 
}

std::ostream& operator<<(std::ostream& os,const ObstacleDimension3D& dimension){
	dimension.print(os);
	return os; 
}

ObstaclePosition::ObstaclePosition(const std::vector<float>& positionCoordinates)
					:positionCoordinates(positionCoordinates){}

const std::vector<float>& ObstaclePosition::getPosition()const{

	return this->positionCoordinates; 
} 

void ObstaclePosition::print(std::ostream& os)const{
	unsigned int positionDimension = this->positionCoordinates.size();
	os << "Obstacle Position: ("; 
	for(unsigned int index = 0 ; index < positionDimension;index++ ){
		
		if(index == positionDimension-1){
			os << this->positionCoordinates[index];
			os << ")";  
			return; 
		}
		os << this->positionCoordinates[index] << ", "; 
	}	

}


bool ObstaclePosition::operator==(const ObstaclePosition& otherPosition)const{
	
	std::vector<float> otherPositionVector = otherPosition.getPosition(); 
	unsigned int otherPositionVectorSize = otherPositionVector.size(); 

	for(unsigned int index = 0 ; index < otherPositionVectorSize ; index++ ){
		if(otherPositionVector[index] != this->positionCoordinates[index]){
			return false; 
		}
	}
	return true; 
}

bool ObstaclePosition::operator!=(const ObstaclePosition& otherPosition)const{

	return !(*this == otherPosition); 
}

ObstaclePosition2D::ObstaclePosition2D(float xCoordinate, float yCoordinate):
					ObstaclePosition({xCoordinate,yCoordinate}){}

std::ostream& operator<<(std::ostream& os,const ObstaclePosition2D& position){
	position.print(os);
	return os; 
}

bool ObstaclePosition2D::operator==(const ObstaclePosition2D& otherPosition)const{
	
	return ObstaclePosition::operator==(otherPosition);  
}

bool ObstaclePosition2D::operator!=(const ObstaclePosition2D& otherPosition)const{

	return ObstaclePosition::operator!=(otherPosition); 
}

ObstaclePosition3D::ObstaclePosition3D(float xPosition, float yPosition,float zPosition):
					ObstaclePosition({xPosition,yPosition,zPosition}){}

std::ostream& operator<<(std::ostream& os,const ObstaclePosition3D& position){
	position.print(os);
	return os; 
}

bool ObstaclePosition3D::operator==(const ObstaclePosition3D& otherPosition)const{
	return ObstaclePosition::operator==(otherPosition);	
}

bool ObstaclePosition3D::operator!=(const ObstaclePosition3D& otherPosition)const{

	return ObstaclePosition::operator!=(otherPosition); 
}
