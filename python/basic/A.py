# -*- coding: utf-8 -*-
import math

print '%%%%****' * 10
print '***********************��������****************************'
# Python֧�����������������ַ���������ֵ����ֵ
# ��ֵ
print None

# ��Python�����У���������һ����������ʾ�������������Ǵ�СдӢ�ġ����ֺ��»��ߣ�_������ϣ��Ҳ��������ֿ�ͷ

# ����ַ���ת��
print r'"����"'  'haha' #���"����"haha
print '\'' #��ӡ������
# �����ַ���ת��
print '''haha
"����"'''
# 0 ���ַ��� null ����Ϊfalse
# a or b     ��aΪtrue���������a ��aΪfalse���������b
a = 'python'
print a or 'world'
print a or ''

b = ''
print b or 'world'

print '--------------------'
# a and b    ��aΪtrue���������b ��aΪfalse �������a ����
a = 'python'
print a and 'world'

b = ''
print b and 'world'

print '**********************list��tuple*****************************'

# list
L = ['adam', 95.5, True, 'lisa', 85, True, 'bart', 59, False];
print L[4]
# �����ڶ�
print L[-2]
# ����
L.insert(3, 'haha')
# ɾ��
L.pop(4)
print L
empty =  []
print empty

# tuple����һ��������б����ķ���Ϊ�� Ԫ�� ����tuple �� list �ǳ����ƣ����ǣ�tupleֻ�ɶ�������д
# ��Ϊ��()���嵥Ԫ�ص�tuple�����壬���� Python �涨����Ԫ�� tuple Ҫ���һ�����š�,���������ͱ��������壺
t = ('ss',)
print t
# list��tuple֮���ת��
t = ('a', 'b', ['A', 'B'])
t = list(t)
t[2] = ('a', 'b')
t = tuple(t)
print t

print '**********************�����жϺ�ѭ��*****************************'

# �����ĸ��ո� python����������
score = 85
if score >=90:
    print 'excellent'
elif score >=80:
    print 'good'
elif score >=60:
    print 'passed'
else:
    print 'failed'

# forѭ�� ���Ե���list��tupleԪ��
L = [75, 92, 59, 68]
sum = 0.0
for s in L:
    sum += s
print 'ƽ������ ' + str(sum/4)

# whileѭ�� �����Ե���list��tuple
sum = 0
x = 1
while x<100:
  if x%2 == 1:
    sum += x
    x += 2
print '100���������ĺ�Ϊ�� ' + str(sum) #�ַ�����int�������ӣ���Ҫ����str��ת����Ҳ�����ö������� ���ǻ��һ���ո�

# ��break����whileѭ��
sum = 0
x = 1
n = 1
while True:
    sum += x
    x = 2**n
    n += 1
    if n > 20:
        break;
print '1+2+4+���� 20��ĺ�Ϊ�� ' + str(sum)

# ��continue
sum = 0
x = 0
while True:
    x += 1;
    if x > 100:
        break
    if x%2 == 0:
        continue
    sum += x;
print '100���������ĺ�Ϊ�� ' + str(sum)

# for x in [1,2,3,4,5,6,7,8,9]:
#     for y in [0,1,2,3,4,5,6,7,8,9]:
#         if x < y:
#             print x * 10 + y

print '*********************dict��set����******************************'

# dict
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59,
    'Paul':75
}
print len(d)

# ���Լ򵥵�ʹ�� d[key] ����ʽ�����Ҷ�Ӧ�� value��list ����ʹ���������ض�Ӧ��Ԫ�أ���dictʹ��key��

# Ҫ���� KeyError �������������취��
# һ�����ж�һ�� key �Ƿ���ڣ��� in ��������
# if 'Paul' in d:
#     print d['Paul']
# ����ʹ��dict�����ṩ��һ�� get ��������Key�����ڵ�ʱ�򣬷���None

# ����ռλ�����
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59
}
for key in ['Adam', 'Lisa', 'Bart']:
    print "%s: %d"%(key, d[key])

