# -*- coding: utf-8 -*-
from math import *
import time
# from math import sqrt

print sum((1,2,3,4,5))
print sum([1,2,3,4,5])


print '***********************����ʽ���****************************'
print abs(-10)
print abs
# �������fָ����abs
f = abs
print f(-10)

print '----------�߽׺���----------'
# �߽׺����ܹ�������һ��������Ϊ����

def add(x, y, f):
  return f(x), f(y)
print add(1, -1, abs)

print '----map----'
# map()�� Python ���õĸ߽׺�����������һ������ f ��һ�� list����ͨ���Ѻ��� f ���������� list ��ÿ��Ԫ���ϣ��õ�һ���µ� list �����ء�
# ���룺�е������ģʽŶ
def  f(x):
  return x**2
print map(f,[1, 2, 3, 4])

print '----reduce----'
# reduce()�������յĲ����� map()���ƣ�һ������ f��һ��list��reduce()����ĺ��� f �����������������
# reduce()��list��ÿ��Ԫ�ط������ú���f�����������ս��ֵ��
def f(x, y):
  return x + y

print reduce(f, [1, 2 ,3 ,4, 5], 100)

print '----filter----'
# filter()�����жϽ���Զ����˵�������������Ԫ�أ������ɷ�������Ԫ����ɵ���list��
def is_not_empty(s):
  return s and len(s.strip()) > 0
# ��rmΪ��ʱ��Ĭ��ɾ���հ׷�������'\n', '\r', '\t', ' ')
print filter(is_not_empty, ['abc', '123', '','and',' ','\n\r\t']) #�õ��ǿ�list
# ���ƽ����Ϊ����
def is_sqr(x):
    return sqrt(x) % 1 == 0

print filter(is_sqr, range(1, 101))

print '----sorted----'
# sorted()Ҳ��һ���߽׺����������Խ���һ���ȽϺ�����ʵ���Զ�������
# �ȽϺ����Ķ����ǣ������������Ƚϵ�Ԫ�� x, y����� x Ӧ������ y ��ǰ�棬���� -1����� x Ӧ������ y �ĺ��棬���� 1����� x �� y ��ȣ����� 0
print sorted([2,3,1,4,-1])
# Ҳ�����Զ���������
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

print '----------���غ���----------'
def f():
    print 'call f()...'
    # ���庯��g:
    def g():
        print 'call g()...'
    # ���غ���g:
    return g
x = f()   # ����f()
print x   # ����x��f()���صĺ�����
x()   # xָ��������˿��Ե���

# ���ڿ��Է��غ����������ں���������Ϳ��Ծ�������Ҫ��Ҫ���øú�����������ʵ�����ӳټ���
def calc_sum(lst):
    def lazy_sum():
        return sum(lst)
    return lazy_sum
# ����calc_sum()��û�м������������Ƿ��غ���:
f = calc_sum([1, 2, 3, 4])
print f()

# ��дһ������calc_prod(lst)��������һ��list������һ�����������غ������Լ�������ĳ˻���
def calc_prod(lst):
    def mul(x, y):
        return x * y
    def result():
      return reduce(mul, lst)
    return result
# �����ǣ�
def calc_prod(lst):
    def prod():
        return reduce(lambda x, y : x * y, lst)
    return prod

f = calc_prod([1, 2, 3, 4])
print f()

print '----------python�հ�----------'
# �ں����ڲ�����ĺ������ⲿ����ĺ�����һ���ģ�ֻ�������޷����ⲿ���ʣ�
# �������ڲ㺯����������㺯���ı���������Ҳ���������Ȼ�󷵻��ڲ㺯�����������Ϊ�հ���Closure��
# �հ����ص��Ƿ��صĺ�������������㺯���ľֲ����������ԣ�Ҫ��ȷʹ�ñհ�����Ҫȷ�����õľֲ������ں������غ��ܱ�
def count():
    fs = []
    for i in range(1, 4):
        def f():
             return i*i
        fs.append(f)
    return fs

