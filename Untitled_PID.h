//if((sum_tmp/100-div_tmp/100)<80)
//else if((sum_tmp/100+div_tmp/100)>100)
//{
//    PWM1.Compute();
//    pwm[0]=90;
//}
//output0=90;//80-120:90
//output1=100;//95-125:100
void kal_pid(int motor)
{
	double dt,ppwm;
	double pwm_sum=0,St=0,Rt=0;
	int i;
	pwm_time[motor]=millis();
	dt=(pwm_time-pwm_lst_time)/1000;
	pwm_lst_time[motor]=pwm_time[motor];
	for(i=1;i<sample_rate;i++)
	{
		pwmzs[motor][i-1]=pwmzs[motor][i];
		pwm_sum+=pwmzs[motor][i]*i;
	}
	pwmzs[motor][sample_rate-1]=pwm[motor];
	pwm_sum+=pwm[motor]*sample_rate;
	ppwm=pwm_sum/((1+sample_rate)*sample_rate/2);
	//PWM0.Compute();
	for(i=1;i<(sample_rate+kalman_samdlt);i++)
	{
		pwm_z[motor][i-1]=pwm_z[motor][i];
		St+=pwm_z[motor][i];
	}
	pwm_z[motor][sample_rate+kalman_samdlt-1]=ppwm;
	St/=(sample_rate+kalman_samdlt);
	for(i=0;i<(sample_rate+kalman_samdlt);i++)
	{
		Rt+=sq(pwm_z[motor][i]-St);
	}
	Rt/=(sample_rate+kalman_samdlt);
	Pt[motor]+=kalman_dev;
	Kt[motor]=Pt[motor]/(Pt[motor]+Rt);
	pwm[motor]+=Kt[motor]*(ppwm-pwm[motor]);
	Pt[motor]*=(1-Kt[motor]);
}
