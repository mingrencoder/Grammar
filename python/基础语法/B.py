# -*- coding: utf-8 -*-
from math import *
import time
# from math import sqrt

print sum((1,2,3,4,5))
print sum([1,2,3,4,5])


print '***********************函数式编程****************************'
print abs(-10)
print abs
# 定义变量f指向函数abs
f = abs
print f(-10)

print '----------高阶函数----------'
# 高阶函数能够接受另一个函数作为参数

def add(x, y, f):
  return f(x), f(y)
print add(1, -1, abs)

print '----map----'
# map()是 Python 内置的高阶函数，它接收一个函数 f 和一个 list，并通过把函数 f 依次作用在 list 的每个元素上，得到一个新的 list 并返回。
# 猜想：有点像代理模式哦
def  f(x):
  return x**2
print map(f,[1, 2, 3, 4])

print '----reduce----'
# reduce()函数接收的参数和 map()类似，一个函数 f，一个list，reduce()传入的函数 f 必须接收两个参数，
# reduce()对list的每个元素反复调用函数f，并返回最终结果值。
def f(x, y):
  return x + y

print reduce(f, [1, 2 ,3 ,4, 5], 100)

print '----filter----'
# filter()根据判断结果自动过滤掉不符合条件的元素，返回由符合条件元素组成的新list。
def is_not_empty(s):
  return s and len(s.strip()) > 0
# 当rm为空时，默认删除空白符（包括'\n', '\r', '\t', ' ')
print filter(is_not_empty, ['abc', '123', '','and',' ','\n\r\t']) #得到非空list
# 输出平方根为整数
def is_sqr(x):
    return sqrt(x) % 1 == 0

print filter(is_sqr, range(1, 101))

print '----sorted----'
# sorted()也是一个高阶函数，它可以接收一个比较函数来实现自定义排序，
# 比较函数的定义是，传入两个待比较的元素 x, y，如果 x 应该排在 y 的前面，返回 -1，如果 x 应该排在 y 的后面，返回 1。如果 x 和 y 相等，返回 0
print sorted([2,3,1,4,-1])
# 也可以自定义排序函数
def cmp_ignore_case(s1, s2):
    str1 = s1.upper()
    str2 = s2.upper()
    if str1 > str2:
      return 1
    elif str1 < str2:
      return -1
    else:
      return 0

print sorted(['bob', 'about', 'Zoo', 'Credit'], cmp_ignore_case)

print '----------返回函数----------'
def f():
    print 'call f()...'
    # 定义函数g:
    def g():
        print 'call g()...'
    # 返回函数g:
    return g
x = f()   # 调用f()
print x   # 变量x是f()返回的函数：
x()   # x指向函数，因此可以调用

# 由于可以返回函数，我们在后续代码里就可以决定到底要不要调用该函数，这样就实现了延迟计算
def calc_sum(lst):
    def lazy_sum():
        return sum(lst)
    return lazy_sum
# 调用calc_sum()并没有计算出结果，而是返回函数:
f = calc_sum([1, 2, 3, 4])
print f()

# 编写一个函数calc_prod(lst)，它接收一个list，返回一个函数，返回函数可以计算参数的乘积。
def calc_prod(lst):
    def mul(x, y):
        return x * y
    def result():
      return reduce(mul, lst)
    return result
# 或者是：
def calc_prod(lst):
    def prod():
        return reduce(lambda x, y : x * y, lst)
    return prod

f = calc_prod([1, 2, 3, 4])
print f()

print '----------python闭包----------'
# 在函数内部定义的函数和外部定义的函数是一样的，只是他们无法被外部访问：
# 像这种内层函数引用了外层函数的变量（参数也算变量），然后返回内层函数的情况，称为闭包（Closure）
# 闭包的特点是返回的函数还引用了外层函数的局部变量，所以，要正确使用闭包，就要确保引用的局部变量在函数返回后不能变
def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i*i
        fs.append(f)
    return fs

f1, f2, f3 = count()
print f1(), f2(), f3()
# 原因就是当count()函数返回了3个函数时，这3个函数所引用的变量 i 的值已经变成了3。
# 由于f1、f2、f3并没有被调用，所以，此时他们并未计算 i*i，当 f1 被调用时：i的值已经变为3
# 因此，返回函数不要引用任何循环变量，或者后续会发生变化的变量
print '----------改进----------'
def count():
    fs = []
    for i in range(1, 4):
        def f(j):
            def g():
                return j*j
            return g
        r = f(i)
        fs.append(r)
    return fs

