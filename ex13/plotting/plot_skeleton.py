#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Programming Techniques for Scientific Simulations, ETH Zürich

from __future__ import (division, print_function)

import numpy as np
import scipy.stats as st
import scipy.linalg as la
import matplotlib.pyplot as plt


def get_samples(n=500):
    return np.random.rand(n, 2) * 2 - 1


def get_r(samples):
    return la.norm(samples, axis=1)


def calculate_pi(samples):
    num_inside = np.sum(get_r(samples) < 1.)
    num_total = len(samples)
    return 4 * num_inside / num_total


def create_scatter_plot(samples):
    # TODO: Create a scatter plot of the samples.
    fig, ax = plt.subplots()
    ax.set_aspect('equal')
    ax.set_xticks([-1, 0, 1])
    ax.set_yticks([-1, 0, 1])
    ax.set_xlabel(r'$x$')
    ax.set_ylabel(r'$y$')
    ax.set_title('Points used to calculate Pi')
    
    x, y = samples.T
    ax.scatter(x, y, c=get_r(samples) < 1., cmap='bwr')
    phi = np.linspace(0, 2*np.pi, 200)
    ax.plot(np.cos(phi), np.sin(phi), 'k')
    
    fig.savefig('scatter_plot.pdf', bbox_inches='tight')


def create_contour_plot(samples):
    density_func = st.gaussian_kde(samples.T, bw_method=0.2)
    # TODO: Create a contour plot showing the interpolated density.
    X, Y = np.mgrid[-1.1:1.1:200j, -1.1:1.1:200j]
    positions = np.stack([X.flat, Y.flat])
    Z = np.reshape(density_func(positions), X.shape)

    fig, ax = plt.subplots()
    ax.set_aspect('equal')

    ax.set_xticks([-1, 0, 1])
    ax.set_yticks([-1, 0, 1])
    ax.set_xlabel(r'$x$')
    ax.set_ylabel(r'$y$', rotation='horizontal')
    ax.set_title('Interpolated Point Density')

    heatmap = ax.contourf(X, Y, Z)
    ax.contour(X, Y, Z, linewidths=0.3, colors='k')
    fig.colorbar(heatmap)

    fig.savefig('contour_plot.pdf', bbox_inches='tight')


def main():
    np.random.seed(42)
    samples = get_samples()
    pi_estimate = calculate_pi(samples)
    print('Pi ~= {}'.format(pi_estimate))

    create_scatter_plot(samples)
    create_contour_plot(samples)


if __name__ == '__main__':
    main()
