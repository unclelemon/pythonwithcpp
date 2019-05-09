# pythonwithcpp
g++ ‘filename’.cpp -o ‘filename’ -I/usr/include/python2.5 -L/usr/lib/python2.5 -lpython2.5  
执行 ./a.out  
notes：  
1、.py 和 .cpp文件在同一目录下  
2、不能将python文件的名字命名为test.py,否则报错，由于test.py是python内置python脚本文件，也就是python有自己的test.py文件，并且其优先级比你的高。  
3、python3没有PyString_*，改为PyBytes_*，  
