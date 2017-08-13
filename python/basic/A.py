# -*- coding: utf-8 -*-
import math

print '%%%%****' * 10
print '***********************基本类型****************************'
# Python支持整数、浮点数、字符串、布尔值、空值
# 空值
print None

# 在Python程序中，变量是用一个变量名表示，变量名必须是大小写英文、数字和下划线（_）的组合，且不能用数字开头

# 多个字符串转义
print r'"哈哈"'  'haha' #输出"哈哈"haha
print '\'' #打印单引号
# 多行字符串转义
print '''haha
"哈哈"'''
# 0 空字符串 null 都视为false
# a or b     若a为true，结果返回a 若a为false，结果返回b
a = 'python'
print a or 'world'
print a or ''

b = ''
print b or 'world'

print '--------------------'
# a and b    若a为true，结果返回b 若a为false 结果返回a 即空
a = 'python'
print a and 'world'

b = ''
print b and 'world'

print '**********************list和tuple*****************************'

# list
L = ['adam', 95.5, True, 'lisa', 85, True, 'bart', 59, False];
print L[4]
# 倒数第二
print L[-2]
# 插入
L.insert(3, 'haha')
# 删除
L.pop(4)
print L
empty =  []
print empty

# tuple是另一种有序的列表，中文翻译为“ 元组 ”。tuple 和 list 非常类似，但是，tuple只可读，不可写
# 因为用()定义单元素的tuple有歧义，所以 Python 规定，单元素 tuple 要多加一个逗号“,”，这样就避免了歧义：
t = ('ss',)
print t
# list和tuple之间的转化
t = ('a', 'b', ['A', 'B'])
t = list(t)
t[2] = ('a', 'b')
t = tuple(t)
print t

print '**********************条件判断和循环*****************************'

# 必须四个空格 python对缩进敏感
score = 85
if score >=90:
    print 'excellent'
elif score >=80:
    print 'good'
elif score >=60:
    print 'passed'
else:
    print 'failed'

# for循环 可以迭代list和tuple元素
L = [75, 92, 59, 68]
sum = 0.0
for s in L:
    sum += s
print '平均数： ' + str(sum/4)

# while循环 不可以迭代list或tuple
sum = 0
x = 1
while x<100:
  if x%2 == 1:
    sum += x
    x += 2
print '100以内奇数的和为： ' + str(sum) #字符串与int类型连接，需要进行str的转化，也可以用逗号连接 但是会多一个空格

# 用break跳出while循环
sum = 0
x = 1
n = 1
while True:
    sum += x
    x = 2**n
    n += 1
    if n > 20:
        break;
print '1+2+4+…… 20项的和为： ' + str(sum)

# 用continue
sum = 0
x = 0
while True:
    x += 1;
    if x > 100:
        break
    if x%2 == 0:
        continue
    sum += x;
print '100以内奇数的和为： ' + str(sum)

# for x in [1,2,3,4,5,6,7,8,9]:
#     for y in [0,1,2,3,4,5,6,7,8,9]:
#         if x < y:
#             print x * 10 + y

print '*********************dict和set类型******************************'

# dict
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59,
    'Paul':75
}
print len(d)

# 可以简单地使用 d[key] 的形式来查找对应的 value，list 必须使用索引返回对应的元素，而dict使用key：

# 要避免 KeyError 发生，有两个办法：
# 一是先判断一下 key 是否存在，用 in 操作符：
# if 'Paul' in d:
#     print d['Paul']
# 二是使用dict本身提供的一个 get 方法，在Key不存在的时候，返回None

# 利用占位符输出
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59
}
for key in ['Adam', 'Lisa', 'Bart']:
    print "%s: %d"%(key, d[key])

# dict的第一个特点是查找速度快，无论dict有10个元素还是10万个元素，查找速度都一样
# dict的第二个特点就是存储的key-value序对是没有顺序的！
# dict的第三个特点是作为 key 的元素必须不可变    Python的基本类型如字符串、整数、浮点数都是不可变的，都可以作为 key

