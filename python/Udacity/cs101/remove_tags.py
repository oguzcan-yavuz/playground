# Question 4: Remove Tags

# When we add our words to the index, we don't really want to include
# html tags such as <body>, <head>, <table>, <a href="..."> and so on.

# Write a procedure, remove_tags, that takes as input a string and returns
# a list of words, in order, with the tags removed. Tags are defined to be
# strings surrounded by < >. Words are separated by whitespace or tags.
# You may assume the input does not include any unclosed tags, that is,
# there will be no '<' without a following '>'.

# find ve split metotlari kullanilarak yapilan cozum
def with_method(string):
    start = string.find('<')
    while start is not -1:
        end = string.find('>', start)
        string = string[:start] + " " + string[end + 1:]
        start = string.find('<')
    return string.split()


print with_method("A <img src='here.img' alt='nothing'>picture,</a> a cat and a mouse!")


def remove_tags(string):
    results, i = [], 0
    while i < len(string) - 1:
        if string[i] is '<':
            while string[i] is not '>':
                i += 1
            j = i + 1
        else:
            j = i
        while (string[i] is not '<' and string[i].isspace() is False) and i + 1 < len(string):
            i += 1
        if i == len(string) - 1:
            if string[i].isspace() is False:
                results.append(string[j:i + 1])
        elif j + 1 <= i:
            results.append(string[j:i])
        while string[i].isspace():
            i += 1
    return results

print remove_tags("A <img src='here.img' alt='nothing'>picture,</a> a cat and a mouse!")

# print remove_tags('''<h1>Title</h1><p>This is a
#                     <a href="http://www.udacity.com">link</a>.<p>''')
# #>>> ['Title','This','is','a','link','.']
#
# print remove_tags('''<table cellpadding='3'>
#                     <tr><td>Hello</td><td>World!</td></tr>
#                      </table>''')
# #>>> ['Hello','World!']
# #
# print remove_tags("<hello><goodbye>")
# # #>>> []
#
# print remove_tags("This is plain text.")
# #>>> ['This', 'is', 'plain', 'text.']


