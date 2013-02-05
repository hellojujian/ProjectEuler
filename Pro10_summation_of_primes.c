/**
 * @Copyright (c) 2013, JuJian
 * All rights reserved.
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>

int check_prime(int a);
int bigint_add(int a,int b,int digit);

int main(int argc, char *argv[]){
	int i = 7,sum = 10;
	for(i; i<=2000000; i=i+2){
		if(check_prime(i)){
			//printf("i is %d\n",i);
			sum += i;
			if(sum < 0){
				printf("sum below zero: %d\n",sum);
			}
		}
	}
	printf("sum is %d",sum);
	return 0;
}

int check_prime(int a){
	if(a >= 3){
		int i = 3,j = a/2,flag = 0;
		for(i; i<=j; i=i+2){
			if(a%i == 0){
				flag = 0;
				break;
			}else{
				flag = 1;
			}
		}
		return flag;
	}
	return 0;
}

int bigint_add(int a,int b,int digit){
	int a_arr[digit+1],b_arr[digit+1];

}
