#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP
#include <vector>

class ObstacleDimension{

	public:
		ObstacleDimension(const std::vector<float>& dimensions); 
		std::vector<float>& getDimension(); 
	protected: 
		std::vector<float> dimensions; 
	

}; 

class ObstacleDimension2D : public ObstacleDimension{
	
	public: 
		ObstacleDimension2D(float height,float width); 
	protected: 

}; 

class ObstacleDimension3D : public ObstacleDimension{
	
	public: 
		ObstacleDimension3D(float height,float width,float depth); 
	protected: 

};

class ObstaclePosition{

	public:
		ObstaclePosition(const std::vector<float>& positionCoordinates);
		std::vector<float>& getPosition(); 
	protected: 
		std::vector<float> positionCoordinates; 
}; 

class ObstaclePosition2D: public ObstaclePosition{
	
	public: 
		ObstaclePosition2D(float xPosition,float yPosition);
	protected: 
}; 

class ObstaclePosition3D: public ObstaclePosition{
	
	public: 
		ObstaclePosition3D(float xPosition,float yPosition,float zPosition);
	protected: 
}; 
#endif
