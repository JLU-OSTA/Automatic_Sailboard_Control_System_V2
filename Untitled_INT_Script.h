now_time_un=millis();
if(timer==0)
    last_time_un=now_time_un;
if((now_time_un-last_time_un)>=5000 && last_time_un!=0)
    timerns();
readkey();
if(keyp==1)
    return;