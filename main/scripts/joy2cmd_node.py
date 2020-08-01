#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
cmd_vel = Twist()

def joy_callback(joy_msg):
    cmd_vel.linear.x = joy_msg.axes[1]
    cmd_vel.linear.y = joy_msg.axes[0]
    cmd_vel.angular.z = joy_msg.axes[2]

def main():
    rospy.init_node('joy2cmd_node', anonymous=True)
    rospy.Subscriber("joy", Joy, joy_callback)
    loop_rate = rospy.Rate(10) # 10Hz
    
    while not rospy.is_shutdown():
        pub.publish(cmd_vel)
        loop_rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException: pass