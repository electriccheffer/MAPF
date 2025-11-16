#ifndef OBSTACLES_HPP
#define OBSTACLES_HPP
#include <vector>
#include <iostream>
#include <cmath>

static constexpr float EPS = 1e-6f;

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
		bool operator!=(const ObstacleDimension2D& otherDimension)const;
	protected: 

}; 

class ObstacleDimension3D : public ObstacleDimension{
	
	public: 
		ObstacleDimension3D(float height,float width,float depth); 
		bool operator==(const ObstacleDimension3D& otherDimension)const;
		bool operator!=(const ObstacleDimension3D& otherDimension)const;
	protected: 

};
template<typename SomePosition,typename SomeDimension>
class ObstaclePosition{

	public:
		ObstaclePosition(const std::vector<float>& positionCoordinates)
						:positionCoordinates(positionCoordinates){}

	const std::vector<float>& getPosition()const{

		return this->positionCoordinates; 
	} 

	void print(std::ostream& os)const{
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


	bool operator==(const ObstaclePosition& otherPosition)const{
		
		std::vector<float> otherPositionVector = otherPosition.getPosition(); 
		unsigned int otherPositionVectorSize = otherPositionVector.size(); 

		for(unsigned int index = 0 ; index < otherPositionVectorSize ; index++ ){
			if(std::fabs(this->positionCoordinates[index]-otherPositionVector[index]) > EPS){
				return false; 
			}
		}
		return true; 
	}

	bool operator!=(const ObstaclePosition& otherPosition)const{

		return !(*this == otherPosition); 
	}

	SomePosition operator+(const SomeDimension& dimension)const{
	
		std::vector<float> dimensionVectors = dimension.getDimension(); 
		int dimensionLength = dimensionVectors.size(); 
		std::vector<float> positionVectorResult; 
		for(int index = 0 ; index < dimensionLength  ; index++){
			
			positionVectorResult.push_back(this->positionCoordinates[index] + 
							dimensionVectors[index]); 
		}	
		SomePosition resultPosition(positionVectorResult);
		return resultPosition; 
	}

	protected: 
		std::vector<float> positionCoordinates; 
}; 

class ObstaclePosition2D: public ObstaclePosition<ObstaclePosition2D,ObstacleDimension2D>{
	
	public:
		ObstaclePosition2D(const std::vector<float>& positions); 
		ObstaclePosition2D(float xPosition,float yPosition);
		bool operator==(const ObstaclePosition2D& otherPosition)const; 
		bool operator!=(const ObstaclePosition2D& otherPosition)const; 
		ObstaclePosition2D operator+(const ObstacleDimension2D& dimension)const;
	protected: 
}; 

class ObstaclePosition3D: public ObstaclePosition<ObstaclePosition3D,ObstacleDimension3D>{
	
	public: 
		ObstaclePosition3D(const std::vector<float>& positions); 
		ObstaclePosition3D(float xPosition,float yPosition,float zPosition);
		bool operator==(const ObstaclePosition3D& otherPosition)const; 
		bool operator!=(const ObstaclePosition3D& otherPosition)const; 
		ObstaclePosition3D operator+(const ObstacleDimension3D& dimension)const;
	protected: 
};

template<typename Derived, typename DimensionType, typename PositionType>
class Obstacle{

	public:
		Obstacle(const PositionType& position,const DimensionType& dimension)
						:position(position),dimension(dimension){}
		const DimensionType& getDimension()const{return this->dimension;}
		const PositionType& getPosition()const{return this->position;}
		void print(std::ostream& os)const{
		
			os << "Obstacle Data:"; 
			os << this->position;
		       	os << ";";	
			os << this->dimension;	
		
		}
		bool operator==(const Obstacle& otherObstacle)const{
			if(this->dimension != otherObstacle.getDimension()){
			
				return false; 
			}
			if(this->position != otherObstacle.getPosition()){
			
				return false;
			}
			return true;
		}
		bool operator!=(const Obstacle& otherObstacle)const{
			return !(*this == otherObstacle); 	
		}
	protected: 
		PositionType position; 
		DimensionType dimension; 
};

class Obstacle2D : public Obstacle<Obstacle2D,ObstacleDimension2D,ObstaclePosition2D>{

	public:
	 	Obstacle2D(const ObstaclePosition2D& position,const ObstacleDimension2D& dimension); 
		bool operator==(const Obstacle2D& otherPostion)const;
		bool operator!=(const Obstacle2D& otherPostion)const;
	protected:

};

class Obstacle3D : public Obstacle<Obstacle3D,ObstacleDimension3D,ObstaclePosition3D>{

	public:
	 	Obstacle3D(const ObstaclePosition3D& position,const ObstacleDimension3D& dimension); 
		bool operator==(const Obstacle3D& otherPostion)const;
		bool operator!=(const Obstacle3D& otherPostion)const;
	protected:

};

template<typename T>
class DiscreteInterval{

	public:
	       	DiscreteInterval(float space,T& dimension)
							:space(space),dimension(dimension){} 	
		const float getSpace()const{return this->space;}
		const T& getDimension()const{return this->dimension;}
		bool operator==(const DiscreteInterval& otherInterval)const{
			if(this->space != otherInterval.getSpace()){
			
				return false; 
			}
			if(this->dimension != otherInterval.getDimension()){
			
				return false; 
			}
			return true; 
		}
		bool operator!=(const DiscreteInterval& otherInterval)const{
			return !(*this == otherInterval); 
		}
		void print(std::ostream& os)const{
		
			os << "Interval Size:"; 
			os << this->space;
		       	os << ";";	
			os << this->dimension;	
		
		}
	protected:
		float space; 
		T dimension;
}; 


class DiscreteInterval2D:public DiscreteInterval<ObstacleDimension2D>{

	public: 
		DiscreteInterval2D(float space, ObstacleDimension2D& dimension); 
		bool operator==(const DiscreteInterval2D& otherInterval)const; 
		bool operator!=(const DiscreteInterval2D& otherInterval)const; 
		
}; 

class DiscreteInterval3D:public DiscreteInterval<ObstacleDimension3D>{

	public: 
		DiscreteInterval3D(float space, ObstacleDimension3D& dimension); 
		bool operator==(const DiscreteInterval3D& otherInterval)const;
		bool operator!=(const DiscreteInterval3D& otherInterval)const; 
}; 

class ObstacleDiscretizer2D{

	public: 
		ObstacleDiscretizer2D(Obstacle2D& obstacle,DiscreteInterval2D& interval);
		Obstacle2D& getObstacle(); 
		DiscreteInterval2D& getInterval(); 
	protected:
		Obstacle2D& obstacle; 
		DiscreteInterval2D& interval; 
		std::vector<ObstaclePosition2D> makeEdge(ObstaclePosition2D& start,
							ObstacleDimension2D& unit,	
							ObstaclePosition2D& endPoint); 
		

}; 


std::ostream& operator<<(std::ostream& os,const ObstaclePosition2D& position);
std::ostream& operator<<(std::ostream& os,const ObstaclePosition3D& position);
std::ostream& operator<<(std::ostream& os,const ObstacleDimension2D& dimension);
std::ostream& operator<<(std::ostream& os,const ObstacleDimension3D& dimension);
std::ostream& operator<<(std::ostream& os,const Obstacle2D& obstacle);
std::ostream& operator<<(std::ostream& os,const Obstacle3D& obstacle);
std::ostream& operator<<(std::ostream& os, const DiscreteInterval2D& interval); 
std::ostream& operator<<(std::ostream& os, const DiscreteInterval3D& interval);
#endif
