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
    of them labeled as NON-POI. I analysed these emails datas 
    and other datas about the workers and trained 
    my classifier with these datas. I used 4 features. 
    There are some features with many missing values. I handled
    them by converting their value to a default value. I had a few outliers in our data but I didn't 
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
    intuition. Features with most information gains and 
    which I end up using were:
    
        * "salary",
        * "total_payments",
        * "bonus",
        * "exercised_stock_options"
        
        Besides from those features, I also consider this
        features to use:
            
        * "from_poi_to_this_person",
        * "from_this_person_to_poi",
        * "from_messages",
        * "to_messages"
        
        I thought POI's might have a higher message rate with
        each other and scaled this features to prove my point.
        But some people had too much mails with both POI's and
        NON-POI's. So using just count of messages was useless.
        I created two new features to calculate percentile of
        messages from poi (from_poi_percentile) and messages 
        to poi (to_poi_percentile). I scaled them with 
        SelectKBest algorithm. Their scores_ and pvalues_ were:
        
        feature | score_ | pvalue_
        from_poi_percentile | 9.00541121e+00 | 9.00541121e+00
        to_poi_percentile | 2.46799385e+00 | 0.11944251
        
        So those features didn't had as much information gain
        as I though. Actually they were pretty bad. So I created
        a new feature as well with combining both "from_poi_percentile"
        and "to_poi_percentile" into one feature as "poi_percentile"
        by calculating the rate of messages send and receiver from
        POI's to all messages send and receiver from everyone.
        score_ and pvalue_ of "poi_percentile" was:
        
        score_ | pvalue_
        3.83020936e+00 | 0.05321129
        
        It was still pretty bad so I didn't use those features.

3)