void lcdprint(int x,int y,char* str)
{
	lcd.setCursor(y-1,x-1);
	lcd.print(str);
}

void lcdclr(int x,int y,unsigned int num)
{
	int i=0;
	lcd.setCursor(y-1,x-1);
	for(;i<num;i++)
	{
		if((y+num-1)<=lcd_col)
			lcd.print(" ");
	}
}

void print_inf()
{
	  lcdprint(1,1,"Aim: ");
    lcdprint(2,1,"Now: ");
    lcdclr(1,6,lcd_col-5);
    lcd.setCursor(5,0);
    lcd.print(aimarr[forward]);
    lcd.print("'");
    if(in%100==0)
    {
        lcdclr(2,6,lcd_col-5);
        lcd.setCursor(5,1);
        lcd.print(ang);
        lcd.print("'");
    }
}
