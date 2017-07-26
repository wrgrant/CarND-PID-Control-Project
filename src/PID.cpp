#include "PID.h"

//using namespace std;

PID::PID() {}

PID::~PID() {}




//void PID::UpdateError(double cte) {
//}

//double PID::TotalError() {
//}


void PID::init(double Kp_in, double Ki_in, double Kd_in) {
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
}


double PID::calculateSteeringAngle(double cte) {

  double diff_cte = cte - prev_cte;
  prev_cte = cte;
  int_cte += cte;

  // Force int_cte to shrink over time.
  int_cte *= 0.9;

  p_error = -Kp * cte;
  i_error = -Ki * int_cte;
  d_error = -Kd * diff_cte;

  return p_error + i_error + d_error;

}
