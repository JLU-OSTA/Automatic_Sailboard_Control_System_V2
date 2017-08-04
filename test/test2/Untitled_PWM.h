void pwm_adjustment()
{
	float poor,pang,a,b,c,d;
	int add,tp,flr;
  int aim=aimarr[forward];
	/*haha*/poor=abs(ang-aim);
	add=1;
	wait=1;
	tp=pwm_up-add;
	flr=pwm_dowm+add;
	analogWrite(pwm_m[0],0);
	analogWrite(pwm_m[1],0);
	delay(wait);
}
