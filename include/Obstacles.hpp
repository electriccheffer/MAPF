#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP
#include <vector>
#include <iostream>

class ObstacleDimension{

	public:
		ObstacleDimension(const std::vector<float>& dimensions); 
		const std::vector<float>& getDimension()const; 
		void print(std::ostream& os)const; 
		bool operator==(const ObstacleDimension& otherDimension)const;
		bool operator!=(const ObstacleDimension& otherDimension)const;
	protected: 
		std::vector<float> dimensions; 
	

}; 

class ObstacleDimension2D : public ObstacleDimension{
	
	public: 
		ObstacleDimension2D(float height,float width); 
		bool operator==(const ObstacleDimension2D& otherDimension)const; 
	protected: 

}; 

class ObstacleDimension3D : public ObstacleDimension{
	
	public: 
		ObstacleDimension3D(float height,float width,float depth); 
		bool operator==(const ObstacleDimension3D& otherDimension)const;
	protected: 

};

class ObstaclePosition{

	public:
		ObstaclePosition(const std::vector<float>& positionCoordinates);
		const std::vector<float>& getPosition()const;
		void print(std::ostream& os)const; 
		bool operator==(const ObstaclePosition& otherPosition)const; 
		bool operator!=(const ObstaclePosition& otherPosition)const; 
	protected: 
		std::vector<float> positionCoordinates; 
}; 

class ObstaclePosition2D: public ObstaclePosition{
	
	public: 
		ObstaclePosition2D(float xPosition,float yPosition);
		bool operator==(const ObstaclePosition2D& otherPosition)const; 
		bool operator!=(const ObstaclePosition2D& otherPosition)const; 
	protected: 
}; 

class ObstaclePosition3D: public ObstaclePosition{
	
	public: 
		ObstaclePosition3D(float xPosition,float yPosition,float zPosition);
		bool operator==(const ObstaclePosition3D& otherPosition)const; 
		bool operator!=(const ObstaclePosition3D& otherPosition)const; 
	protected: 
};
std::ostream& operator<<(std::ostream& os,const ObstaclePosition2D& position);
std::ostream& operator<<(std::ostream& os,const ObstaclePosition3D& position);
std::ostream& operator<<(std::ostream& os,const ObstacleDimension2D& dimension);
std::ostream& operator<<(std::ostream& os,const ObstacleDimension3D& dimension);
#endif
