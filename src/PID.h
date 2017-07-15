#ifndef PID_H
#define PID_H

class PID {

private:
//
//  // Stores integrated cte over time.
//  double int_cte = 0;
//
//  // Stores previous cte.
//  double prev_cte = 0;


public:


  // Stores integrated cte over time.
  double int_cte = 0;

  // Stores previous cte.
  double prev_cte = 0;



  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
//  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
//  double TotalError();



  double calculateSteeringAngle(double cte);


};

#endif /* PID_H */
