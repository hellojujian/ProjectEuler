/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * find the largest prime factor of 600851475143
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>
#include <gmp.h>

float find_largest_factor(float num);
int main(int argc, char *argv[]){
	float num_to_solve = 600851475143,largest_factor = 0;
	largest_factor = find_largest_factor(num_to_solve);
	printf("%f",largest_factor);
	return 0;
}

float find_largest_factor(float num){
	float i = 2,factor = 1;
	for(i; i<=num; i++){
		if((num%i) == 0){
			factor = num/i;
		}
	}
	return factor;
}