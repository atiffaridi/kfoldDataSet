import numpy as np
import pandas
from pandas.tools.plotting import scatter_matrix
from tkinter import Tk
from tkinter import filedialog
from tkinter.filedialog import askopenfilename
Tk().withdraw()
dataSet = askopenfilename()
dataset = pandas.read_csv(dataSet, header=None)
cols = len(dataset.columns)
rows=len(dataset)
posData=dataset[dataset.iloc[:,cols-1]>0]
negData=dataset[dataset.iloc[:,cols-1]<1]
#print('DD',negData)
rowsPos=len(posData)
rowsNeg=len(negData)
import math
fold=int(input('Enter No. of folds:-->'))
posParLen=math.floor(rowsPos/fold)
negParLen=math.floor(rowsNeg/fold)
lowPos=0
highPos = posParLen
lowNeg = 0
highNeg = negParLen
thMin={}
thMax={}
for i in range(fold):
    testPos=posData.iloc[lowPos:highPos,:]
    trainPos=posData.drop(testPos.index)
    rowsPosTrain=len(trainPos)
    testNeg=negData.iloc[lowNeg:highNeg,:]
    trainNeg=negData.drop(testNeg.index)
    rowsNegTrain=len(trainNeg)
    TR=trainPos.append(trainNeg,ignore_index=False)
    TEST=testPos.append(testNeg,ignore_index=False)
    if i==fold-2:
        lowPos = highPos
        highPos = rowsPos
        lowNeg = highNeg
        highNeg = highNeg+negParLen
    else:
        lowPos = highPos
        highPos = highPos + posParLen
        lowNeg = highNeg
        highNeg = highNeg + negParLen
    print("train","\n", TR)
    print("Test","\n", TEST)
