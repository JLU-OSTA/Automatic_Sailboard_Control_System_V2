Setpoint=aimarr[forward];

//if((sum_tmp/100-div_tmp/100)<80)
{
    PWM0.Compute();
    output1=100;
}
//else if((sum_tmp/100+div_tmp/100)>100)
//{
//    PWM1.Compute();
//    output0=90;
//}
//output0=90;//80-120:90
//output1=100;//95-125:100
analogWrite(pwm_m[0],output0);
analogWrite(pwm_m[1],output1);
