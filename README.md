# app_ros_car
ROSラジコンカー

## インストール方法
1. catkinワークスペースの作成
``` bash
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
```

2. setup.bashのロード
``` bash
$ source ~/catkin_ws/devel/setup.bash
```

3. リポジトリのクローン
``` bash
$ cd ~/catkin_ws/src
$ git clone git@github.com:rotace/app_ros_car
```

4. ビルド
``` bash
$ cd ~/catkin_ws
$ catkin_make
```

## 参考文献
* [公式「ROSチュートリアル」](http://wiki.ros.org/ja/ROS/Tutorials)
* [Qiita「ROS講座」](https://qiita.com/srs/items/5f44440afea0eb616b4a)（[Git](https://github.com/project-srs/ros_lecture)）
* [「ROSで始めるロボティクス」](http://bril-tech.blogspot.com/2016/10/ros1-robot-operating-system.html)