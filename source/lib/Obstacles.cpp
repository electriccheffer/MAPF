#include "../../include/Obstacles.hpp"
#include "../../include/errors/ObstacleErrors.hpp"
#include <cmath>
#include <algorithm>

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

	if(height ==  0.00 && width == 0.00){
	
		throw ObstacleDimensionError("dimensions may not be zero or negative");
	
	}	

	if(height <  0.00 || width < 0.00){
	
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

ObstaclePosition2D::ObstaclePosition2D(const std::vector<float>& positions)
							:ObstaclePosition(positions){
							
	if(positions.size() != 2){
	
		throw new ObstaclePositionError("position 2D array must be of length 2"); 
	}						
								
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

ObstaclePosition2D ObstaclePosition2D::operator+(const ObstacleDimension2D& dimension)const{

	return ObstaclePosition::operator+(dimension); 

}

ObstaclePosition3D::ObstaclePosition3D(float xPosition, float yPosition,float zPosition):
					ObstaclePosition({xPosition,yPosition,zPosition}){}

ObstaclePosition3D::ObstaclePosition3D(const std::vector<float>& positions)
							:ObstaclePosition(positions){
							
	if(positions.size() != 3){
	
		throw new ObstaclePositionError("position 3D array must be of length 3"); 
	}						
								
}

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

ObstaclePosition3D ObstaclePosition3D::operator+(const ObstacleDimension3D& dimension)
										const{
										
	return ObstaclePosition::operator+(dimension); 
										
}

Obstacle2D::Obstacle2D(const ObstaclePosition2D& position,const ObstacleDimension2D& dimension):Obstacle(position,dimension){}

bool Obstacle2D::operator==(const Obstacle2D& otherObstacle)const{
	
	return Obstacle::operator==(otherObstacle);
}

bool Obstacle2D::operator!=(const Obstacle2D& otherObstacle)const{
	
	return Obstacle::operator!=(otherObstacle);
}

std::ostream& operator<<(std::ostream& os,const Obstacle2D& obstacle){
	
	obstacle.print(os);
	return os; 
}

Obstacle3D::Obstacle3D(const ObstaclePosition3D& position,const ObstacleDimension3D& dimension):Obstacle(position,dimension){}

bool Obstacle3D::operator==(const Obstacle3D& otherObstacle)const{
	
	return Obstacle::operator==(otherObstacle);
}

bool Obstacle3D::operator!=(const Obstacle3D& otherObstacle)const{
	
	return Obstacle::operator!=(otherObstacle);
}


std::ostream& operator<<(std::ostream& os,const Obstacle3D& obstacle){

	obstacle.print(os);
	return os; 
}

DiscreteInterval2D::DiscreteInterval2D(float space, ObstacleDimension2D& dimension)
					:DiscreteInterval(space,dimension){}

bool DiscreteInterval2D::operator==(const DiscreteInterval2D& otherInterval)const{

	return DiscreteInterval::operator==(otherInterval); 
}

bool DiscreteInterval2D::operator!=(const DiscreteInterval2D& otherInterval)const{

	return DiscreteInterval::operator!=(otherInterval); 
}

std::ostream& operator<<(std::ostream& os, const DiscreteInterval2D& interval){

	interval.print(os); 
	return os; 
}

DiscreteInterval3D::DiscreteInterval3D(float space, ObstacleDimension3D& dimension)
					:DiscreteInterval(space,dimension){}

bool DiscreteInterval3D::operator==(const DiscreteInterval3D& otherInterval)const{

	return DiscreteInterval::operator==(otherInterval); 
}

bool DiscreteInterval3D::operator!=(const DiscreteInterval3D& otherInterval)const{

	return DiscreteInterval::operator!=(otherInterval); 
}

std::ostream& operator<<(std::ostream& os, const DiscreteInterval3D& interval){

	interval.print(os); 
	return os; 
}


ObstacleDiscretizer2D::ObstacleDiscretizer2D(Obstacle2D& obstacle,
					DiscreteInterval2D& interval)
						:obstacle(obstacle),interval(interval){}

Obstacle2D& ObstacleDiscretizer2D::getObstacle(){

	return this->obstacle; 
}

DiscreteInterval2D& ObstacleDiscretizer2D::getInterval(){

	return this->interval;
}


std::vector<ObstaclePosition2D> ObstacleDiscretizer2D::makeEdge(ObstaclePosition2D& start,
							ObstacleDimension2D& unit,
							ObstaclePosition2D& endPoint){
	
    std::vector<ObstaclePosition2D> positions;

    float sx = start.getPosition()[0];
    float sy = start.getPosition()[1];
    float ex = endPoint.getPosition()[0];
    float ey = endPoint.getPosition()[1];

    float ux = unit.getDimension()[0];
    float uy = unit.getDimension()[1];

    int steps = 0;

    if (std::fabs(ux) > 1e-12f) {
        steps = std::round((ex - sx) / ux);
    } else {
        steps = std::round((ey - sy) / uy);
    }

    for (int i = 1; i < steps; ++i) {
        positions.emplace_back(sx + ux * i, sy + uy * i);
    }
    int len = positions.size(); 
    	
    return positions;	

}


std::vector<ObstaclePosition2D> ObstacleDiscretizer2D::getDiscreteObject(){

	std::vector<ObstaclePosition2D> discretePoints; 
	
	ObstaclePosition2D startPosition = this->obstacle.getPosition(); 
	
	ObstacleDimension2D obstacleDimension = this->obstacle.getDimension(); 
	ObstacleDimension2D robotDimension = this->interval.getDimension(); 
	ObstacleDimension2D horizontalMaxDimension(obstacleDimension.getDimension()[0]
						   + robotDimension.getDimension()[0] ,
						   0.0); 	
	ObstacleDimension2D verticalMaxDimension(0.0 ,obstacleDimension.getDimension()[1]
						       + robotDimension.getDimension()[1]);

	ObstacleDimension2D horizontalUnit(this->interval.getSpace(),0.0); 
	ObstacleDimension2D verticalUnit(0.0,this->interval.getSpace());

	ObstaclePosition2D southEastMax = (startPosition + horizontalMaxDimension); 	
	std::cout << "SOUTHEAST MAX: " << southEastMax << std::endl; 
	ObstaclePosition2D northEastMax = (southEastMax + verticalMaxDimension);
	std::cout << "NORTHEAST MAX: " << northEastMax << std::endl; 
	ObstaclePosition2D northWestMax = (startPosition + verticalMaxDimension); 
	std::cout << "NORTHWEST MAX: " << northWestMax << std::endl; 
	
	//calculate bottom
	discretePoints.push_back(startPosition); 
	std::vector<ObstaclePosition2D> horizontalPostions = this->makeEdge(startPosition,
							     horizontalUnit, southEastMax);
	discretePoints.insert(discretePoints.end(),
				horizontalPostions.begin(),
				horizontalPostions.end()); 
	//calculate horizontal-vertical
	discretePoints.push_back(southEastMax);
	std::vector<ObstaclePosition2D> horizontalVerticalPostions = makeEdge(southEastMax,
							     verticalUnit, northEastMax);
	discretePoints.insert(discretePoints.end(),
				horizontalVerticalPostions.begin(),
				horizontalVerticalPostions.end()); 

		
	//calculate vertical
	discretePoints.push_back(northEastMax);
	std::vector<ObstaclePosition2D> verticalPostions = makeEdge(startPosition,
							     verticalUnit, northWestMax);
	discretePoints.insert(discretePoints.end(),
				verticalPostions.begin(),
				verticalPostions.end()); 

	discretePoints.push_back(northWestMax);

	//calcualte vertical-horizontal
	std::vector<ObstaclePosition2D> verticalHorizontalPostions = makeEdge(northWestMax,
							     horizontalUnit, northEastMax);
	discretePoints.insert(discretePoints.end(),
				verticalHorizontalPostions.begin(),
				verticalHorizontalPostions.end()); 

	return discretePoints; 
		
}

SLDistanceHeuristic2D::SLDistanceHeuristic2D(ObstaclePosition2D& position, 
					ObstaclePosition2D& otherPosition):
					SLDistanceHeuristic<ObstaclePosition2D>
							(position,otherPosition){
	

}

SLDistanceHeuristic3D::SLDistanceHeuristic3D(ObstaclePosition3D& position, 
					ObstaclePosition3D& otherPosition):
						SLDistanceHeuristic(position,otherPosition){
	

}
