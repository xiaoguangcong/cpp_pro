1. 基于boost的代码实现

环境：boost 1.66.0

安装的教程网上很多，很容易的。

安装后编译代码

'''
g++ -Wall http_server.cpp -lboost_system -lboost_filesystem -o http_server -std=c++17 -lpthread -lboost_thread
'''

运行前需要设置环境变量：
'''
export LD_LIBRARY_PATH="/usr/local/lib/:$LD_LIBRARY_PATH"
'''