f1, f2, f3 = count()
print f1(), f2(), f3()

print '----------匿名函数----------'
# 高阶函数可以接收函数做参数，有些时候，我们不需要显式地定义函数，直接传入匿名函数更方便。
# 在Python中，对匿名函数提供了有限支持。还是以map()函数为例:
# map(lambda x: x * x, [1, 2, 3])  其中的lambda x:x * x 相当于定义了一个函数返回x * x
#
# 关键字lambda 表示匿名函数，冒号前面的 x 表示函数参数。
#
# 匿名函数有个限制，就是只能有一个表达式，不写return，返回值就是该表达式的结果
myabs = lambda x: -x if x < 0 else x
print myabs(-1)
print myabs(1)

print '----------decorate装饰器----------'
# 定义一个函数，想要动态增加函数的一个功能
# 通过高阶函数 返回一个新函数

def f1(x):
    return x * 2;

def new_fn(f):
    def fn(x):
        print 'call ' + f.__name__ + '()'
        return f(x)
    return fn

# 调用装饰器函数
g1 = new_fn(f1)
print g1(5)

f1 = new_fn(f1) # f1的原始定义函数被彻底隐藏
print f1(5)


# Python的 decorator 本质上就是一个高阶函数，它接收一个函数作为参数，然后，返回一个新函数。
# 使用 decorator 用Python提供的 @ 语法，这样可以避免手动编写 f = decorate(f) 这样的代码。

def log(f):
    def fn(x):
        print 'call ' + f.__name__ + '()...'
        return f(x)
    return fn

# 阶乘
@log
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))

print factorial(5)

# 对于参数不是一个的函数，调用将报错
# 要让 @log 自适应任何参数定义的函数，可以利用Python的 *args 和 **kw，保证任意个数的参数总是能正常调用
def log(f):
    def fn(*args, **kw):
        print 'call ' + f.__name__ + '()...'
        return f(*args, **kw)
    return fn
# 现在，对于任意函数，@log 都能正常工作
print '-----无参decorate-----'
# 编写一个@performance，它可以打印出函数调用的时间。
def performance(f):
    def fn(*args, **kw):
        t1 = time.time()
        r = f(*args, **kw)
        t2 = time.time()
        print 'call %s() in %fs' % (f.__name__, (t2-t1))
        return r
    return fn

@performance
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))

print factorial(10)

print '-----带参decorate-----'
# 给 @performace 增加一个参数，允许传入's'或'ms'：
def performance(unit):
    def perf_decorator(f):
        def wrapper(*args, **kw):
            t1 = time.time()
            r = f(*args, **kw)
            t2 = time.time()
            t = (t2 - t1) * 1000 if unit=='ms' else (t2 - t1)
            print 'call %s() in %f %s' % (f.__name__, t, unit)
            return r
        return wrapper
    return perf_decorator

@performance('ms')
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))
print factorial(10)


print '***********************模块****************************'
# 将代码拆分放入不同的py文件中， 好处：
# 同一个名字的变量互不影响： 对于变量冲突的解决办法是，将不同的模块放入不同的包中
# 如何区分包和普通目录：包下面有一个__init__.py文件，而且每一层都有
#
# 要使用一个模块，我们必须首先导入该模块。Python使用import语句导入一个模块
# 如果使用 from...import 导入 log 函数，势必引起冲突。这时，可以给函数起个“别名”来避免冲突，如：
from math import log
from logging import log as logger   # logging的log现在取别名为logger

# Python的os.path模块提供了 isdir() 和 isfile()函数，请导入该模块，并调用函数判断指定的目录和文件是否存在
import os.path
print os.path.isdir(r'C:\Windows')
print os.path.isfile(r'C:\Windows\notepad.exe')

print '----------动态导入模块----------'
# 如果导入的模块不存在，Python解释器会报 ImportError 错误
# 利用ImportError错误，我们经常在Python中动态导入模块
try:
    from cStringIO import StringIO
except ImportError:
    from StringIO import StringIO
# 上述代码先尝试从cStringIO导入，如果失败了（比如cStringIO没有被安装），再尝试从StringIO导入。

print '----------使用__future__----------'
# 要在Python 2.7中引入3.x的除法规则，导入__future__的division，代码如下
# from __future__ import division
print 10 / 3

# 在Python 3.x中，字符串统一为unicode，不需要加前缀 u，而以字节存储的str则必须加前缀 b
# 利用__future__的unicode_literals在Python 2.7中编写unicode字符串，代码如下
# from __future__ import unicode_literals
s = 'am I an unicode?'
print isinstance(s, unicode)

