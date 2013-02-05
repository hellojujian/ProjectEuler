/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>
#include <math.h>

int check_prime(int a);
int main(int argc, char *argv[]){
	int count = 2,start = 5,flag = 0;
	while(count < 10001){
		flag = check_prime(start);
		if(flag == 1){
			printf("%d\n",start);
			count++;
		}
		start += 2;
	}
	//printf("%d",res);
	return 0;
}

int check_prime(int a){
	if(a >= 2){
		int i = 2,j = sqrt(i),flag = 0;
		for(i; i<=j; i++){
			if(a%i == 0){
				flag = 0;
			}else{
				flag = 1;
			}
			if(flag == 0){
				return 0;
			}
		}
		return flag;
	}
	return 0;
}
