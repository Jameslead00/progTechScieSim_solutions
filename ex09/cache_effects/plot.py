#!/usr/bin/env python3
"""
Usage: ./plot.py data_file
"""

import sys
import os

import numpy as np
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    sys.exit('Please provide a filename!')

RESULTS = np.sort(
    np.loadtxt(
        sys.argv[1],
        dtype={
            'names': ['size', 'step', 'time', 'nops'],
            'formats': ['u4', 'u4', 'f8', 'u4']
        }
    ),
    order=['step', 'size']
)

STEPS = np.unique(RESULTS['step'])
STEP_SLICES = [RESULTS['step'] == s for s in STEPS]

plt.figure()
for s, s_slice in zip(STEPS, STEP_SLICES):
    if s > 512:
        break
    plt.semilogx(
        RESULTS['size'][s_slice],
        1e9 * RESULTS['time'][s_slice] / RESULTS['nops'][s_slice],
        marker='+',
        label='{} bytes'.format(s),
        base=2
    )
plt.title('Part a) Cache and Cacheline Size.')
plt.legend(title='Step Size', loc='best')
plt.ylabel('time [ns]')
plt.xlabel('array size [bytes]')
plt.savefig(os.path.join('result', 'plot_a.pdf'), bbox_inches='tight')

plt.figure()
for s, s_slice in zip(STEPS, STEP_SLICES):
    if s < 1024:
        continue
    plt.semilogx(
        RESULTS['size'][s_slice] / s,
        1e9 * RESULTS['time'][s_slice] / RESULTS['nops'][s_slice],
        label='{} bytes'.format(s),
        base=2
    )
plt.title('Part b) Associativity.')
plt.legend(title='Step Size', loc='best')
plt.ylabel('time [ns]')
plt.xlabel('array size / step size')
plt.savefig(os.path.join('result', 'plot_b.pdf'), bbox_inches='tight')
