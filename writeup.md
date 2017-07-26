## PID Controller project

The purpose of this project was to implement a PID controller from scratch and develop a feel for what each of the P, I, and D components contribute to the control algorithm.

#### Describe the parameter effects


The P parameter stands for 'Proportional'. It is a coefficient multiplied in linear proportion to the cross track error (CTE from here on -- which is the distance between where the car currently is and the center of the track). A low P value will lead to light correction of the car towards the set point and a high P will result in very strong turning corrections.

Here is an example of a low P value of 0.01 with the I and D coefficients set to 0.
![](./movies/low%20p.gif)

<br>

And here is an example of a higher P coefficient around 5
![](./movies/high%20p.gif)


Note that when only P is used, the controller system results in oscillations. Slower oscillations for lower P values, and faster oscillations for higher P values.

<br>
<br>

Next is the D term. D stands for 'derivative' but some also refer to this term as the 'damping' term because of the effect this coefficient has on the system. The D coefficient is multiplied by the change in time of the CTE. If the CTE is changing quickly towards 0 (meaning the car is rapidly approaching the track center) this proportion will act in opposition to the P term, effectively slowing the rate of change so the car will stay close to 0 for CTE. Thus, the D term acts as a damping of the oscillations that the P term introduces. The clip below shows that when a fairly high D value of 30 is used, it does not allow the car to oscillate around the center line, resulting in a more controlled car motion.

![](./movies/D%20added.gif)

<br>
<br>

Finally is the I term. I stands for 'integral' and is a coefficient multiplied by the integral over time of the CTE. This will correct for any long term drifting away from the track center. In the clip below I have added a small I term of 0.01 which resluts in the car keeping noticeably better position towards the center of the track.

![](./movies/I%20added.gif)

With all terms added together, and in proper proportion, the car pulls strongly towards the set point (P); has litle or no oscillation about the set point (D); and eliminates any offset over time (I).


<br>
<br>

#### Describe how the final parameters were chosen

I chose to do a manual process, as I wanted to develop a 'feel' for the parameter values. I probably tried a hundred different combinations, doing a human driven version of the 'twiddle' algorithm Sebastian discussed.

I started with P. I tried to find a value that would pull decently towards the center, but also not result in only +-25 degree values for steering sent back to the simulator. I then dialed in more and more D until the system became too twitchy and unstable. Higher D values also allowed slightly higher P while still staying stable.

I then added a bit of I. I found that too much I (more than about 0.01) resulted in strange overshoots of the car when it was going around tight corners. A smaller value allows the car to swing side to side in the lane a bit, but still drives the car towards the center during the straight sections of the track.
