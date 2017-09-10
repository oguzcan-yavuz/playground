### Q / A

1) Summarize for us the goal of this project and 
how machine learning is useful in trying to 
accomplish it. As part of your answer, give 
some background on the dataset and how it can 
be used to answer the project question. Were there 
any outliers in the data when you got it, and how did 
you handle those?  [relevant rubric items: 
“data exploration”, “outlier investigation”]
    
    * My goal is to identify people work at Enron as person of 
interest(POI) or not(NON-POI) with training a classifier 
which uses Enron data to train itself. With machine 
learning, we don't have to handle the features which a 
computer could easily handle. Most of the hard parts of 
maths which required to analyse complex datasets are 
handled by the computer, that is why using machine 
learning to accomplish our goal is a good choice. 

        Enron is an energy company which was very large during 
    2000 and bancrupted during 2002 due to forgery. 
    Enron dataset which I am using in this project, 
    contains emails of the workers at the Enron company. 
    It has 146 people; 18 of them labeled as POI and 126 
    of them labeled as NON-POI. I analysed these emails 
    contents and other datas about the workers and trained 
    my classifier with these datas. I used ... features. 
    There are some features with many missing values. I handled
    them ... . I had a few outliers in our data but I didn't 
    remove them. Since I am building a POI classifier, those 
    outliers are very likely to be our POI's. Because POIs are 
    most likely have anomalies so I want to catch those 
    anomalies to classify them.


2) What features did you end up using in your 
POI identifier, and what selection process did you 
use to pick them? Did you have to do any scaling? 
Why or why not? As part of the assignment, you should 
attempt to engineer your own feature that does not come 
ready-made in the dataset -- explain what feature you 
tried to make, and the rationale behind it. 
(You do not necessarily have to use it in the final 
analysis, only engineer and test it.) In your feature 
selection step, if you used an algorithm like a decision 
tree, please also give the feature importances of the 
features that you use, and if you used an automated 
feature selection function like SelectKBest, please 
report the feature scores and reasons for your choice 
of parameter values.  [relevant rubric items: 
“create new features”, “intelligently select features”, 
“properly scale features”]

    * I visualized different features and I tried to guess the 
    features with most information gains to improve my 
    intuition.