print '--------------------'
# 遍历
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59
}
d['Paul'] = 72 #插入一条数据，若key已存在则更新value
for key in d:
    print key + ":" , d[key]

print '***************************************************'
# set
s = set(['A','B','C','A'])
print s
# 由于set存储的是无序集合，所以我们没法通过索引来访问。
# 访问 set中的某个元素实际上就是判断一个元素是否在set中。

# set存储的元素和dict的key类似，必须是不变对象，因此，任何可变对象是不能放入set中的。最后，set存储的元素也是没有顺序的。
months = set(['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul','Aug','Sep','Oct','Nov','Dec'])
x1 = 'Feb'
x2 = 'Sun'

if x1 in months:
    print 'x1: ok'
else:
    print 'x1: error'
if x2 in months:
    print 'x2: ok'
else:
    print 'x2: error'

s = set([('Adam', 95), ('Lisa', 85), ('Bart', 59)])
# 更新
s.add(('hahaha',88)) #增加
s.remove(('Lisa', 85)) #删除
# 遍历
for x in s:
    print x[0] + ":" , x[1]

print '***********************函数****************************'
# help(abs)
# help(xrange)

print(abs(-1))

# 从1+2^1+……+100^2
L = []
x = 1
while x <= 10:
    L.append(pow(x,2))
    x += 1
for x in L:
    print x
print '----------range----------'
# 下面利用range函数实现
a = range(1, 11)
L = [i**2 for i in a]
for x in L:
    print x

# return None可以简写为return

def square_of_sum(L):
    sum = 0
    for i in L:
        sum += i*i
    return sum

print "该list每个元素的平方和为：%d"%square_of_sum([1, 2, 3, 4, 5])
print "该list每个元素的平方和为：%d"%square_of_sum([-5, 0, 5, 15, 25])

# 在语法上，返回一个tuple可以省略括号，Python的函数返回多值其实就是返回一个tuple

print '----------一元二次方程----------'
def quadratic_equation(a, b, c):
    t = b**2 - 4*a*c
    if t > 0:
        d = math.sqrt(t)
        a1 = (-b+d)/(2*a)
        a2 = (-b-d)/(2*a)
        return a1, a2
    elif t == 0:
        return (-b)/(2*a)
    else:
        return

print "函数的解为：",quadratic_equation(1, -6, 5)  #两个解
print "函数的解为：",quadratic_equation(1, -6, 50) #无解


print '连接'.join(('aaa', 'bbb', 'ccc'))


# 递归函数
# 先找出如何处理第n个数据，再逐渐细化
print '----------阶乘----------'
# 阶乘
def fact(n):
    if n == 1:
        return 1
    return n * fact(n-1)

print fact(4)

print '----------汉诺塔----------'
# 汉诺塔
B=[] #设置操作过程列表
def move(n, a, b, c):
    if n == 1:
        buzhou = a,str(n),'-->',c,str(n) #一个圆盘需要从A到C操作步骤
        B.append(buzhou) #向列表中添加操作步骤
        return
    move(n-1, a, c, b) #将A柱的n-1个盘移到B柱
    buzhou = a,str(n),'-->',c,str(n) #将A柱的第n个盘移到C柱操作步骤
    B.append(buzhou) #向列表中添加操作步骤
    move(n-1, b, a, c) #将过渡柱子B上n-1个圆盘B移动到目标柱子C

move(6,'A','B','C') #2**64-1，64次太大，这里用6个盘子
print'共需操作'+str(len(B))+'次','操作过程为\n',B #计算6个盘子的步骤数及操作过程

print '----------汉诺塔简化版----------'
def move(n, a, b, c):
    if n == 1:
        print a,'-->',c
        return
    move(n-1, a, c ,b)
    print a, '-->',c
    move(n-1, b, a, c)
move(4, 'A', 'B', 'C')

# 定义默认参数
# 由于函数的参数按从左到右的顺序匹配，所以默认参数只能定义在必需参数的后面
print '----------默认参数----------'
def greet(name='world'):
    print 'Hello,' + name + '.'

