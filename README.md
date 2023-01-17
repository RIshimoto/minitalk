# minitalk
## 概要
42Tokyoの課題の一つ。クライアントとサーバーの形でシグナル通信を行う。

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

## 使用関数
write, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit
