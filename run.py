#! /usr/bin/python3

import os
import random
import re

if __name__ == '__main__':
    solutions = set()
    for file_name in os.listdir('./src/'):
        if file_name.endswith('.cc'):
            solutions.add(file_name[:-3])
    with open('README.md') as fin:
        lines = fin.readlines()
    new_lines = ''
    unsolved_probs = []
    for line in lines:
        match_num = re.match('^\* \[(\d+)\.[^\]]+\]\([^\)]+\)\s*$', line)
        if match_num is None:
            new_lines += line
            continue
        prob_num = match_num.groups(0)[0]
        if prob_num not in solutions:
            new_lines += line
            unsolved_probs.append(prob_num)
            continue
        print("Adding solution for ", prob_num)
        new_lines += line[:-1] + ' [(C++)](src/' + prob_num + '.cc)\n'
    with open('README.md', 'w') as fout:
        fout.write(new_lines)
    print(len(unsolved_probs), " problems unsolved")
    selected_prob = unsolved_probs[random.randrange(0, len(unsolved_probs))]
    # selected_prob = min(map(lambda x: int(x), unsolved_probs))
    print("Try ", selected_prob)
