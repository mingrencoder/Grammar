# -*- coding: utf-8 -*-
# 
# 如何在列表，字典，集合中根据条件筛选数据

# 解决方案：  列表： Filter函数 filter(lambda x:x >= 0, data)
#                 列表解析    [x for x in data if x >=0]
#           字典： {k: v for k, v in d.iteritems() if v > 90}
#           集合： {x for x in s if x % 3 == 0}

from random import randint
import timeit

# 过滤掉列表中的负数
data = [randint(-10, 10) for _ in xrange(10)]

print data

print filter(lambda x: x >= 0, data)

print [x for x in data if x >= 0] # 速度更快

# 筛选出字典中高于90的项
d = {x: randint(60, 100) for x in xrange(1, 21)}

print {k: v for k, v in d.iteritems() if v > 90}

# 筛选出集合中能被3整除的元素

s = set(data)

print {x for x in s if x % 3 == 0}
