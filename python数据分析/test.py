# -*- coding: utf-8 -*-
"""
Created on Sun Dec 23 14:34:36 2018

@author: Lenovo
"""
'''
import pandas as pd;
data = pd.read_table(r"data.csv", sep=",", header=None, names=['opAge', 'opYear', 'cellNum', 'status'], engine="python") 
data1 = data[data['status'] == 1] # status为1的数据 
data2 = data[data['status'] == 2] # status为2的数据
'''

# 导入类库 
import matplotlib.pyplot as plt 
import numpy as np
import pandas as pd 

#数据读取
data =pd.read_csv('data.txt',header=None ,names = ['opAge', 'opYear', 'cellNum', 'status'], engine="python")
print ("数据的形状为：",data.shape)
print("数据的基本信息：\n",data.info())
print("\n数据集：\n",data.head(306))
print("数据基本统计描述：\n",data.describe())



#数据预处理
data = data.replace(to_replace='?',value=np.nan)    #非法字符的替代
data = data.dropna(how='any')        #去掉空值，any：出现空值行则删除
print('每个特征缺失的数目为：\n',data.isnull().sum())
print('每个特征非缺失的数目为：\n',data.notnull().sum())
print("数据预处理去除缺失列后的大小：",data.shape)
print(data.head())

'''
# 箱线图
from matplotlib import pyplot 
data.plot(kind='box', subplots=True, layout=(2,2), sharex=False, sharey=False)
print("箱型图")
pyplot.show()

data.hist()
pyplot.xlabel('数值')
pyplot.ylabel('个数')
print("直方图")
pyplot.show()

# 散点矩阵图
from pandas.plotting import scatter_matrix 
scatter_matrix(data)
print("散点矩阵图")
pyplot.show()

#3D散点图
print('3D散点图')

data1 = data[data['status'] == 1]  # status为1的数据
data2 = data[data['status'] == 2]  # status为2的数据

fig = plt.figure(figsize=(16, 12)) 
ax = fig.gca(projection="3d") #get current axis 
ax.scatter(data1['opAge'], data1['opYear'], data1['cellNum'], c='r', s=100, marker="*", label="survived 5 years or longer") #status为1的样本的散点图 
ax.scatter(data2['opAge'], data2['opYear'], data2['cellNum'], c='b', s=100, marker="^", label="died within 5 year") #status为2的样本的散点图 
ax.set_xlabel("operation age", size=15) 
ax.set_ylabel("operation year", size=15) 
ax.set_zlabel("cell number", size=15) 
ax.set_title('Haberman\'s Survival Scatter Plot', size=15, weight='bold') 
ax.set_zlim(0, 30) 
ax.legend(loc="lower right", fontsize=15) 
plt.show()
'''

'''
# 归一化 
(x-min)/(max-min)∈[0,1] 
def autoNorm(dataSet): 
    minVals = samples.min(axis=0) # 按列求最小值，即求每个属性的最小值 
    maxVals = samples.max(axis=0) # 求每个属性的最大值 
    factors = maxVals - minVals # 归一化因子 
    sNum = dataSet.shape[0] # 数据集的行数，即样本数 
    normDataSet = (dataSet - np.tile(minVals, (sNum, 1))) / np.tile(factors, (sNum, 1)) # 先将minVals和归一化因子转换成与dataSet相同的shape，再做减法和除法运算，最终归一化后的数据都介于[0,1] 
    return normDataSet

testIdxs = random.sample(range(0, len(samples), 1), len(samples) * 1 / 10) # 随机选取testing data的索引 
testingSet = samples.ix[testIdxs] # 根据索引从样本集中获取testing data 
idxs = range(0, len(samples), 1) # 总的数据索引序列 
#以下for循环是从总的数据索引序列中将testing data的索引去除 
for i in range(0, len(testIdxs)): 
    idxs.remove(testIdxs[i]) 
trainData = samples.ix[idxs] # 获取用作训练的数据集
'''

def classifyKNN(inX, dataSet, labels, k):
    nDataSet = zeros((dataSet.shape[0], dataSet.shape[1])) 
    j = 0
    for i in dataSet.index:
        nDataSet[j] = dataSet.ix[i]
        j += 1
    nDataSet = pd.DataFrame(nDataSet)

    nLabels = zeros(labels.shape[0]) #与labels同型的0向量
    h = 0
    for i in labels.index:
        nLabels[h] = labels.ix[i]
        h += 1

    dataSetNum = nDataSet.shape[0]  # 样本数(DataFrame行数)
    diffMat = tile(inX, (dataSetNum, 1)) - nDataSet 
    sqDiffMat = diffMat ** 2  #平方
    sqDistances = sqDiffMat.sum(axis=1) #矩阵sqDiffMat的列之和，即目标样本与样本集中每个样本对应属性的差值的平方和
    distances = sqDistances ** 0.5 #平方根，欧氏距离，即目标样本与每个样本点的距离
    sortedDistanceIdx = distances.argsort()  # 距离从小到大的索引值，sortedDistanceIdx的索引是从0开始的自然数，sortedDistanceIdx的值表示对应的distance的索引，比如sortedDistanceIdx[0]是150，表示最小的距离在distances中的索引是150
    classCount = {}
    for i in range(k):
        #找出distance最小的k个索引，然后在nLabels中获取其对应类别
        voteLabel = nLabels[int(sortedDistanceIdx[i])]
        classCount[voteLabel] = classCount.get(voteLabel, 0) + 1
    #classCount字典中存放了统计的label和对应的出现次数
    sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True) #倒序
    return sortedClassCount[0][0]  #出现次数最大的label

