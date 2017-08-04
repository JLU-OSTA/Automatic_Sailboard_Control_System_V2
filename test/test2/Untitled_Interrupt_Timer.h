void timerns()
{
    digitalWrite(beep,LOW);
    timer=0;
    if(forward==1)
        forward=0;
    else
        forward=1;
}