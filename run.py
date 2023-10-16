#! /usr/bin/python3

import os
import re

if __name__ == '__main__':
    solutions = set()
    for file_name in os.listdir('./src/'):
        if file_name.endswith('.cc'):
            solutions.add(file_name[:-3])
    with open('README.md') as fin:
        lines = fin.readlines()
    new_lines = ''
    for line in lines:
        match_num = re.match('^\* \[(\d+)\.[^\]]+\]\([^\)]+\)\s*$', line)
        if match_num is None or match_num.groups(0)[0] not in solutions:
            new_lines += line
            continue
        prob_num = match_num.groups(0)[0]
        print(prob_num)
        new_lines += line[:-1] + ' [(solution)](src/' + prob_num + '.cc)\n'
    with open('README.md', 'w') as fout:
        fout.write(new_lines)