#返回在该验证集上的错误率
def train(trainingSet, validationSet, kn):
    errorCount = 0
    vIdxs = validationSet.index
    #遍历验证集，对每个样本使用KNN
    for i in range(0, len(validationSet)):
        pred = classifyKNN(validationSet.loc[vIdxs[i], ['opAge', 'opYear', 'cellNum']], trainingSet[['opAge', 'opYear', 'cellNum']], trainingSet['status'], kn)
        if (pred != validationSet.at[vIdxs[i], 'status']):
            errorCount += 1
    return errorCount / float(len(validationSet))

def crossValidation(dataSet, idxs, k, kn):
    step = len(idxs) / k
    errorRate = 0
    for i in range(k):
        validationIdx = []
        for i in range(i * step, (i + 1) * step):
            validationIdx.append(idxs[i])
        validationSet = dataSet.ix[validationIdx]  # 获得验证集数据
        temp = idxs[:]
        for i in validationIdx:  # 把验证集的索引去除
            temp.remove(i)
        trainingSet = dataSet.ix[temp]  # 获取训练集数据
        errorRate += train(trainingSet, validationSet, kn)
    aveErrorRate = errorRate / float(k)
    return aveErrorRate
def predict(trainingSet, testingSet, kn):
    errorCount = 0
    for i in range(0, len(testingSet)):
        vIdxs = testingSet.index
        pred = classifyKNN(testingSet.loc[vIdxs[i], ['opAge', 'opYear', 'cellNum']], trainingSet[['opAge', 'opYear', 'cellNum']], trainingSet['status'], kn)
        print ("The prediction label is ",pred)
        print ("The real label is %s",testingSet.at[vIdxs[i], 'status'])
        if (pred != testingSet.at[vIdxs[i], 'status']):
            errorCount += 1
    return errorCount / float(len(testingSet))
'''
print ("The cross validation error ratio is %d" ,crossValidation(data, idxs, 10, 3))
print ("The testing data error ratio is %d",predict(samples,testingSet,3))
'''

import numpy as np
import pylab as pl
import random as rd
import imageio
#计算平面两点的欧氏距离
step=0
color=['.r','.g','.b','.y']#颜色种类
dcolor=['*r','*g','*b','*y']#颜色种类
frames = []
def distance(a, b):
    return (a[0]- b[0]) ** 2 + (a[1] - b[1]) ** 2
#K均值算法
def k_means(x, y, k_count,la):
    count = len(x)      #点的个数
    #随机选择K个点
    k = rd.sample(range(count), k_count)
    k_point = [[x[i], [y[i]]] for i in k]   #保证有序
    k_point.sort()
    global frames
    global step
    while True:
        km = [[] for i in range(k_count)]      #存储每个簇的索引
        #遍历所有点
        for i in range(count):
            cp = [x[i], y[i]]                   #当前点
            #计算cp点到所有质心的距离
            _sse = [distance(k_point[j], cp) for j in range(k_count)]
            #cp点到那个质心最近
            min_index = _sse.index(min(_sse))   
            #把cp点并入第i簇
            km[min_index].append(i)
        #更换质心
        step+=1
        k_new = []
        for i in range(k_count):
            _x = sum([x[j] for j in km[i]]) / len(km[i])
            _y = sum([y[j] for j in km[i]]) / len(km[i])
            k_new.append([_x, _y])
        k_new.sort()        #排序
 
        #使用Matplotlab画图
        pl.figure()
        pl.title("N=%d,k=%d  iteration:%d"%(count,k_count,step))
        for j in range(k_count):
            pl.plot([x[i] for i in km[j]], [y[i] for i in km[j]], color[j%4])
            pl.plot(k_point[j][0], k_point[j][1], dcolor[j%4])
        pl.xlabel(la)
        pl.ylabel('status')
        pl.savefig("1.jpg")
        frames.append(imageio.imread('1.jpg'))
        if (k_new != k_point):#一直循环直到聚类中心没有变化
            k_point = k_new
        else:
            return km

arr=['opAge','opYear','cellNum']
for i in range(0,3):
    x=data[arr[i]]
    y = data['status']
    print(i)
    k_count = 1
    km = k_means(x, y, k_count,arr[i])
       
print("K-means算法结束")
