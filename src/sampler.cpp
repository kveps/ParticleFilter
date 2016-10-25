#include <sampler.h>

namespace sp{

Sampler::Sampler(Map *map, int num_particles)
:
map_(map),
num_particles_(num_particles),
ang_res_(5)
{
	free_space_ = map_->getFreeSpace();
	constructFullFreeSpace();
}

void Sampler::constructFullFreeSpace(){

	for(int i = 0; i < free_space_.size(); i++){
		for(int j = 0; j < 360; j+=ang_res_){
			double ang = j*M_PI/180;
			full_free_space_.push_back(std::make_tuple(free_space_[i].first, free_space_[i].second, ang));
		}
	}
}

void Sampler::sampleUniform(std::vector<ps::ParticleState>& ps){

	std::random_device rd;
  std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dist(0, full_free_space_.size());

	for (int i = 0; i < num_particles_; i++){	
  	int num = dist(gen);
  	ParticleState p_state;
  	p_state.x(std::get<0>(full_free_space_[num]));
  	p_state.y(std::get<1>(full_free_space_[num]));
  	p_state.theta(std::get<2>(full_free_space_[num]));
    std::vector<int>* ranges = new std::vector<int> ();
    ranges->clear();
    p_state.setRanges(ranges);
    
    // std::cout << "Sampled point " << p_state.x() << " " << p_state.y() << " " << p_state.theta() << std::endl; 

  	p_state.weight(1.0);

  	ps.push_back(p_state);
	}
}

void Sampler::importanceResample(std::vector<ps::ParticleState> &ps)
  {

    std::vector <int> input_weights;

    for(std::vector<ps::ParticleState>::iterator it = ps.begin(); it != ps.end(); ++it) {
      input_weights.push_back(it->weight());
      //cout << it->weight();
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::discrete_distribution<> d(input_weights.begin(), input_weights.end());

    std::vector<ps::ParticleState> resampled_particles;

    for(int n=0; n<ps.size(); ++n) {
      //cout << d(gen) << endl;
      resampled_particles.push_back(ps[d(gen)]);
    }
    ps = resampled_particles;
  }

}