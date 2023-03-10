# minitalk
## 概要
42Tokyo[^1]の課題の一つ。クライアントとサーバーの形でシグナル通信を行う。

[^1]:https://42tokyo.jp/

## 詳細
- **サーバー**
  - 起動後にサーバーのPIDを表示
  - 文字列を受信したら、それを素早く表示する
  - 再起動することなく、複数のクライアントから連続して文字列を受信できる

- **クライアント**
  - パラメータとして渡された文字列をサーバーに伝える
  - パラメータとして以下を受け取る
    - サーバーのPID
    - 送信する文字列
    
- プログラム間の通信は、以下UNIXのシグナルのみを使用。
  - SIGUSR1
  - SIGUSR2

## 実行
- ビルド
```
$ git clone https://github.com/RIshimoto/minitalk
$ cd minitalk
$ make
```

- サーバー
```
$ ./server
(PID)
```

- クライアント
```
（サーバー起動後）
$ ./client (serverのPID) (送りたい文字列)
```

## デモ
https://user-images.githubusercontent.com/57135683/213507453-796f696b-bd9e-4824-a65c-4e1493735934.mp4

## 使用したライブラリ関数
write, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit
