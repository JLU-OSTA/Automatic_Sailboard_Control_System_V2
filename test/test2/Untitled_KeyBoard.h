void readkey()
{
	char key=keypad.getKey();
    if(key!=NO_KEY)
        delay(wait_key_ms);
    if(key=='A')
    {
        keyp=1;
        forward=0;
        key=NO_KEY;
        lcdprint(1,4,"1:");
        lcdprint(1,6,"   '");
        lcdclr(1,10,lcd_col-9);
        lcd.setCursor(5,0);
    }
    if(key=='B')
    {
        aimarr[forward]=0;
        rd=3;
        key=NO_KEY;
        lcd.setCursor(3,0);
        lcd.print(forward+1);
        lcd.print(":");
        lcdprint(1,6,"   '");
        lcdclr(1,10,lcd_col-9);
        lcd.setCursor(5,0);
    }
    if(rd==0 && forward==1)
    {
        keyp=0;
        rd=3;
        if(aimarr[0]>=99)
        {
            aimarr[0]+=1;
        }
        if(aimarr[1]>=99)
        {
            aimarr[1]+=1;
        }
        forward=0;
        return;
    }
    if(keyp==1 && key!=NO_KEY)
    {
        if(rd==3)
            aimarr[forward]=0;
        if(rd!=0)
        {
            lcd.print(key);
            aimarr[forward]+=(key-0x30)*pow(10,rd-1);
            rd--;
            if(rd==0 && forward==0)
            {
                rd=3;
                forward++;
                lcdprint(1,4,"2:");
                lcdprint(1,6,"   '");
                lcdclr(1,10,lcd_col-9);
                lcd.setCursor(5,0);
            }
            return;
        }
    }
}
