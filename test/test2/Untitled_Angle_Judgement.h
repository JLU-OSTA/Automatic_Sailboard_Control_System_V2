//double aggKp1=0.8, aggKi1=1.2, aggKd1=0.1;
void angle_judgement()
{
	if(abs(ang-aimarr[forward])<adjust_range)
    {
        bingo++;
        //aggKp0=1, aggKi0=1.8, aggKd0=0.03;
        if(bingo==200)
        {
		        digitalWrite(beep,HIGH);
            if(timer==0)
            {
                timer=1;
                last_time_un=millis();
            }
            bingo=1;
        }
    }
    else
    {
      //if(in%50==0)
          //aggKp0=1.2, aggKi0=0.8, aggKd0=0.08;
      bingo=1;
     }
     //PWM0.SetTunings(aggKp0, aggKi0, aggKd0);
     //PWM1.SetTunings(aggKp1, aggKi1, aggKd1);
}
