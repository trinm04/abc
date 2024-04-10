
#include <AccelStepper.h>

AccelStepper stepper1(1,5,4);// pin 5 step, pin 4 dir
AccelStepper stepper2(1,7,8);
AccelStepper stepper3(1,10,11);

int apha = 20;
int tocdostep2 = 200; // 360do/s

void setup() {
  Serial.begin(9600);
  
  pinMode(6,OUTPUT); // Enable
  digitalWrite(6,LOW);
  pinMode(9,OUTPUT); // Enable
  digitalWrite(9,LOW); 
  pinMode(12,OUTPUT); // Enable
  digitalWrite(12,LOW);// Dặt Enable xuống low để khởi động động cơ

  stepper1.setMaxSpeed(800);//di trong 5s => toc do = so buoc chia 5
  stepper1.setAcceleration(800);
  stepper1.moveTo(apha*8/1.8);

  stepper2.setMaxSpeed(800);
  stepper2.moveTo(30000);
  stepper2.setAcceleration(800);
  
  stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800);
  stepper3.moveTo(2000);

}

void loop() 
{
  if(!stepper1.isRunning()&&!stepper2.isRunning()&&!stepper3.isRunning()) // kiểm tra xem có đang hoạt động ko 
  {
  stepper1.setMaxSpeed(800);//di trong 5s => toc do = so buoc chia 5
  stepper1.setAcceleration(800); // sét gia tốc góc động cơ 
  stepper1.moveTo(apha*8/1.8);

  stepper3.setMaxSpeed(800);
  stepper3.setAcceleration(800); // sét gia tốc góc động cơ 
  stepper3.moveTo(2000); // di chuyển đến  vị trí có tọa độ 


  stepper2.setMaxSpeed(800);
  stepper2.setAcceleration(800); // sét gia tốc góc động cơ 
  stepper2.moveTo(30000);
  }
  stepper3.runToPosition();// cài đặt thứ tự\\\\chạy  của steep
  stepper1.runToPosition();
  stepper2.runToPosition();


  if(stepper1.distanceToGo()==0)  // kiểm tra xem s1 đến vị trí chưa đến rồi thì quay về ko 
  {
  // stepper1.moveTo(0);
  stepper1.runToNewPosition(0);
  }

  if(!stepper1.isRunning()&&!stepper2.isRunning()&&!stepper3.isRunning()) // sét điểm đầu của động coe 
  {
    stepper1.setCurrentPosition(0);
    stepper2.setCurrentPosition(0);
    stepper3.setCurrentPosition(0);

  }
}
