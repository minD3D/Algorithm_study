Machine Learning
-------------------------
Experience
Task
Probability


01. Introduction
    Overview
    - Supervised learning
        - regression
            continuous 한 실수 결과값을 갖는 경우
            ex) 집의 넓이에 해당하는 집값 추정

        - classification
            특정 집단으로 분류가 가능한 경우
            ex) 고양이인가 개인가

    - Unsupervised learning
        - Clustering
            ex) 논문을 비슷한 것끼리 묶는것
                특정 특징을 가지고 그룹화 하는 것
        - Non clustering

02. Linear Regression
        집값을 예측하는 상황
        정답이 존재하는 상황이므로 Supervised learning 이다.
        이때 결과에 선형 관계가 존재할 때 Linear regression 이라 할 수 있다.

        - The hypothesis function
            가설이라는 의미로 
            input과 output의 관계를 나타내는 함수이다.
            주어진 데이터를 통해 결과를 유추할 수 있는 함수를 찾아낸 것이다.

        - Cost function
            hypothesis function의 정확도를 측정하기 위한 함수
            오차값의 합을 계산한 것

03. Logistic Regression
    Gradient descent (기울기 강하)
        hypothesis function의 최적 parameter 를 찾는 방법
        상수값을 바꿔가며서 최소 오차에 가까운 값을 찾는다.
        
    Multiple features
        여러 변수를 이용한 추정

04. Regularization
        Overfitting
        Feature가 너무 많으면 hypothesis function 이 복잡해진다. 이럴 경우 트레이닝 셋과 매우 유사한 모델을 만들 수 는 있지만 너무 유사하면 새로운 데이터를 예측할 경우 실패할 수 있다. 
        
        트레이닝 데이터에 너무 fit 되어 일반적 추세를 표현 못하는 경우를 말한다.

        피하기 위해서는 feature 를 수동으로 고르고 모델이 너무 복잡해지지 않도록 제약을 거는 방법이 있다

05. Neural Networks
    1) Model Representation
    2) Cost Function
    3) Back-Propagation Algorithm I
    4) Back-Propagation Algorithm II
    5) Implementation Notes
    6) Put it Together
06. Advice for Applying Machine Learning
    1) Machine Learning Diagnostic
    2) Bias vs. Variance
    3) Learning Curves
    4) Deciding What to do Next (Revisited)
07. Machine Learning System Design
    1) Building a Spam Classifier
    2) Handling Skewed Data
    3) Using Large Data Sets
08. Support Vector Machines
    1) Decision Boundary: Large Margin
    2) Kernels
    3) Using an SVM
09. Unsupervised Learning
    1) K-Means Algorithm
    2) Optimization Objective
    3) Random Initialization
    4) Choosing the Number of Clusters
10. Dimensionality Reduction
    1) Principal Component Analysis
    2) Reconstruction from Compressed Representation
    3) Choosing the Number of Principal Components
    4) Advice for Applying PCA
    5) Factor Analysis
    6) Linear Discriminant Analysis
11. Anomaly Detection
    1) Density Estimation
    2) Building an Anomaly Detection System
    3) Choosing what Features to Use
12. Recommender Systems
    1) Content Based Recommendation
    2) Collaborative Filtering
    3) Low Rank Matrix Factorization
13. Large Scale Machine Learning
    1) Gradient Descent with Large Datasets
    2) Advanced Topics
14. Application Example: Photo OCR
    A-1. Probability and Likelihood
    A-2. AdaBoost
    A-3. Gaussian Mixture Model
    A-4. Feature Selection
    A-5. Human Perception: Signal Detection Theory
    1) Sensitivity

