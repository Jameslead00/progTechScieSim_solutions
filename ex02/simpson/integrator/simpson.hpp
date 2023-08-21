#ifndef SIMPSON_HPP
#define SIMPSON_HPP

double integrate(double a, double b, unsigned int nbins, double (*function)(double));

#endif