# ROSラジコンカー

## 開発環境

- Ubuntu14.04
- ROS indigo
- platformIO

## インストール方法

本パッケージはrosserialを使用するため、platformIOを使ったビルド＆アップロードの前に、プロジェクト内のlib/で以下のコマンドを実行して、ROSライブラリを展開してください。

```sh
$ rosrun rosserial_arduino make_libraries.py .
```

## 使用方法

### PS3コントローラのペアリング及び動作確認

本パッケージのコントローラとしてPS3コントローラを使用する場合は、以下の手順に従ってBluetoothペアリング及び動作確認を実施してください。
参考：[「ps3joy」](http://wiki.ros.org/ps3joy)、[「ps3joy/Tutorials」](http://wiki.ros.org/ps3joy/Tutorials)

1. PS3コントローラをUSB接続します。
2. パソコンにBluetoothが内蔵されていない場合は、BluetoothドングルをUSB接続します。
3. ターミナルを開き、以下のコマンドでペアリングを行います。
```
$ sudo bash
# rosrun ps3joy sixpair
```
4. PS3コントローラを取り外します。
5. 以下のコマンドでPS3コントローラをBluetooth接続します。
```
# rosrun ps3joy ps3joy.py
```
6. PS3コントローラの「PS」ボタンを押下し、以下が表示されることを確認します。
```
Connection is Activated.
```
7. ターミナルを開き、以下のコマンドでROSを起動します。
```
$ roscore
```
8. 別のターミナルを開き、以下のコマンドでPS3コントローラのノードを作成します。
```
$ rosrun joy joy_node
```
9. 別のターミナルを開き、以下のコマンドでPS3コントローラの操作内容が見えます。
```
$ rostopic echo /joy
```

### メインルーチンの起動

ランチファイルから一括起動します。
```
$ roslaunch main main.launch
```