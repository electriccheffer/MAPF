#include "../../include/Obstacles.hpp"


ObstacleDimension::ObstacleDimension(const std::vector<float>& dimensions):dimensions(dimensions){}

std::vector<float>& ObstacleDimension::getDimension(){

	return this->dimensions; 
}

ObstacleDimension2D::ObstacleDimension2D(float height, float width):
					ObstacleDimension({height,width}){


}

ObstacleDimension3D::ObstacleDimension3D(float height, float width, float depth):
					ObstacleDimension({height,width,depth}){



}
