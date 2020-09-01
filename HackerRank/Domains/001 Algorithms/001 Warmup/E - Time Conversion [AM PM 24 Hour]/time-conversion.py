def time_conversion(s):
    hh, mm, ss = s.split(':')

    period = ss[2]
    ss = ss[:2]

    if int(hh) == 12 and period == 'A':
        hh = str(0)
    if not int(hh) == 12 and period == 'P':
        hh = str(int(hh) + 12)

    print(hh.rjust(2, '0') + ':' + mm.rjust(2, '0') + ':' + ss.rjust(2, '0'))


if __name__ == '__main__':
    s = input()

    time_conversion(s)