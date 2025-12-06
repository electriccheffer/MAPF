#ifndef MAP_HPP
#define MAP_HPP
#include "Obstacles.hpp"
#include <cmath>
#include <map>

const long long M_SHIFT_2 = 65536; 
const long long M_SHIFT_3 = 4294967296LL;  

template<typename Position,typename Interval>
class MapTuple{

	public:
		MapTuple(Position& position,Interval& interval)
						:position(position),interval(interval){} 
		virtual long long getHash() const = 0; 
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
		long long getHash()const; 

};

class MapTuple3D:public MapTuple<ObstaclePosition3D,DiscreteInterval3D>{

	public:
		MapTuple3D(ObstaclePosition3D& position,DiscreteInterval3D& interval); 
		long long getHash()const;
}; 

template<typename Position,typename Interval,typename TupleType>
class MapData{

	public: 
		MapData(Interval& interval):interval(interval){} 
		
		bool get(Position& position){
			TupleType tuple(position,this->interval); 
			long long positionHash = tuple.getHash(); 
			if(this->obstacles[positionHash]){
				
				return true; 
			}
			return false; 
		} 

		
		void add(Position& position){
			TupleType tuple(position,this->interval);
			long long positionHash = tuple.getHash(); 
			this->obstacles[positionHash] = true; 	
		}

	protected: 
		std::map<long long,bool> obstacles;  		
		Interval& interval; 
}; 


#endif