f1, f2, f3 = count()
print f1(), f2(), f3()
# ԭ����ǵ�count()����������3������ʱ����3�����������õı��� i ��ֵ�Ѿ������3��
# ����f1��f2��f3��û�б����ã����ԣ���ʱ���ǲ�δ���� i*i���� f1 ������ʱ��i��ֵ�Ѿ���Ϊ3
# ��ˣ����غ�����Ҫ�����κ�ѭ�����������ߺ����ᷢ���仯�ı���
print '----------�Ľ�----------'
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

print '----------��������----------'
# �߽׺������Խ��պ�������������Щʱ�����ǲ���Ҫ��ʽ�ض��庯����ֱ�Ӵ����������������㡣
# ��Python�У������������ṩ������֧�֡�������map()����Ϊ��:
# map(lambda x: x * x, [1, 2, 3])  ���е�lambda x:x * x �൱�ڶ�����һ����������x * x
#
# �ؼ���lambda ��ʾ����������ð��ǰ��� x ��ʾ����������
#
# ���������и����ƣ�����ֻ����һ�����ʽ����дreturn������ֵ���Ǹñ��ʽ�Ľ��
myabs = lambda x: -x if x < 0 else x
print myabs(-1)
print myabs(1)

print '----------decorateװ����----------'
# ����һ����������Ҫ��̬���Ӻ�����һ������
# ͨ���߽׺��� ����һ���º���

def f1(x):
    return x * 2;

def new_fn(f):
    def fn(x):
        print 'call ' + f.__name__ + '()'
        return f(x)
    return fn

# ����װ��������
g1 = new_fn(f1)
print g1(5)

f1 = new_fn(f1) # f1��ԭʼ���庯������������
print f1(5)


# Python�� decorator �����Ͼ���һ���߽׺�����������һ��������Ϊ������Ȼ�󣬷���һ���º�����
# ʹ�� decorator ��Python�ṩ�� @ �﷨���������Ա����ֶ���д f = decorate(f) �����Ĵ��롣

def log(f):
    def fn(x):
        print 'call ' + f.__name__ + '()...'
        return f(x)
    return fn

# �׳�
@log
def factorial(n):
    return reduce(lambda x,y: x*y, range(1, n+1))

print factorial(5)

# ���ڲ�������һ���ĺ��������ý�����
# Ҫ�� @log ����Ӧ�κβ�������ĺ�������������Python�� *args �� **kw����֤��������Ĳ�����������������
def log(f):
    def fn(*args, **kw):
        print 'call ' + f.__name__ + '()...'
        return f(*args, **kw)
    return fn
# ���ڣ��������⺯����@log ������������
print '-----�޲�decorate-----'
# ��дһ��@performance�������Դ�ӡ���������õ�ʱ�䡣
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

print '-----����decorate-----'
# �� @performace ����һ��������������'s'��'ms'��
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


print '***********************ģ��****************************'
# �������ַ��벻ͬ��py�ļ��У� �ô���
# ͬһ�����ֵı�������Ӱ�죺 ���ڱ�����ͻ�Ľ���취�ǣ�����ͬ��ģ����벻ͬ�İ���
# ������ְ�����ͨĿ¼����������һ��__init__.py�ļ�������ÿһ�㶼��
#
# Ҫʹ��һ��ģ�飬���Ǳ������ȵ����ģ�顣Pythonʹ��import��䵼��һ��ģ��
# ���ʹ�� from...import ���� log �������Ʊ������ͻ����ʱ�����Ը�����������������������ͻ���磺
from math import log
from logging import log as logger   # logging��log����ȡ����Ϊlogger

# Python��os.pathģ���ṩ�� isdir() �� isfile()�������뵼���ģ�飬�����ú����ж�ָ����Ŀ¼���ļ��Ƿ����
import os.path
print os.path.isdir(r'C:\Windows')
print os.path.isfile(r'C:\Windows\notepad.exe')

