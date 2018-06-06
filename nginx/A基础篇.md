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
    命令：nginx -V

## 3、Nginx基本配置语法

    user                设置nginx服务的系统使用用户
    worker_process      工作进程数
    error_log           nginx的错误日志
    pid                 nginx启动时的pid

    events      worker_connections      每个进程允许的最大连接数
                use                     工作进程数

    

# 三、默认模块
    nginx -V  查看模块

## ngx_http_stub_status_module
    Syntax: stub_status;
    Default:    —
    Context:    server, location
    e.g.
    location /mystatus {
        stub_status;
    }

## ngx_http_random_index_module
    Syntax: random_index on | off;
    Default:    random_index off;
    Context:    location
    e.g.
    location / {
        random_index on;
    }

## ngx_http_access_module
    Syntax: allow address | CIDR | unix: | all;
    Default:    —
    Context:    http, server, location, limit_except
    e.g.
    location / {
        deny  192.168.1.1;
        allow 192.168.1.0/24;
        allow 10.1.1.0/16;
        allow 2001:0db8::/32;
        deny  all;
    }

## ngx_http_auth_basic_module
    Syntax: auth_basic_user_file file;
    Default:    —
    Context:    http, server, location, limit_except
    e.g.
    location / {
        auth_basic           "closed site";
        auth_basic_user_file conf/htpasswd;
    }




## HTTP的请求和连接
    curl http://www.baidu.com
    curl -v http://www.baidu.com

