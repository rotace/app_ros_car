#include <ros.h>
#include <std_msgs/Int32MultiArray.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>

#include <math.h>

#define ENC_L  2
#define ENC_R  3
#define MOT_LF 5
#define MOT_LB 6
#define MOT_RF 9
#define MOT_RB 10
#define STS_SIZE 2

int mot_l = 0;
int mot_r = 0;
volatile int enc_l = 0;
volatile int enc_r = 0;
void readEncoderL() {
  enc_l++;
}

void readEncoderR() {
  enc_r++;
}

void command_motor_left(float veloc){
  if(veloc>+1.0) veloc=+1.0;
  if(veloc<-1.0) veloc=-1.0;
  mot_l = veloc*255;
  if(mot_l > 255) mot_l = 255;
  if(mot_l <-255) mot_l =-255;

  if( mot_l > 0 ) {
    analogWrite(MOT_LF, +mot_l);
    analogWrite(MOT_LB, 0);
  } else {
    analogWrite(MOT_LF, 0);
    analogWrite(MOT_LB, -mot_l);
  }
}

void command_motor_right(float veloc){
  if(veloc>+1.0) veloc=+1.0;
  if(veloc<-1.0) veloc=-1.0;
  mot_r = veloc*255;
  if(mot_r > 255) mot_r = 255;
  if(mot_r <-255) mot_r =-255;

  if( mot_r > 0 ) {
    analogWrite(MOT_RF, +mot_r);
    analogWrite(MOT_RB, 0);
  } else {
    analogWrite(MOT_RF, 0);
    analogWrite(MOT_RB, -mot_r);
  }
}

void controller(const geometry_msgs::Twist& twist){
  const float linear_x = twist.linear.x;
  const float angle_z = twist.angular.z;
  command_motor_left ( linear_x - angle_z );
  command_motor_right( linear_x + angle_z );
}

ros::NodeHandle  nh;
// nav_msgs::Odometry odom;
std_msgs::Int32MultiArray status;
ros::Publisher pub_status("status", &status);
ros::Subscriber<geometry_msgs::Twist> sub_cmd_vel("cmd_vel", &controller);


void setup() {
  // nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(pub_status);
  nh.subscribe(sub_cmd_vel);
  status.data = (int32_t*)malloc(sizeof(int32_t) * STS_SIZE);
  status.data_length = STS_SIZE;

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
  status.data[0] = enc_l;
  status.data[1] = enc_r;
  // status.data[2] = mot_l;
  // status.data[3] = mot_r;
  pub_status.publish( &status );
  nh.spinOnce();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}