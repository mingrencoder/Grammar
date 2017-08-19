# -*- coding: utf-8 -*-

from random import randint,sample
import timeit
from time import time
from collections import namedtuple
from collections import Counter
import re
from collections import OrderedDict
from collections import deque

print '**************************筛选数据**************************'
# 如何在列表，字典，集合中根据条件筛选数据
# 
# 例1：
#   过滤掉列表中的负数
# 解决方案：Filter函数 filter(lambda x:x >= 0, data)
#                 列表解析    [x for x in data if x >=0]
#                 
# 例2：
# 筛选出字典中高于90的项
# 解决方案：{k: v for k, v in d.iteritems() if v > 90}
# 
# 例3：
# 筛选出集合中能被3整除的元素
# 解决方案：{x for x in s if x % 3 == 0}

print '---------例1-----------'
data = [randint(-10, 10) for _ in xrange(10)]
print data

print filter(lambda x: x >= 0, data)

print [x for x in data if x >= 0] # 速度更快

print '---------例2-----------'
d = {x: randint(60, 100) for x in xrange(1, 21)}
print d
print {k: v for k, v in d.iteritems() if v > 90}

print '---------例3-----------'
s = set(data)

print {x for x in s if x % 3 == 0}


print '**************************命名**************************'
# 如何为元组中的每个元素命名，提高程序可读性
# 
# 例：
#   学生信息系统中的数据为固定格式 (名字，年龄，性别，邮箱)
# 解决方案：
#   方案1、定义类似与其他语言的枚举类型，定义一些列的数值常量
#   方案2、使用标准库中collections.namedtuple替代tuple
sudent = ('Jim', 17, 'male', 'Jim@gmail.com')

# 原始方法获取name
print sudent[0]

# 方法1

# NAME = 0
# AGE = 1
# SEX = 2
# EMAIL = 3
NAME, AGE, SEX, EMAIL = xrange(4)
# age
print sudent[AGE]

# 方法2
# 定义一个可以设置别名的tuple
stu = namedtuple('STUDENT', ['name', 'age', 'sex', 'email'])
s = stu('Bob', '19', 'male', 'Bob@gmail.com')

print s

print s.name
# s属于tuple
print isinstance(s, tuple)


print '**************************统计**************************'
# 如何统计序列中元素的出现频度
#  
# 例1：
#   某随机序列中找到出现次数最高的3个元素与次数
# 解决方案：
#   方案1、dict.fromkeys(data, 0)，再遍历给值不断加一
#   方案2、from collections import Counter，将序列传入Counter构造器，得到Counter对象是元素频度的字典
#         再通过Counter.most_common(n)方法得到频度最高的n个元素的列表

# 例2：
#   对某英文文章的单词进行词频统计，找到出现次数最多的10个单词与次数
# 解决方案：
#   引入re正则模块

print '---------例1-----------'
data = [randint(0,20) for _ in xrange(30)]

# 创建一个新字典，以data为键，以0为值
# 注意这里得到的键都是不重复的
c1 = dict.fromkeys(data, 0)

# 方法1
# 遍历循环data，每遇到一次就给c的对应值加一，再进行排序
for x in data:
    c1[x] += 1

print {k: v for k, v in c1.iteritems() if v > 2}
# 方法2
c2 = Counter(data)
print c2
print c2.most_common(3)

print '---------例2-----------'
txt = 'abc ab abc nnn bob dddd you me hah houhou'

c3 = Counter(re.split('\W+', txt))
print c3.most_common(3)


print '**************************字典排序**************************'
# 如何根据字典中的值的大小来，对字典项进行排序
#  
# 例1：
#   某班英语成绩以字典形式存储，按照成绩从高到低排序
# 解决方案：
#   方案1、使用内置函数sorted：利用zip将字典转化为元组，
#   方案2、使用内置函数sorted：传递sorted函数的key参数

d = {x: randint(60, 100) for x in 'abcxyz'}
print d

# sorted默认是以键key进行比较
print sorted(d)

# 方法1
z = zip(d.itervalues(),d.iterkeys())
print sorted(z)

# 方法2
# 迭代时，把items中的每个项作为x传入lambda函数中，通过 key= 来自定义用哪一部份作为键值
print sorted(d.items(), key = lambda x: x[1])


print '**************************公共键**************************'
# 如何快速找到多个字典中的公共键(key)
#  
# 例1：
#   足球联赛，每轮比赛球员进球统计
#   第一轮：{'梅西':2,'C罗':3,'苏雷亚斯',1}
#   第二轮：{'梅西':3,'格里芬':2,'C罗',2}
#   第三轮：{'内马尔':3,'贝尔':2,'保罗',3}
#   ……
#   统计前N轮，每场比赛都有进球的球员

# 解决方案：
#   利用集合set交集操作
#       step1、使用字典的viewkeys()方法，得到字典的keys集合
#       step2、使用map函数，得到所有字典的keys集合
#       step3、使用reduce函数，得到所有字典keys集合的交集
#   

print '---------对于前三轮-----------'
# 随机取样
sam1 = sample('abcdefg', randint(3, 6))
sam2 = sample('abcdefg', randint(3, 6))
sam3 = sample('abcdefg', randint(3, 6))

# 采样球员每位进球1到4个
s1 = {x: randint(1,4) for x in sam1}
s2 = {x: randint(1,4) for x in sam2}
s3 = {x: randint(1,4) for x in sam3}
print s1,'\n',s2,'\n',s3

v1 = s1.viewkeys()
v2 = s2.viewkeys()
v3 = s3.viewkeys()

print v1&v2&v3


print '---------对于前N轮-----------'

m = map(dict.viewkeys, [s1, s2, s3])
result = reduce(lambda a, b: a&b, m)
print result



print '**************************历史记录**************************'
# 如何实现用户的历史记录功能

# 解决方案：
#   from collections import deque

q = deque(maxlen = 3)

q.append(3)
q.append(5)
q.append(2)
print q

q.append(4)
print q

print '**************************字典有序**************************'
# 如何让字典保持有序
# 
# 例：
#   竞赛系统，选手完成题目后将比赛用时记录到字典中，并可按照姓名查询成绩
#   最后按照排名打印选手成绩
#   
#   from collections import OrderedDict

d = OrderedDict()

players = list('ABCDEFGH')
start = time()

for i in xrange(8):
    raw_input()
    p = players.pop(randint(0, 7-i))
    end = time()
    print i + 1, p, end - start
    d[p] = (i+1, end - start)

print '\n'

for k in d:
	print k, d[k]

