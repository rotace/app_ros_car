#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32MultiArray.h>

#include <math.h>

#define ENC_L  2
#define ENC_R  3
#define MOT_LF 5
#define MOT_LB 6
#define MOT_RF 9
#define MOT_RB 10

volatile int count_l = 0;
volatile int count_r = 0;
void readEncoderL() {
  count_l++;
}

void readEncoderR() {
  count_r++;
}

void control_motor_l(const std_msgs::Float32& msg){
  int val = msg.data*255;
  if(val > 255) val = 255;
  if(val <-255) val =-255;

  if( val > 0 ) {
    analogWrite(MOT_LF, +val);
    analogWrite(MOT_LB, 0);
  } else {
    analogWrite(MOT_LF, 0);
    analogWrite(MOT_LB, -val);
  }
}

void control_motor_r(const std_msgs::Float32& msg){
  int val = msg.data*255;
  if(val > 255) val = 255;
  if(val <-255) val =-255;

  if( val > 0 ) {
    analogWrite(MOT_RF, +val);
    analogWrite(MOT_RB, 0);
  } else {
    analogWrite(MOT_RF, 0);
    analogWrite(MOT_RB, -val);
  }
}

ros::NodeHandle  nh;
std_msgs::Int32MultiArray count;
ros::Publisher pub_encoder("encoder", &count);
ros::Subscriber<std_msgs::Float32> sub_motor_l("motor_l", &control_motor_l);
ros::Subscriber<std_msgs::Float32> sub_motor_r("motor_r", &control_motor_r);


void setup() {
  nh.initNode();
  nh.advertise(pub_encoder);
  nh.subscribe(sub_motor_l);
  nh.subscribe(sub_motor_r);
  count.data = (int32_t*)malloc(sizeof(int32_t) * 2);
  count.data_length = 2;

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENC_L, INPUT);
  pinMode(ENC_R, INPUT);
  pinMode(MOT_LF, OUTPUT);
  pinMode(MOT_LB, OUTPUT);
  pinMode(MOT_RF, OUTPUT);
  pinMode(MOT_RB, OUTPUT);

  analogWrite(MOT_LF, 0);
  analogWrite(MOT_LB, 0);
  analogWrite(MOT_RF, 0);
  analogWrite(MOT_RB, 0);

  attachInterrupt(digitalPinToInterrupt(ENC_L), readEncoderL, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENC_R), readEncoderR, CHANGE);
}

void loop() {
  count.data[0] = count_l;
  count.data[1] = count_r;
  pub_encoder.publish( &count );
  nh.spinOnce();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}