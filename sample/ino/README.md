# arduino サンプル

## 開発環境

- Ubuntu14.04 / 16.04
- ROS indigo / kinetic
- platformIO

## フォルダ構成

| フォルダ／ファイル名 | 内容 |
| --- | --- |
| 01_led/ | platformIOをつかったLチカ*1 |
| 02_ros_serial/ | ROSシリアルライブラリのサンプル*1 |

*1 [ROS講座46 ROSでarduinoを使う](https://qiita.com/srs/items/53b1d0a9d574d9ca7752)

## インストール方法

platformIOを使ったビルド＆アップロードの前に、各pioプロジェクトのlib/で以下のコマンドを実行して、ROSライブラリを展開してください。

```sh
$ rosrun rosserial_arduino make_libraries.py .
```

## 参考文献
* [公式「ROSチュートリアル」](http://wiki.ros.org/ja/ROS/Tutorials)
* [Qiita「ROS講座」](https://qiita.com/srs/items/5f44440afea0eb616b4a)（[Git](https://github.com/project-srs/ros_lecture)）