print '----------安装第三方模块----------'
# 两种方式
# 1、easy_install
# 2、pip  （推荐，已内置到2.7.9）


print '***********************面向对象****************************'
# 类通过 class 关键字定义
class Person(object):
    pass
xiaoming = Person()
xiaohong = Person()
# 打印并输出两个实例是否相同
print xiaoming
print xiaohong
print xiaoming == xiaohong

# 实例的属性可以像普通变量一样进行操作，每个实例的属性可以不一样
p1 = Person()
p1.name = 'Bart'

p2 = Person()
p2.name = 'Adam'

p3 = Person()
p3.name = 'Lisa'

L1 = [p1, p2, p3]
L2 = sorted(L1, lambda p1, p2: cmp(p1.name, p2.name))
# 这里使用了前面排序高阶函数和匿名函数两个知识点
print L2[0].name
print L2[1].name
print L2[2].name

print '----------初始化实例属性----------'
# 在定义 Person 类时，可以为Person类添加一个特殊的__init__()方法，当创建实例时，__init__()方法被自动调用
# __init__() 方法的第一个参数必须是 self（也可以用别的名字，但建议使用习惯用法），后续参数则可以自由指定，和定义函数没有任何区别
# 相应地，创建实例时，就必须要提供除 self 以外的参数

# 要定义关键字参数，使用 **kw；
# 除了可以直接使用self.name = 'xxx'设置一个属性外，还可以通过 setattr(self, 'name', 'xxx') 设置属性。
class Person(object):
    def __init__(self, name, gender, birth, **kw):
        self.name = name
        self.gender = gender
        self.birth = birth
        for k, v in kw.iteritems():
            setattr(self, k, v)

xiaoming = Person('Xiao Ming', 'Male', '1990-1-1', job="student")
print xiaoming.name
print xiaoming.job

print '----------访问限制----------'
# 1、如果一个属性由双下划线开头(__)，该属性就无法被外部访问
# 2、如果一个属性以"__xxx__"的形式定义，那它又可以被外部访问了，以"__xxx__"定义的属性在Python的类中被称为特殊属性
# 有很多预定义的特殊属性可以使用，通常不要把普通属性用"__xxx__"定义
# 3、以单下划线开头的属性"_xxx"虽然也可以被外部访问，但是，按照习惯，他们不应该被外部访问
# _xxx 可以在子类中使用
# __xxx 不可以在子类中使用
class Person(object):
    def __init__(self, name, score):
        self.name = name
        self.__score = score

p = Person('Bob', 59)

print p.name
try:
    print p.__score
except AttributeError:
    print 'AttributeError'

print '----------创建类属性和实例方法----------'
# 实例属性每个实例各自拥有，互相独立，而类属性有且只有一份
# 由于Python是动态语言，类属性也是可以动态添加和修改的
# 但因为类属性只有一份，一处改变则所有实例访问到的类属性都改变了
#
# 这里的count相当于一个计数器的功能
class Person(object):
    count = 0
    address = 'beijing'
    def __init__(self, name):
        Person.count += 1
        self.name = name
    # 定义实例方法 它的第一个参数永远是 self，指向调用该方法的实例本身
    def printInfo(self):
        print count,self.name,Person.address

# 改变了类属性
Person.address = 'wuhan'

p1 = Person('Bob')
p1.printInfo()

p2 = Person('Alice')
p2.printInfo()

# 关于类属性和实例属性名字冲突
# 访问p1.address 时，优先查找实例属性，当实例属性和类属性重名时，实例属性优先级高，它将屏蔽掉对类属性的访问
p1.address = 'shanghai'
print '分别指向p1的实例属性和Person的类属性：',p1.address,Person.address # 打印shanghai wuhan
# 把 p1 的 address 实例属性删除后
del p1.address
print '指向Person的类属性：',p1.address,Person.address # 打印wuhan wuhan