print '----------��̬����ģ��----------'
# ��������ģ�鲻���ڣ�Python�������ᱨ ImportError ����
# ����ImportError�������Ǿ�����Python�ж�̬����ģ��
try:
    from cStringIO import StringIO
except ImportError:
    from StringIO import StringIO
# ���������ȳ��Դ�cStringIO���룬���ʧ���ˣ�����cStringIOû�б���װ�����ٳ��Դ�StringIO���롣

print '----------ʹ��__future__----------'
# Ҫ��Python 2.7������3.x�ĳ������򣬵���__future__��division����������
# from __future__ import division
print 10 / 3

# ��Python 3.x�У��ַ���ͳһΪunicode������Ҫ��ǰ׺ u�������ֽڴ洢��str������ǰ׺ b
# ����__future__��unicode_literals��Python 2.7�б�дunicode�ַ�������������
# from __future__ import unicode_literals
s = 'am I an unicode?'
print isinstance(s, unicode)

print '----------��װ������ģ��----------'
# ���ַ�ʽ
# 1��easy_install
# 2��pip  ���Ƽ��������õ�2.7.9��


print '***********************�������****************************'
# ��ͨ�� class �ؼ��ֶ���
class Person(object):
    pass
xiaoming = Person()
xiaohong = Person()
# ��ӡ���������ʵ���Ƿ���ͬ
print xiaoming
print xiaohong
print xiaoming == xiaohong

# ʵ�������Կ�������ͨ����һ�����в�����ÿ��ʵ�������Կ��Բ�һ��
p1 = Person()
p1.name = 'Bart'

p2 = Person()
p2.name = 'Adam'

p3 = Person()
p3.name = 'Lisa'

L1 = [p1, p2, p3]
L2 = sorted(L1, lambda p1, p2: cmp(p1.name, p2.name))
# ����ʹ����ǰ������߽׺�����������������֪ʶ��
print L2[0].name
print L2[1].name
print L2[2].name

print '----------��ʼ��ʵ������----------'
# �ڶ��� Person ��ʱ������ΪPerson�����һ�������__init__()������������ʵ��ʱ��__init__()�������Զ�����
# __init__() �����ĵ�һ������������ self��Ҳ�����ñ�����֣�������ʹ��ϰ���÷����������������������ָ�����Ͷ��庯��û���κ�����
# ��Ӧ�أ�����ʵ��ʱ���ͱ���Ҫ�ṩ�� self ����Ĳ���

# Ҫ����ؼ��ֲ�����ʹ�� **kw��
# ���˿���ֱ��ʹ��self.name = 'xxx'����һ�������⣬������ͨ�� setattr(self, 'name', 'xxx') �������ԡ�
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

print '----------��������----------'
# 1�����һ��������˫�»��߿�ͷ(__)�������Ծ��޷����ⲿ����
# 2�����һ��������"__xxx__"����ʽ���壬�����ֿ��Ա��ⲿ�����ˣ���"__xxx__"�����������Python�����б���Ϊ��������
# �кܶ�Ԥ������������Կ���ʹ�ã�ͨ����Ҫ����ͨ������"__xxx__"����
# 3���Ե��»��߿�ͷ������"_xxx"��ȻҲ���Ա��ⲿ���ʣ����ǣ�����ϰ�ߣ����ǲ�Ӧ�ñ��ⲿ����
# _xxx ������������ʹ��
# __xxx ��������������ʹ��
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

print '----------���������Ժ�ʵ������----------'
# ʵ������ÿ��ʵ������ӵ�У����������������������ֻ��һ��
# ����Python�Ƕ�̬���ԣ�������Ҳ�ǿ��Զ�̬��Ӻ��޸ĵ�
# ����Ϊ������ֻ��һ�ݣ�һ���ı�������ʵ�����ʵ��������Զ��ı���
#
# �����count�൱��һ���������Ĺ���
class Person(object):
    count = 0
    address = 'beijing'
    def __init__(self, name):
        Person.count += 1
        self.name = name
    # ����ʵ������ ���ĵ�һ��������Զ�� self��ָ����ø÷�����ʵ������
    def printInfo(self):
        print count,self.name,Person.address

