# arduino サンプル

## 開発環境

- Ubuntu14.04 / 16.04
- ROS indigo / kinetic
- platformIO

## フォルダ構成

| フォルダ／ファイル名 | ROSserial | 内容 |
| --- | --- | --- |
| 01_led/ | 不要 | platformIOをつかったLチカ*1 |
| 02_ros_serial/ | 要 | ROSシリアルライブラリのサンプル*1 |
| 03_motor_drive/ | 要 | モーターの駆動*2 |

*1 [ROS講座46「ROSでarduinoを使う」](https://qiita.com/srs/items/53b1d0a9d574d9ca7752)  
*2 [メカト講座07「モータを速度制御する」](https://qiita.com/srs/items/3e69e392c9aefa1b4693)  

## インストール方法

ROSシリアルを使用するプロジェクトは、platformIOを使ったビルド＆アップロードの前に、プロジェクト内のlib/で以下のコマンドを実行して、ROSライブラリを展開してください。

```sh
$ rosrun rosserial_arduino make_libraries.py .
```

## 使用方法

### 01_led
1. platformIO等を用いてarduinoに書き込みます。
2. arduinoにUSB等で電源を供給すると動作します。

### 02_ros_serial
1. platformIO等を用いてarduinoに書き込みます。
2. arduinoをROSのインストールされているPCへUSBで接続します。
3. ターミナルを開き、以下のコマンドでROSを起動します。
```
$ roscore
```
4. 別のターミナルを開き、以下のコマンドでarduinoと接続します。_port:には、接続しているUSBのフルパスを設定ください。
```
$ rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0
```
5. 別のターミナルを開き、以下のコマンドで`data: hello world!`が見えます。
```
$ rostopic echo /chatter
```
6. 別のターミナルを開き、以下のコマンドでLEDが点灯します。
```
$ rostopic pub -1 /led std_msgs/Bool -- "data: true"
```

### 03_motor_drive
1. platformIO等を用いてarduinoに書き込みます。
2. arduinoをROSのインストールされているPCへUSBで接続します。
3. ターミナルを開き、以下のコマンドでROSを起動します。
```
$ roscore
```
4. 別のターミナルを開き、以下のコマンドでarduinoと接続します。_port:には、接続しているUSBのフルパスを設定ください。
```
$ rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0
```
5. 別のターミナルを開き、以下のコマンドでエンコーダのカウンタが見えます。
```
$ rostopic echo /encoder
```
6. 別のターミナルを開き、以下のコマンドで左モータが前進駆動します。
```
$ rostopic pub -1 /motor_l std_msgs/Float32 -- "data: 1.0"
```

## 参考文献
* [公式「ROSチュートリアル」](http://wiki.ros.org/ja/ROS/Tutorials)
* [Qiita「ROS講座」](https://qiita.com/srs/items/5f44440afea0eb616b4a)（[Git](https://github.com/project-srs/ros_lecture)）
