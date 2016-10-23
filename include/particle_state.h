#ifndef PARTICLE_STATE_H
#define PARTICLE_STATE_H

#include <standard_includes.h>
#include <util_functions.h>

#include <robot_state.h>

using namespace rs;

namespace ps{

	class ParticleState{

	public:

		ParticleState(){}
		ParticleState(double x, double y, double theta, double weight);
		ParticleState(RobotState robot_state, double weight);

		void x(double x);
		void y(double y);
		void theta(double theta);
		void robot_state(RobotState robot_state);
		void weight(double weight);
		double x();
		double y();
		double theta();		
		RobotState robot_state();
		double weight();
		
		ParticleState rotate(double theta);

	private:

		RobotState robot_state_;
		double x_;
		double y_;
		double theta_;
		double weight_;

		utils::UtilFunctions *utils_;

	};
}

#endif