greet()
greet('Bart')

# 可变参数
# Python解释器会把传入的一组参数组装成一个tuple传递给可变参数，因此，在函数内部，直接把变量 args 看成一个 tuple 就好了
def fn(*args):
    print args

fn('a')
fn('a','b')
fn('a',2)

def average(*args):
    sum = 0.0
    if len(args) == 0:
        return sum
    for x in args:
        sum += x
    return sum/len(args)

print average()
print average(1, 2)
print average(1, 2, 2, 3, 4)

print '***********************切片****************************'

print '----------对list或tuple切片----------'
# 对这种经常取指定索引范围的操作，用循环十分繁琐，因此，Python提供了切片（Slice）操作符，能大大简化这种操作
L = range(1, 101)

print L[:]
print L[90:] #后10个数
print L[-3:]
print L[:10] # 前10个数；
#下面两者实现效果一样
print L[-8:-1:2]
print L[-8:-1][::2]

print L[2::3] # 3的倍数；
print L[4:50:5] # 不大于50的5的倍数。
print '----------对字符串切片----------'
print 'ABCDEFG'[:3]
print 'ABCDEFG'[::2]

def firstCharUpper(s):
    return s[:1].upper()+s[1:]

print firstCharUpper('hello')

print '***********************迭代****************************'
for i in range(1,101):
    if i%7 == 0:
        print i
# 使用 enumerate() 函数，我们可以在for循环中同时绑定索引index和元素name
# 实际上迭代的每一个元素实际上是一个tuple

d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59,
    'Paul':75
}

for t in enumerate(d):
    print t
# 也可以写成
for index, name in enumerate(range(5)):
    print index, '-', name

# zip函数，将两个list合并为一个
print zip([10, 20, 30], ['A', 'B', 'C'])

L = ['Adam', 'Lisa', 'Bart', 'Paul']
for index, name in zip(range(1,len(L)+1),L):
    print index, '-', name

print '----------对dict迭代----------'
# dict 对象有一个 values() 方法，这个方法把dict转换成一个包含所有value的list，这样，我们迭代的就是 dict的每一个 value：
d = { 'Adam': 95, 'Lisa': 85, 'Bart': 59 }
print d.itervalues() #速度更快
print d.values()
# items() 方法把dict对象转换成了包含tuple的list，我们对这个list进行迭代，可以同时获得key和value：
print d.items()
for key, value in d.items():
    print key, ':', value
# items() 也有一个对应的 iteritems()，iteritems() 不把dict转换成list，而是在迭代过程中不断给出 tuple，所以， iteritems() 不占用额外的内存。
print '----------iteritems----------'
for key, value in d.iteritems():
    print key, ':', value

print '***********************列表生成式****************************'
print [i*(i+1) for i in range(1,10,2)]

# 使用for循环的迭代不仅可以迭代普通的list，还可以迭代dict。
tds = ['<tr><td>%s</td><td>%s</td></tr>' % (name, score) for name, score in d.iteritems()]
print '<table>'
print '<tr><th>Name</th><th>Score</th><tr>'
print '\n'.join(tds) #字符串的join()方法可以把一个 list 拼接成一个字符串。
print '</table>'

# 列表生成式的 for 循环后面还可以加上 if 判断
print [x * x for x in range(1, 11) if x % 2 == 0]

# 1. isinstance(x, str) 可以判断变量 x 是否是字符串；
# 2. 字符串的 upper() 方法可以返回大写的字母。
def toUppers(L):
    return [x.upper() for x in L if isinstance(x,str)]
print toUppers(['Hello', 'world', 101])

# 循环套嵌
L = []
for m in 'ABC':
    for n in '123':
        L.append(m+n)
print L
# 可以简化为下面写法
print [m+n for m in 'ABC' for n in '123']
# 对称三位数
print [100 * x + 10 * y + x for x in range(1, 10) for y in range(0, 10)]
