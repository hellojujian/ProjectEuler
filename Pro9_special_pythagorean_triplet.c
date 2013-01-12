/**
 * @Copyright (c) 2012, Jujian all rights reserved.
 * 
 *  A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 *	a*a + b*b = c*c
 *	For example, 3*3 + 4*4 = 9 + 16 = 25 = 5*5.
 *
 *	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *	Find the product abc.
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */

#include <stdio.h>

int main(int argc, char *argv[]){
	int i = 1,end = 333,j = 2,k = 3;
	for(i; i<=end; i++){
		for(j=i+1; j<=1000; j++){
			for(k=j+1; k<=1000; k++){
				if((i*i+j*j) == k*k && (i+j+k) == 1000){
					printf("i is %d\tj is %d\tk is %d\n",i,j,k);
					printf("product is %d",i*j*k);
				}
			}
		}
	}
	return 0;
}
