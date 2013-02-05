/**
 * @Copyright (c) 2013, JuJian
 * All rights reserved.
 * 
 * http://projecteuler.net/problem=12
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>
#include <math.h>
int get_factor_number(int n);

int main(int argc, char *argv[]){
	int n = 1,i = 1;
	int count = get_factor_number(n);
	while(count!=500){
		if((n*(n+1)/2 < 0)){
			printf("now n is %d",n);
		}
		count = get_factor_number(n*(n+1)/2);
		n++;
	}
	printf("%d",n*(n+1)/2);
	return 0;
}


int get_factor_number(int n){
	if(n>=0){
		if(n <= 2){
			return n;
		}
		int i = 2,j = sqrt(n),count = 0;
		for(i; i<=j; i++){
			if(n%i == 0){
				if(i == j){
					count++;
				}else{
					count += 2;
				}
			}
		}
		return count+2;
	}
	return 0;
}