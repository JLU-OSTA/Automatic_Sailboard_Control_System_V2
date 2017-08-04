void angle_sumup()
{
	accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
	if(in%load_time_def==0)
	{
		lcdprint(1,1,"Loading...     %");
		lcdprint(2,1," Untitled  Team ");
		lcd.setCursor(12,0);
		lcd.print(100*(in-angle_sumup_a)/(angle_sumup_b-angle_sumup_a));
	}
	gz0+=gz;
}

void angle_inited()
{
	lcdprint(1,1,"   Corrected!   ");
	lcdprint(2,1," Untitled  Team ");
	digitalWrite(beep,HIGH);
	delay(angle_auto_ms);
	digitalWrite(beep,LOW);
	delay(wel_time_ms-angle_auto_ms);
    in=0;
}
