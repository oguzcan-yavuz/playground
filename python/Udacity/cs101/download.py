# Write a procedure download_time which takes as inputs a file size, the
# units that file size is given in, bandwidth and the units for
# bandwidth (excluding per second) and returns the time taken to download
# the file.
# Your answer should be a string in the form
# "<number> hours, <number> minutes, <number> seconds"

# Some information you might find useful is the number of bits
# in kilobits (kb), kilobytes (kB), megabits (Mb), megabytes (MB),
# gigabits (Gb), gigabytes (GB) and terabits (Tb), terabytes (TB).

# print 2 ** 10      # one kilobit, kb
# print 2 ** 10 * 8  # one kilobyte, kB

# print 2 ** 20      # one megabit, Mb
# print 2 ** 20 * 8  # one megabyte, MB

# print 2 ** 30      # one gigabit, Gb
# print 2 ** 30 * 8  # one gigabyte, GB

# print 2 ** 40      # one terabit, Tb
# print 2 ** 40 * 8  # one terabyte, TB

# Often bandwidth is given in megabits (Mb) per second whereas file size
# is given in megabytes (MB).


def check_s(n, str):
    if n > 1 or n < 1:
        str += "s"
    return str


def convert_seconds(sec):
    seconds = sec % 60
    mins = int(sec / 60)
    hours = 0
    while mins >= 60:
        hours += 1
        mins -= 60
    s = check_s(seconds, "second")
    m = check_s(mins, "minute")
    h = check_s(hours, "hour")
    return "{0} {1}, {2} {3}, {4} {5}".format(hours, h, mins, m, seconds, s)


def check_types(type):
    if type == 'kb':
        return 2 ** 10
    elif type == 'kB':
        return 2 ** 10 * 8
    elif type == 'Mb':
        return 2 ** 20
    elif type == 'MB':
        return 2 ** 20 * 8
    elif type == 'Gb':
        return 2 ** 30
    elif type == 'GB':
        return 2 ** 30 * 8
    elif type == 'Tb':
        return 2 ** 40
    elif type == 'TB':
        return 2 ** 40 * 8


def download_time(size, stype, bw, bwtype):
    return convert_seconds((size * check_types(stype)) * 1.0 / (bw * check_types(bwtype)))


print download_time(1024,'kB', 1, 'MB')
# >>> 0 hours, 0 minutes, 1 second

# print download_time(1024,'kB', 1, 'Mb')
# # >>> 0 hours, 0 minutes, 8 seconds  # 8.0 seconds is also acceptable
#
print download_time(1,'kB',3,'MB')
# # >>> 0 hours, 39 minutes, 37.1428571429 seconds
#
# print download_time(13,'GB', 5.6, 'Mb')
# # >>> 5 hours, 16 minutes, 57.1428571429 seconds
#
# print download_time(10,'MB', 2, 'kB')
# # >>> 1 hour, 25 minutes, 20 seconds  # 20.0 seconds is also acceptable
#
# print download_time(10,'MB', 2, 'kb')
# # >>> 11 hours, 22 minutes, 40 seconds  # 40.0 seconds is also acceptable
