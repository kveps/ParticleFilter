#include <robot_state.h>

namespace rs{

RobotState::RobotState(double x, double y, double theta)
:
x_(x),
y_(y),
theta_(theta)
{
	utils_ = new utils::UtilFunctions();
}

void RobotState::setX(double x){
	x_ = x;
}

void RobotState::setY(double y){
	y_ = y;
}

void RobotState::setTheta(double theta){
	theta_ = theta;
}

double RobotState::x(){
	return x_;
}

double RobotState::y(){
	return y_;
}

double RobotState::theta(){
	return theta_;
}

RobotState* RobotState::rotate(double theta){

	RobotState* trans_state = new RobotState;
	
	Eigen::Vector3d vec(x_, y_, 0);	
	Eigen::Vector3d trans_vec = utils_->rotateVector(vec, theta);

	trans_state->setX(trans_vec[0]);
	trans_state->setY(trans_vec[1]);
	trans_state->setTheta(theta_);

	return trans_state;
}

} //namepsace