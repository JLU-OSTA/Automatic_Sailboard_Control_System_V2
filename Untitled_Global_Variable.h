int16_t ax,ay,az,gx,gy,gz;	//accelogyro variable
double lst_ang=0;
long now=0,last=0;
float gz0=0,agz=0,aaz;
float aazs[sample_rate]={0};
float a_z[sample_rate+kalman_samdlt]={0};
float Pz=1,Kz;    //kalman
float ang,level=0,sumup=0;//angle debuger variable


//float sum_tmp=0,div_tmp=0;

double Setpoint,Input;
double aggKp0,aggKi0,aggKd0;
//double aggKp1,aggKi1,aggKd1;

double pwm[2]=pwm_def;	
long last_time_un=0,now_time_un=0;
int forward=0,pwm_motor;	//pwm adjustment variable
int keyp=0,rd=3,in=0,timer=0,aimarr[2]=range_def,wait=10,bingo=1;	//adjustment variable



//double pwmzs[2][sample_rate]={0};
//double pwm_z[2][sample_rate+kalman_samdlt]={0};
//double Pt[2]={1,1},Kt[2];
//long pwm_time[2]={0},pwm_lst_time[2]={0};


LiquidCrystal lcd(rs_pin,en_pin,data_pin);	//set lcd1602
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );	//set keyboard
MPU6050 accelgyro;	//initialize accelgyro MPU6050
PID PWM0(&Input,&pwm[0],&Setpoint,aggKp0,aggKi0,aggKd0,DIRECT);
PID PWM1(&Input,&pwm[1],&Setpoint,aggKp0,aggKi0,aggKd0,REVERSE);
