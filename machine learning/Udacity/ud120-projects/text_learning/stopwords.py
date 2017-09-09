# from nltk.corpus import stopwords
# sw = stopwords.words("english")
# print(len(sw))

# Stemmer
from nltk.stem.snowball import SnowballStemmer
stemmer = SnowballStemmer("english")
print(stemmer.stem("unresponsive"))
print(stemmer.stem("responsive"))
print(stemmer.stem("responsivity"))
