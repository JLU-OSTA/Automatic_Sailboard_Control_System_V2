int16_t ax,ay,az,gx,gy,gz;	//accelogyro variable
float ang,level=0,sumup=0,a_ang;	//angle debuger variable

int forward=0,pwm[2]=pwm_def,pwm_motor;	//pwm adjustment variable
int keyp=0,rd=3,in=0,timer=0,aimarr[2]=range_def,wait=10;	//adjustment variable
int bingo=1;
long last_time_un=0,now_time_un=0,inall=0;	//intergration time variable

long now=0,last=0;
float gz0=0;
float aaz,agz;
float aazs[sample_rate]={0};
float a_z[sample_rate+kalman_samdlt]={0};
float Pz=1,Kz,Vz,Qz;

LiquidCrystal lcd(rs_pin,en_pin,data_pin);	//set lcd1602
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );	//set keyboard
MPU6050 accelgyro;	//initialize accelgyro MPU6050