# dict�ĵ�һ���ص��ǲ����ٶȿ죬����dict��10��Ԫ�ػ���10���Ԫ�أ������ٶȶ�һ��
# dict�ĵڶ����ص���Ǵ洢��key-value�����û��˳��ģ�
# dict�ĵ������ص�����Ϊ key ��Ԫ�ر��벻�ɱ�    Python�Ļ����������ַ��������������������ǲ��ɱ�ģ���������Ϊ key

print '--------------------'
# ����
d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59
}
d['Paul'] = 72 #����һ�����ݣ���key�Ѵ��������value
for key in d:
    print key + ":" , d[key]

print '***************************************************'
# set
s = set(['A','B','C','A'])
print s
# ����set�洢�������򼯺ϣ���������û��ͨ�����������ʡ�
# ���� set�е�ĳ��Ԫ��ʵ���Ͼ����ж�һ��Ԫ���Ƿ���set�С�

# set�洢��Ԫ�غ�dict��key���ƣ������ǲ��������ˣ��κοɱ�����ǲ��ܷ���set�еġ����set�洢��Ԫ��Ҳ��û��˳��ġ�
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
# ����
s.add(('hahaha',88)) #����
s.remove(('Lisa', 85)) #ɾ��
# ����
for x in s:
    print x[0] + ":" , x[1]

print '***********************����****************************'
# help(abs)
# help(xrange)

print(abs(-1))

# ��1+2^1+����+100^2
L = []
x = 1
while x <= 10:
    L.append(pow(x,2))
    x += 1
for x in L:
    print x
print '----------range----------'
# ��������range����ʵ��
a = range(1, 11)
L = [i**2 for i in a]
for x in L:
    print x

# return None���Լ�дΪreturn

def square_of_sum(L):
    sum = 0
    for i in L:
        sum += i*i
    return sum

print "��listÿ��Ԫ�ص�ƽ����Ϊ��%d"%square_of_sum([1, 2, 3, 4, 5])
print "��listÿ��Ԫ�ص�ƽ����Ϊ��%d"%square_of_sum([-5, 0, 5, 15, 25])

# ���﷨�ϣ�����һ��tuple����ʡ�����ţ�Python�ĺ������ض�ֵ��ʵ���Ƿ���һ��tuple

print '----------һԪ���η���----------'
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

print "�����Ľ�Ϊ��",quadratic_equation(1, -6, 5)  #������
print "�����Ľ�Ϊ��",quadratic_equation(1, -6, 50) #�޽�


print '����'.join(('aaa', 'bbb', 'ccc'))


# �ݹ麯��
# ���ҳ���δ����n�����ݣ�����ϸ��
print '----------�׳�----------'
# �׳�
def fact(n):
    if n == 1:
        return 1
    return n * fact(n-1)

print fact(4)

print '----------��ŵ��----------'
# ��ŵ��
B=[] #���ò��������б�
def move(n, a, b, c):
    if n == 1:
        buzhou = a,str(n),'-->',c,str(n) #һ��Բ����Ҫ��A��C��������
        B.append(buzhou) #���б�����Ӳ�������
        return
    move(n-1, a, c, b) #��A����n-1�����Ƶ�B��
    buzhou = a,str(n),'-->',c,str(n) #��A���ĵ�n�����Ƶ�C����������
    B.append(buzhou) #���б�����Ӳ�������
    move(n-1, b, a, c) #����������B��n-1��Բ��B�ƶ���Ŀ������C

move(6,'A','B','C') #2**64-1��64��̫��������6������
print'�������'+str(len(B))+'��','��������Ϊ\n',B #����6�����ӵĲ���������������

print '----------��ŵ���򻯰�----------'
def move(n, a, b, c):
    if n == 1:
        print a,'-->',c
        return
    move(n-1, a, c ,b)
    print a, '-->',c
    move(n-1, b, a, c)
move(4, 'A', 'B', 'C')

# ����Ĭ�ϲ���
# ���ں����Ĳ����������ҵ�˳��ƥ�䣬����Ĭ�ϲ���ֻ�ܶ����ڱ�������ĺ���
print '----------Ĭ�ϲ���----------'
def greet(name='world'):
    print 'Hello,' + name + '.'