print '----------方法也是属性----------'
# 因为方法也是一个属性，所以，它也可以动态地添加到实例上，只是需要用 types.MethodType() 把一个函数变为一个方法
# 由于属性可以是普通的值对象，如 str，int 等，也可以是方法，还可以是函数
class Person(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
        self.get_grade = lambda: 'A'

p1 = Person('Bob', 90)
print p1.get_grade
print p1.get_grade()
# 思考：p1.get_grade 为什么是函数而不是方法？
# 回答：直接把 lambda 函数赋值给 self.get_grade 和绑定方法有所不同，函数调用不需要传入 self，但是方法调用需要传入 self

print '----------定义类方法----------'
# 方法也分1――实例方法 和 2――类方法
# 在class中定义的全部是实例方法，实例方法第一个参数 self 是实例本身
# 通过标记一个 @classmethod，该方法将绑定到类上，而非类的实例，类方法的第一个参数将传入类本身，通常将参数名命名为 cls
#
# 注意：因为是在类上调用，而非实例上调用，因此类方法无法获得任何实例变量，只能获得类的引用
class Person(object):
    __count = 0

    @classmethod
    def how_many(cls):
        return cls.__count

    def __init__(self, name):
        self.name = name
        Person.__count += 1

print Person.how_many()
p1 = Person('Bob')
print Person.how_many()


print '***********************继承****************************'
# 一定要用 super(Student, self).__init__(name, gender) 去初始化父类
# 注意：self参数已在super()中传入，在__init__()中将隐式传递，不需要写出（也不能写）
class Person(object):
    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

class Teacher(Person):
    def __init__(self, name, gender, course):
        super(Teacher, self).__init__(name, gender)
        self.course = course

t = Teacher('James', 'Female', 'English')
print t.name
print t.course

print '----------判断类型----------'
# 函数isinstance()可以判断一个变量的类型，可以判断基本类型与自定义类

class Student(Person):
    def __init__(self, name, gender, score):
        super(Student, self).__init__(name, gender)
        self.score = score

p = Person('Tim', 'Male')
s = Student('Bob', 'Male', 88)
t = Teacher('Alice', 'Female', 'English')
print 'p属于Person类' if isinstance(p, Person) else 'p不属于Person类' # 三元表达式
print 'p属于Teacher类' if isinstance(p, Teacher) else 'p不属于Teacher类'
print 'p属于Student类' if isinstance(p, Student) else 'p不属于Student类'
print 's属于Person类' if isinstance(s, Person) else 's不属于Person类'
print 's属于Student类' if isinstance(s, Student) else 's不属于Student类'
print 's属于Teacher类' if isinstance(s, Teacher) else 's不属于Teacher类'

print '----------多态----------'

import json
class Student(object):
    def read(self):
        return r'["Tim", "Bob", "Alice"]'

s = Student()

print json.load(s)

print '----------多重继承----------'
# 多重继承的目的是从两种继承树中分别选择并继承出子类，以便组合功能使用
class A(object):
    def __init__(self, a):
        print 'init A...'
        self.a = a

class B(A):
    def __init__(self, a):
        super(B, self).__init__(a)
        print 'init B...'

class C(A):
    def __init__(self, a):
        super(C, self).__init__(a)
        print 'init C...'

class D(B, C):
    def __init__(self, a):
        super(D, self).__init__(a)
        print 'init D...'
# D 同时继承自 B 和 C，也就是 D 拥有了 A、B、C 的全部功能。
# 多重继承通过 super()调用__init__()方法时，A 虽然被继承了两次，但__init__()只调用一次
d = D('d')

print '----------获取对象信息----------'
# 可以用 type() 函数获取变量的类型，它返回一个 Type 对象
print type(123)
print type(s)
# 可以用 dir() 函数获取变量的所有属性
print dir(123)
print dir(t)
print '----过滤----'
def getUs(s):
    return s and s.find('__') # find方法查找字符串，默认值为0，找不到则为-1
print filter(getUs, dir(t))

print getattr(t, 'name', 'haha') # 如果不存在name属性，则返回haha
setattr(s, 'course', 'Chinese')
print getattr(s, 'course')


print '***********************定制类****************************'
# 特殊方法：定义在class中，不需要直接调用，Python中某些函数或操作符会调用对应方法
# __str__() 相当于toString()
# __len__()
# __cmp__() 等等

# Python 定义了__str__()和__repr__()两种方法，__str__()用于显示给用户，而__repr__()用于显示给开发人员
class Person(object):

    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

    def __str__(self):
        return '(Person: %s, %s)' % (self.name, self.gender)

    __repr__ = __str__# 有一个偷懒的定义__repr__的方法：
    # Python的 sorted() 按照默认的比较函数 cmp 排序，但是，如果对一组 Student 类的实例排序时，就必须提供我们自己的特殊方法 __cmp__()：
    def __cmp__(self, s):
        if self.name < s.name:
            return -1
        elif self.name > s.name:
            return 1
        return 0
        # return cmp(self.name, s.name) 或者这种方法
    def __len__(self):
        return len(self.name)

p = Person('Bobbbb', 'male')
print p
L = [Person('Tim', 99), Person('Bob', 88), Person('Alice', 77)]
print sorted(L)
#只要正确实现了__len__()方法，就可以用len()函数返回Students实例的“长度”：
print 'length of name: ', len(p)

# 编写一个Fib类，print Fib(10) 可以打印出数列的前 10 个元素，len(Fib(10))可以正确返回数列的个数10
class Fib(object):

    def __init__(self, num):
        a, b, L = 0, 1, []
        for n in range(num):
            L.append(a)
            a, b = b, a + b
        self.numbers = L

    def __str__(self):
        return str(self.numbers)

    def __len__(self):
        return len(self.numbers)

f = Fib(10)
print f
print len(f)

# a, b = b, a + b
# 相当于：
# t = a
# a = b
# b = t+b

print '----------数学运算----------'
# Python 提供的基本数据类型 int、float 可以做整数和浮点的四则运算以及乘方等运算
# 四则运算不局限于int和float，还可以是有理数、矩阵等
class Rational(object):
    def __init__(self, p, q):
        self.p = p
        self.q = q
    def __add__(self, r):
        return Rational(self.p * r.q + self.q * r.p, self.q * r.q)
    def __str__(self):
        return '%s/%s' % (self.p, self.q)
    __repr__ = __str__

r1 = Rational(1, 3)
r2 = Rational(1, 2)
print r1 + r2

# 如果运算结果是 6/8，在显示的时候需要归约到最简形式3/4
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

class Rational(object):
    def __init__(self, p, q):
        self.p = p
        self.q = q

    def __add__(self, r):
        return Rational(self.p * r.q + self.q * r.p, self.q * r.q)

    def __sub__(self, r):
        return Rational(self.p * r.q - self.q * r.p, self.q * r.q)

    def __mul__(self, r):
        return Rational(self.p * r.p, self.q * r.q)

    def __div__(self, r):
        return Rational(self.p * r.q, self.q * r.p)

    def __str__(self):
        g = gcd(self.p, self.q)
        return '%s/%s' % (self.p / g, self.q / g)

    def __int__(self):
        return self.p // self.q

    def __float__(self):
        return float(self.p) / self.q

    __repr__ = __str__

r1 = Rational(1, 2)
r2 = Rational(1, 4)
print r1 + r2
print r1 - r2
print r1 * r2
print r1 / r2

# 如果要把 Rational 转为 int，需要使用int()
# 要让int()函数正常工作，只需要实现特殊方法__int__():
print int(Rational(7, 2))
print int(Rational(1, 3))
print float(Rational(7, 2))
print float(Rational(1, 3))

print '----------@property----------'
# 用装饰器函数把 get/set 方法“装饰”成属性调用
class SS(object):
    def __init__(self, name, score):
        self.name = name
        self.__score = score
    @property
    def score(self):
        return self.__score
    @score.setter
    def score(self, score):
        if score < 0 or score > 100:
            raise ValueError('invalid score')
        self.__score = score


# 注意: 第一个score(self)是get方法，用@property装饰，
# 第二个score(self, score)是set方法，用@score.setter装饰，
# @score.setter是前一个@property装饰后的副产品
s = SS('Bob', 59)
s.score = 60
print s.score
# s.score = 1000 ??

print '----------限制添加的属性__slots__方法----------'
# __slots__是指一个类允许的属性列表
class Student(object):
    __slots__ = ('name', 'gender', 'score')
    def __init__(self, name, gender, score):
        self.name = name
        self.gender = gender
        self.score = score

s = Student('SSS', 'male', 88)
s.name = 'AAA'
try:
    s.a = 1
except AttributeError:
    print 'AttributeError'
# 如果不需要添加任意动态的属性，使用__slots__也能节省内存
# 注意：__slots__定义的属性仅对当前类起作用，对继承的子类是不起作用的！！

print '----------__call__----------'
# 一个类实例也可以变成一个可调用对象，只需要实现一个特殊方法__call__()
# 在Python中，函数也是对象，对象和函数的区别并不显著

# 下面是改进后的斐波那契数列类
class Fib(object):
    # def __init(self):
    #     pass
    def __call__(self, num):
        a, b, L = 0, 1, []
        for n in range(num):
            L.append(a)
            a, b = b, a + b
        return L

f = Fib()
print f(10)

