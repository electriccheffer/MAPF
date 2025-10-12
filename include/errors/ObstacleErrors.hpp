#ifndef OBSTACLE_ERRORS_HPP
#define OBSTACLE_ERRORS_HPP
#include <stdexcept>
#include <string>

class ObstacleDimensionError : public std::runtime_error{

	public: 
		explicit ObstacleDimensionError(const std::string& message):
		std::runtime_error("Obstacle Dimension Error:" + message),message(message){}
	private: 
		std::string message; 

}; 
#endif
