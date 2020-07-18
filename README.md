# app_ros_car
ROSラジコンカー

## 開発環境

- Ubuntu14.04 / 16.04
- ROS indigo / kinetic
- platformIO

## フォルダ構成

| フォルダ／ファイル名 | 内容 |
| --- | --- |
| sample/ | 主にサンプルコードを集めたROSパッケージ |
| $ROS_PKG_NAME/src/ | ROS側のソースコード |
| $ROS_PKG_NAME/ino/ | arduino側のソースコード |

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

4. 依存パッケージのインストール
``` bash
$ rosdep install -r --from-path src --ignore-src
```

5. ビルド
``` bash
$ cd ~/catkin_ws
$ catkin_make
```

## 参考文献
* [公式「ROSチュートリアル」](http://wiki.ros.org/ja/ROS/Tutorials)
* [Qiita「ROS講座」](https://qiita.com/srs/items/5f44440afea0eb616b4a)（[Git](https://github.com/project-srs/ros_lecture)）
* [「ROSで始めるロボティクス」](http://bril-tech.blogspot.com/2016/10/ros1-robot-operating-system.html)