greet()
greet('Bart')

# �ɱ����
# Python��������Ѵ����һ�������װ��һ��tuple���ݸ��ɱ��������ˣ��ں����ڲ���ֱ�Ӱѱ��� args ����һ�� tuple �ͺ���
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

print '***********************��Ƭ****************************'

print '----------��list��tuple��Ƭ----------'
# �����־���ȡָ��������Χ�Ĳ�������ѭ��ʮ�ַ�������ˣ�Python�ṩ����Ƭ��Slice�����������ܴ������ֲ���
L = range(1, 101)

print L[:]
print L[90:] #��10����
print L[-3:]
print L[:10] # ǰ10������
#��������ʵ��Ч��һ��
print L[-8:-1:2]
print L[-8:-1][::2]

print L[2::3] # 3�ı�����
print L[4:50:5] # ������50��5�ı�����
print '----------���ַ�����Ƭ----------'
print 'ABCDEFG'[:3]
print 'ABCDEFG'[::2]

def firstCharUpper(s):
    return s[:1].upper()+s[1:]

print firstCharUpper('hello')

print '***********************����****************************'
for i in range(1,101):
    if i%7 == 0:
        print i
# ʹ�� enumerate() ���������ǿ�����forѭ����ͬʱ������index��Ԫ��name
# ʵ���ϵ�����ÿһ��Ԫ��ʵ������һ��tuple

d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59,
    'Paul':75
}

for t in enumerate(d):
    print t
# Ҳ����д��
for index, name in enumerate(range(5)):
    print index, '-', name

# zip������������list�ϲ�Ϊһ��
print zip([10, 20, 30], ['A', 'B', 'C'])

L = ['Adam', 'Lisa', 'Bart', 'Paul']
for index, name in zip(range(1,len(L)+1),L):
    print index, '-', name

print '----------��dict����----------'
# dict ������һ�� values() ���������������dictת����һ����������value��list�����������ǵ����ľ��� dict��ÿһ�� value��
d = { 'Adam': 95, 'Lisa': 85, 'Bart': 59 }
print d.itervalues() #�ٶȸ���
print d.values()
# items() ������dict����ת�����˰���tuple��list�����Ƕ����list���е���������ͬʱ���key��value��
print d.items()
for key, value in d.items():
    print key, ':', value
# items() Ҳ��һ����Ӧ�� iteritems()��iteritems() ����dictת����list�������ڵ��������в��ϸ��� tuple�����ԣ� iteritems() ��ռ�ö�����ڴ档
print '----------iteritems----------'
for key, value in d.iteritems():
    print key, ':', value

print '***********************�б�����ʽ****************************'
print [i*(i+1) for i in range(1,10,2)]

# ʹ��forѭ���ĵ����������Ե�����ͨ��list�������Ե���dict��
tds = ['<tr><td>%s</td><td>%s</td></tr>' % (name, score) for name, score in d.iteritems()]
print '<table>'
print '<tr><th>Name</th><th>Score</th><tr>'
print '\n'.join(tds) #�ַ�����join()�������԰�һ�� list ƴ�ӳ�һ���ַ�����
print '</table>'

# �б�����ʽ�� for ѭ�����滹���Լ��� if �ж�
print [x * x for x in range(1, 11) if x % 2 == 0]

# 1. isinstance(x, str) �����жϱ��� x �Ƿ����ַ�����
# 2. �ַ����� upper() �������Է��ش�д����ĸ��
def toUppers(L):
    return [x.upper() for x in L if isinstance(x,str)]
print toUppers(['Hello', 'world', 101])

# ѭ����Ƕ
L = []
for m in 'ABC':
    for n in '123':
        L.append(m+n)
print L
# ���Լ�Ϊ����д��
print [m+n for m in 'ABC' for n in '123']
# �Գ���λ��
print [100 * x + 10 * y + x for x in range(1, 10) for y in range(0, 10)]
