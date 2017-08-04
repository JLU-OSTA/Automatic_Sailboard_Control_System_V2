//double kp = 5, ki = 5, kd = 0;
//double pid_arr[3] = {0};
//double a, b, c;
//double sumang;

const int inter_time = 25;

#include <TimerOne.h>
#include "Untitled_Header.h"

double adj()
{
  Input = ang;
  //for(int i=1;i<3;i++)
  //    pid_arr[i-1]=pid_arr[i];
  //pid_arr[2]=aimarr[forward]-ang;
  PWM0.Compute();
  PWM1.Compute();
  //pwm[0]+=a*pid_arr[2]-b*pid_arr[1]+c*pid_arr[0];
  //pwm[1]-=a*pid_arr[2]-b*pid_arr[1]+c*pid_arr[0];
  analogWrite(pwm_m[0], pwm[0]);
  analogWrite(pwm_m[1], pwm[1]);
}

void setup()
{
  aggKp0 = 1.30;
  aggKi0 = 0.16;
  aggKd0 = 0.23;
  #include "Untitled_Initialize_Script.h"
  Setpoint = aimarr[0];
  PWM0.SetMode(AUTOMATIC);
  PWM1.SetMode(AUTOMATIC);
  PWM0.SetTunings(aggKp0, aggKi0, aggKd0);
  PWM1.SetTunings(aggKp0, aggKi0, aggKd0);
  //PWM1.SetTunings(aggKp1,aggKi1,aggKd1);
  pwm[1] = 110;
  pwm[0] = 140;
  analogWrite(pwm_m[1], pwm[1]);
  analogWrite(pwm_m[0], pwm[0]);
  delay(1000);
  Timer1.initialize(inter_time * 1000);
  Timer1.attachInterrupt(adj);
  //Serial.begin(115200);  //Debuger
}

void loop()
{
#include "Untitled_INT_Script.h"
  Setpoint = aimarr[forward];
  if(Setpoint<70)
  {
      aggKp0 = 1.30;
      aggKi0 = 0.16;
      aggKd0 = 0.23;
  }
  else
  {
      aggKp0 = 2.25;
      aggKi0 = 0.44;
      aggKd0 = 0.00;
  }


  PWM0.SetTunings(aggKp0, aggKi0, aggKd0);
  PWM1.SetTunings(aggKp0, aggKi0, aggKd0);
  angle_judgement();
  getangle();
  if (Serial.available() > 0)
  {
    char cmd = Serial.read();
    delay(2);
    switch (cmd)
    {
      case 'p': {
          aggKp0 -= 0.01;
          break;
        }
      case 'P': {
          aggKp0 += 0.01;
          break;
        }
      case 'i': {
          aggKi0 -= 0.01;
          break;
        }
      case 'I': {
          aggKi0 += 0.01;
          break;
        }
      case 'd': {
          aggKd0 -= 0.01;
          break;
        }
      case 'D': {
          aggKd0 += 0.01;
          break;
        }
        /*case 'R':{analogWrite(pwm_m[1],255);delay(1500);analogWrite(pwm_m[1],110);break;}
        */
    }
    PWM0.SetTunings(aggKp0, aggKi0, aggKd0);
    PWM1.SetTunings(aggKp0, aggKi0, aggKd0);
  }
  /*if(in%25==0)
  {
      Serial.print("S");Serial.print(ang);Serial.print(" ");Serial.print(pwm[0]);Serial.print(" ");
      Serial.print(aggKp0);Serial.print(" ");Serial.print(aggKi0);Serial.print(" ");Serial.print(aggKd0);
      Serial.print("E");
  }
  PWM0.SetTunings(aggKp0,aggKi0,aggKd0);
  PWM1.SetTunings(aggKp0,aggKi0,aggKd0);*/

  if (in % 20 == 0)
  {
    /*Serial.print(ang);
    Serial.print("\t");
    Serial.print(aggKp0);
    Serial.print("\t");
    Serial.print(aggKi0);
    Serial.print("\t");
    Serial.println(aggKd0);*/
    print_inf();
  }
  if (in >= 200)
    in = 0;
  in++;
}
