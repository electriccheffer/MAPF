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

#endif
