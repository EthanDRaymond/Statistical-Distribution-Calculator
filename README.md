# Statistical Distribution Calculator

## Description

This tool is designed for calculating probabilities based on the standard set of statistical distributions.

### Supported Distributions
1. Normal
2. Poisson
3. Binomial
4. Exponential

## How to Install

### Unix/Linux
Perform the following commands:
````
make all
````
````
sudo make install
````

## Usage

To use each distribution, use the following commands

### Normal Distribution
````
stat-calc normal [OPTIONS] Z-VALUE
````
#### Options
````
--mean              The statistical mean for this distribution.
--standard-dev      The statistical standard deviation for this 
                    distribution.
````

### Poisson
````
stat-calc poisson [OPTIONS]
````
#### Options
````
-k                  The k-value used to calculate the probability.
--lambda            The lambda value for the poisson distribution.
````

### Binomial
````
stat-calc binomial [OPTIONS]
````
#### Options
````
-x                  The x value used to calculate the probability.
-n                  The n value in B(n,p)
-p                  The p value in B(n,p)
````

### Exponential
````
stat-calc exponential [OPTIONS]
````
#### Options
````
-x                  The x value used to calculate the probability.
--theta             The theta value for the distribution
````