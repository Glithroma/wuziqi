# wuziqi

C++五子棋课程设计
要求：
设计并实现五子棋游戏系统；
有欢迎与登录界面、说明界面和游戏界面。
欢迎界面显示游戏的名称和游戏菜单，选择不同的菜单可以实现开始游戏、阅读游戏说明、按键功能说明以及退出游戏功能。
实现悔棋和复盘功能。
按五子棋规则实现对战过程，并返回赢家信息。

两个文件夹里，名字为wuziqi的文件夹是我自己创建的，里面包含工程文件和.cpp/.h文件，另外一个是编译器自己生成的，可执行文件什么的在里边。
我也没搞懂mac上Qt Creator的机制...自己领悟吧
另外，代码是在mac上的Qt Creator上写的，不知道可不可以直接下载后运行

mainwindow是登陆界面的类
其他界面的类名字应该很清楚了

关于game.cpp：
我尝试写了一下博弈树相关的算法，但是应该是写错了，导致棋子多后运行时间长，而且算出来的结果好像也不是很好，于是就把这些代码弃用了，但还是留在了game.cpp文件里。欢迎改进。
如果你想试试我写的辣鸡算法：有一个叫findBestPoint的函数，最前面有一段代码，把这段代码剪切粘贴到AIAct里，然后用你的智慧做做微调，把原先的遍历棋盘算最好的点的循环注释掉就可以用了

关于复盘：
如果一个对局是A用户下的，那么只有A用户可以查看它。

关于账号：
考虑不周，没写密码找回功能，欢迎改进。
