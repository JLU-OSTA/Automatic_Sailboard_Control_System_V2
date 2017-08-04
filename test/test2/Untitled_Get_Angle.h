void getangle()
{
	float dt,acy,acz,grz;
	float az_sum=0,tmp;
	float Sz=0,Rz=0;
	int i;
  lst_ang=ang;
  now=millis();
	dt=(now-last)/1000;
	last=now;
	accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
	acy=ay/acc_lsb;
	acz=az/acc_lsb;
  if(acz<0)
      aaz=360+180*atan2(acz,acy)/pi;
  else
      aaz=180*atan2(acz,acy)/pi;
	for(i=1;i<sample_rate;i++)
	{
		aazs[i-1]=aazs[i];
		az_sum+=aazs[i]*i;
	}
	aazs[sample_rate-1]=aaz;
	az_sum+=aaz*sample_rate;
	aaz=az_sum/((1+sample_rate)*sample_rate/2);
	grz=-(gz-gz0)/gcc_lsb*dt;
	agz+=grz;
/*Kalman*/
	for(i=1;i<(sample_rate+kalman_samdlt);i++)
	{
		a_z[i-1]=a_z[i];
		Sz+=a_z[i];
	}
	a_z[sample_rate+kalman_samdlt-1]=aaz;
	Sz/=(sample_rate+kalman_samdlt);
	for(i=0;i<(sample_rate+kalman_samdlt);i++)
	{
		Rz+=sq(a_z[i]-Sz);
	}
	Rz/=(sample_rate+kalman_samdlt);
	Pz+=kalman_dev;
	Kz=Pz/(Pz+Rz);
	agz+=Kz*(aaz-agz);
	Pz*=(1-Kz);
	ang=180-agz;
	tmp=ang_fit2*sq(ang);
	ang*=ang_fit1;
	ang+=ang_fit0;
	ang+=tmp;
  ang-=level;
  
  sum_tmp+=ang;
  div_tmp+=ang-lst_ang;
  if(in%50==0)
  {
      sum_tmp=0;
      div_tmp-0;
  }
    
}
