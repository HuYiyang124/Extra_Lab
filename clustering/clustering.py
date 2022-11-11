import matplotlib.pyplot as plt
import numpy as np

# This data set represents a toy manufacturer's product data
#
# The first value in the pair represents a toy:
# 0-2: Action Figures
# 3-5: Building Blocks
# 6-8: Cars
#
# The second value is the age group that buys the most of that toy:
# 0: 5 year-olds
# 1: 6 year-olds
# 2: 7 year-olds
# 3: 8 year-olds
# 4: 9 year-olds
# 5: 10 year-olds
x = np.array([[0,4], [1,3], [2,5], [3,2], [4,0], [5,1], [6,4], [7,5], [8,3]])

'''
   Exercises1. implement the k-means correlated function
'''
def getDistance(pointA, pointB):
    res = 0
    for i in range(len(pointA)):
        res += (pointA[i] - pointB[i]) ** 2
    return res ** 0.5

def renewCenterPoint(typeList, dataSet, K):
    centerPoint = []
    for k in range(K):
        X = Y = cnt = 0
        for j in range(len(typeList)):
            if typeList[j] == k + 1:
                X += dataSet[j][0]
                Y += dataSet[j][1]
                cnt += 1
        print(f'X: {X}, Y: {Y}, Type num: {cnt}')
        centerPoint.append([X/cnt, Y/cnt])
    return centerPoint

def KMeans(dataSet):
    typeList = []
    [typeList.append(0) for i in range(len(dataSet))]
    K = 3
    # the first choosed points 
    centerPoint = [[0,4], [1,3], [2,5]]
    print('the first choosed points are: ', centerPoint)
    
    flag = 1
    while(flag == 1):
        for i in range(len(x)):# 
            distList = []
            for k in range(K):
                dist = getDistance(dataSet[i], centerPoint[k]) # The center point distance
                distList.append(dist)
            for j in range(K):
                if distList[j] == min(distList): # find the minimun point
                    typeList[i] = j + 1 # j+1 is the type
            print(typeList)
            
        # Calculate the new center point
        newCenterPoint = renewCenterPoint(typeList, dataSet, K)
        print('New center point: ', newCenterPoint)
        cntK = 0                
        for k in range(K):
            # Calculate the new center distanse
            distChange = getDistance(centerPoint[k], newCenterPoint[k]) 
            if distChange < 1:
                cntK += 1
            if cntK == K:   
                flag = 0
                break
        centerPoint = newCenterPoint # update the center point
    return typeList, centerPoint

# Set up K-Means clustering with a fixed start and stop at 3 clusters
kmeansLabel, centerPoint = KMeans(x)

# draw the data distribution
for i in range(len(x)):
    if kmeansLabel[i] == 1:
        plt.scatter(x[i, 0], x[i, 1], c='r')
    if kmeansLabel[i] == 2:
        plt.scatter(x[i, 0], x[i, 1], c='g')
    if kmeansLabel[i] == 3:
        plt.scatter(x[i, 0], x[i, 1], c='b')

# draw the center points
plt.scatter(centerPoint[:][0], centerPoint[:][1], c='black', marker='x')
plt.scatter(centerPoint[2][0], centerPoint[2][1], c='black', marker='x')
plt.title('Exercises-1')
plt.show()


'''
    Exercises2
'''
import seaborn as sns
from sklearn.cluster import KMeans
from sklearn.cluster import AgglomerativeClustering, AffinityPropagation, \
     DBSCAN, Birch, FeatureAgglomeration
from collections import defaultdict
from scipy.spatial import ConvexHull
from scipy.spatial import Voronoi, voronoi_plot_2d
import string

x = []
#read data
with open('train.txt') as file:
     for line in file:
         #print(line)
         x.append([float(line[1:-2].split(',')[0]), float(line[1:-2].split(',')[1])])

x = np.array(x)

# Set up hierarchical clustering and stop at 3 clusters
num_clusters = 3
kmeans = AgglomerativeClustering(n_clusters=num_clusters).fit(x)

# Plot the data
sns.set_style("darkgrid")
plt.scatter(x[:, 0], x[:, 1], c=kmeans.labels_, cmap=plt.get_cmap("winter"))
# Save the axes limits of the current figure
x_axis = plt.gca().get_xlim()
y_axis = plt.gca().get_ylim()
# Resize figure as needed
plt.gca().set_xlim(x_axis)
plt.gca().set_ylim(y_axis)
# Remove ticks from the plot
plt.xticks([])
plt.yticks([])
plt.tight_layout()
plt.title('AgglomerativeClustering')
plt.show()

kmeans = AffinityPropagation().fit(x)

# Plot the data
sns.set_style("darkgrid")
plt.scatter(x[:, 0], x[:, 1], c=kmeans.labels_, cmap=plt.get_cmap("winter"))
# Save the axes limits of the current figure
x_axis = plt.gca().get_xlim()
y_axis = plt.gca().get_ylim()
# Resize figure as needed
plt.gca().set_xlim(x_axis)
plt.gca().set_ylim(y_axis)
# Remove ticks from the plot
plt.xticks([])
plt.yticks([])
plt.tight_layout()
plt.title('AffinityPropagation')
plt.show()

kmeans = DBSCAN().fit(x)

# Plot the data
sns.set_style("darkgrid")
plt.scatter(x[:, 0], x[:, 1], c=kmeans.labels_, cmap=plt.get_cmap("winter"))
# Save the axes limits of the current figure
x_axis = plt.gca().get_xlim()
y_axis = plt.gca().get_ylim()
# Resize figure as needed
plt.gca().set_xlim(x_axis)
plt.gca().set_ylim(y_axis)
# Remove ticks from the plot
plt.xticks([])
plt.yticks([])
plt.tight_layout()
plt.title('DBSCAN')
plt.show()

kmeans = Birch().fit(x)

# Plot the data
sns.set_style("darkgrid")
plt.scatter(x[:, 0], x[:, 1], c=kmeans.labels_, cmap=plt.get_cmap("winter"))
# Save the axes limits of the current figure
x_axis = plt.gca().get_xlim()
y_axis = plt.gca().get_ylim()
# Resize figure as needed
plt.gca().set_xlim(x_axis)
plt.gca().set_ylim(y_axis)
# Remove ticks from the plot
plt.xticks([])
plt.yticks([])
plt.tight_layout()
plt.title('Birch')
plt.show()

