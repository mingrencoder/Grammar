# Nginx介绍

## 中间件架构

    - 对sql的注入防攻击
    - 对请求的访问控制
    - 对请求的频率控制
    - 对防爬虫

## 对Nginx中间件性能优化

    - http性能压测
    - 性能瓶颈分析
    - 系统性能优化
    - 基于Nginx的性能配置优化

# 环境调试确认

    1、确认系统网络
    2、确认yum可用
    3、确认关闭iptables规则
    4、确认停用selinux

# 基于Nginx的中间件架构

## 环境调试确认

### 两项安装
    yum -y install gcc gcc-c++ autoconf pcre pcre-devel make automake
    yum -y install wget httpd-tools vim

### 一次初始化
    cd /opt;
    mkdir app(代码) download(源码包) logs(自定义日志文件) work(shell脚本) backup




