# Format 1 Lab

Introduction to format string attack lab

## Let's Play

Review the source code [chall.c](/chall.c) and find the bug. Please hack this lab on your own environment, then get the real flag at `ws://format-1-lab.herokuapp.com`.

## WebSocket PWN

On Heroku, only web applications can be deployed. Thus, the PWN challenges are deployed using WebSocket protocol.

### netcat to wscat

Connect to lab app with wscat instead. To install wscat, NPM is required.

```
$ npm install -g wscat
$ wscat -c ws://echo.websocket.org
Connected (press CTRL+C to quit)
> hi there
< hi there
> are you a happy parrot?
< are you a happy parrot?
```

### pwnlib.tubes.remote.remote to sock_websocket.WebSock

Connect to lab app with sock_websocket.WebSock instead.

```
$ pip install sock-websocket
[...]
$ cat echo.py
from pwn import *
from sock_websocket import WebSock

# s = process("chall")
# s = remote("1.3.3.7", 1337)
s = WebSock("ws://echo.websocket.org")
s.sendline(b"Hello World !")
s.interactive()

$ python echo.py
Hello World !
<3
<3
```

## Running Locally

Make sure you have Python 3.7 [installed locally](http://install.python-guide.org). To push to Heroku, you'll need to install the [Heroku CLI](https://devcenter.heroku.com/articles/heroku-cli).

```sh
$ git clone https://github.com/ErbaZZ/format-1-lab.git
$ cd format-1-lab
$ docker build -t format-1-lab .
$ docker run -d --rm -p 1337:1337 -e PORT=1337 -e FLAG=flag{example_flag} -e PASS=example_password format-1-lab
```

Your app should now be running on `ws://localhost:1337`.

## Deploying to Heroku

```sh
$ heroku create
$ heroku config:set FLAG=flag{example_flag}
$ heroku config:set PASS=example_password
$ heroku stack:set container
$ git push heroku main
$ heroku open
```
or

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy)