# �ı���������
Person.address = 'wuhan'

p1 = Person('Bob')
p1.printInfo()

p2 = Person('Alice')
p2.printInfo()

# ���������Ժ�ʵ���������ֳ�ͻ
# ����p1.address ʱ�����Ȳ���ʵ�����ԣ���ʵ�����Ժ�����������ʱ��ʵ���������ȼ��ߣ��������ε��������Եķ���
p1.address = 'shanghai'
print '�ֱ�ָ��p1��ʵ�����Ժ�Person�������ԣ�',p1.address,Person.address # ��ӡshanghai wuhan
# �� p1 �� address ʵ������ɾ����
del p1.address
print 'ָ��Person�������ԣ�',p1.address,Person.address # ��ӡwuhan wuhan

print '----------����Ҳ������----------'
# ��Ϊ����Ҳ��һ�����ԣ����ԣ���Ҳ���Զ�̬����ӵ�ʵ���ϣ�ֻ����Ҫ�� types.MethodType() ��һ��������Ϊһ������
# �������Կ�������ͨ��ֵ������ str��int �ȣ�Ҳ�����Ƿ������������Ǻ���
class Person(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
        self.get_grade = lambda: 'A'

p1 = Person('Bob', 90)
print p1.get_grade
print p1.get_grade()
# ˼����p1.get_grade Ϊʲô�Ǻ��������Ƿ�����
# �ش�ֱ�Ӱ� lambda ������ֵ�� self.get_grade �Ͱ󶨷���������ͬ���������ò���Ҫ���� self�����Ƿ���������Ҫ���� self

print '----------�����෽��----------'
# ����Ҳ��1����ʵ������ �� 2�����෽��
# ��class�ж����ȫ����ʵ��������ʵ��������һ������ self ��ʵ������
# ͨ�����һ�� @classmethod���÷������󶨵����ϣ��������ʵ�����෽���ĵ�һ�������������౾��ͨ��������������Ϊ cls
#
# ע�⣺��Ϊ�������ϵ��ã�����ʵ���ϵ��ã�����෽���޷�����κ�ʵ��������ֻ�ܻ���������
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


print '***********************�̳�****************************'
# һ��Ҫ�� super(Student, self).__init__(name, gender) ȥ��ʼ������
# ע�⣺self��������super()�д��룬��__init__()�н���ʽ���ݣ�����Ҫд����Ҳ����д��
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

print '----------�ж�����----------'
# ����isinstance()�����ж�һ�����������ͣ������жϻ����������Զ�����

class Student(Person):
    def __init__(self, name, gender, score):
        super(Student, self).__init__(name, gender)
        self.score = score

p = Person('Tim', 'Male')
s = Student('Bob', 'Male', 88)
t = Teacher('Alice', 'Female', 'English')
print 'p����Person��' if isinstance(p, Person) else 'p������Person��' # ��Ԫ���ʽ
print 'p����Teacher��' if isinstance(p, Teacher) else 'p������Teacher��'
print 'p����Student��' if isinstance(p, Student) else 'p������Student��'
print 's����Person��' if isinstance(s, Person) else 's������Person��'
print 's����Student��' if isinstance(s, Student) else 's������Student��'
print 's����Teacher��' if isinstance(s, Teacher) else 's������Teacher��'

print '----------��̬----------'

import json
class Student(object):
    def read(self):
        return r'["Tim", "Bob", "Alice"]'

s = Student()

print json.load(s)

print '----------���ؼ̳�----------'
# ���ؼ̳е�Ŀ���Ǵ����ּ̳����зֱ�ѡ�񲢼̳г����࣬�Ա���Ϲ���ʹ��
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
# D ͬʱ�̳��� B �� C��Ҳ���� D ӵ���� A��B��C ��ȫ�����ܡ�
# ���ؼ̳�ͨ�� super()����__init__()����ʱ��A ��Ȼ���̳������Σ���__init__()ֻ����һ��
d = D('d')

print '----------��ȡ������Ϣ----------'
# ������ type() ������ȡ���������ͣ�������һ�� Type ����
print type(123)
print type(s)
# ������ dir() ������ȡ��������������
print dir(123)
print dir(t)
print '----����----'
def getUs(s):
    return s and s.find('__') # find���������ַ�����Ĭ��ֵΪ0���Ҳ�����Ϊ-1
print filter(getUs, dir(t))

print getattr(t, 'name', 'haha') # ���������name���ԣ��򷵻�haha
setattr(s, 'course', 'Chinese')
print getattr(s, 'course')


print '***********************������****************************'
# ���ⷽ����������class�У�����Ҫֱ�ӵ��ã�Python��ĳЩ���������������ö�Ӧ����
# __str__() �൱��toString()
# __len__()
# __cmp__() �ȵ�

# Python ������__str__()��__repr__()���ַ�����__str__()������ʾ���û�����__repr__()������ʾ��������Ա
class Person(object):

    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

    def __str__(self):
        return '(Person: %s, %s)' % (self.name, self.gender)

    __repr__ = __str__# ��һ��͵���Ķ���__repr__�ķ�����
    # Python�� sorted() ����Ĭ�ϵıȽϺ��� cmp ���򣬵��ǣ������һ�� Student ���ʵ������ʱ���ͱ����ṩ�����Լ������ⷽ�� __cmp__()��
    def __cmp__(self, s):
        if self.name < s.name:
            return -1
        elif self.name > s.name:
            return 1
        return 0
        # return cmp(self.name, s.name) �������ַ���
    def __len__(self):
        return len(self.name)

p = Person('Bobbbb', 'male')
print p
L = [Person('Tim', 99), Person('Bob', 88), Person('Alice', 77)]
print sorted(L)
#ֻҪ��ȷʵ����__len__()�������Ϳ�����len()��������Studentsʵ���ġ����ȡ���
print 'length of name: ', len(p)

# ��дһ��Fib�࣬print Fib(10) ���Դ�ӡ�����е�ǰ 10 ��Ԫ�أ�len(Fib(10))������ȷ�������еĸ���10
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
# �൱�ڣ�
# t = a
# a = b
# b = t+b

print '----------��ѧ����----------'
# Python �ṩ�Ļ����������� int��float �����������͸�������������Լ��˷�������
# �������㲻������int��float�����������������������
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

# ����������� 6/8������ʾ��ʱ����Ҫ��Լ�������ʽ3/4
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

# ���Ҫ�� Rational תΪ int����Ҫʹ��int()
# Ҫ��int()��������������ֻ��Ҫʵ�����ⷽ��__int__():
print int(Rational(7, 2))
print int(Rational(1, 3))
print float(Rational(7, 2))
print float(Rational(1, 3))

print '----------@property----------'
# ��װ���������� get/set ������װ�Ρ������Ե���
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


# ע��: ��һ��score(self)��get��������@propertyװ�Σ�
# �ڶ���score(self, score)��set��������@score.setterװ�Σ�
# @score.setter��ǰһ��@propertyװ�κ�ĸ���Ʒ
s = SS('Bob', 59)
s.score = 60
print s.score
# s.score = 1000 ??

print '----------������ӵ�����__slots__����----------'
# __slots__��ָһ��������������б�
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
# �������Ҫ������⶯̬�����ԣ�ʹ��__slots__Ҳ�ܽ�ʡ�ڴ�
# ע�⣺__slots__��������Խ��Ե�ǰ�������ã��Լ̳е������ǲ������õģ���

print '----------__call__----------'
# һ����ʵ��Ҳ���Ա��һ���ɵ��ö���ֻ��Ҫʵ��һ�����ⷽ��__call__()
# ��Python�У�����Ҳ�Ƕ��󣬶���ͺ��������𲢲�����

# �����ǸĽ����쳲�����������
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

