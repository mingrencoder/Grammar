# 一、快速安装

## 版本
Mainline version - 开发版
Stable version - 稳定版
Legacy version - 历史版

## 安装

yum install nginx

# 二、配置语法

## 1、安装目录
    命令：rpm -ql nginx

    /etc/logrotate.d/nginx      配置文件    Nginx日志轮转，用于logrotate服务的日志切割

    /etc/nginx                  目录、配置文件     Nginx主配置文件
    /etc/nginx/nginx.conf
    /etc/nginx/conf.d
    /etc/nginx/conf.d/default.conf

    /etc/nginx/fastcgi_params   配置文件    cgi配置相关，fastcgi配置
    /etc/nginx/uwsgc_params
    /etc/nginx/scgi_params

    /etc/nginx/koi-utf          配置文件    编码转换映射转化文件
    /etc/nginx/koi-win
    /etc/nginx/win-utf

    /etc/nginx/mime.types       配置文件   设置http协议的Content-Type与扩展名对应关系

    /usr/lib/system/nginx-debug.service  配置文件 用于配置出系统守护进程管理器管理方式
    /usr/lib/system/nginx.service
    /etc/sysconfig/nginx
    /etc/sysconfig/nginx-debug

    /usr/sbin/nginx         命令      Nginx服务启动管理的终端命令
    /usr/sbin/nginx-debug

    /usr/share/doc/nginx-1.12.0     文件、目录   Nginx的手册和帮助文件
    /usr/share/doc/nginx-1.12.0/COPYRIGHT
    /usr/share/man/man8/nginx.8.gz

    /var/cache/nginx        目录      Nginx的缓存目录

## 2、编译参数

## 3、Nginx基本配置语法

# 三、默认模块

# 四、Nginx的log

# 五、访问限制 

## 1、HTTP的请求和连接

## 2、请求限制与连接限制

## 3、access模块配置语法

## 4、请求限制局限性

## 5、基本安全认证

## 6、auth模块配置语法

## 7、安装认证局限性
