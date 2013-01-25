/**
 * @Copyright (c) 2013, JuJian
 * All rights reserved.
 * 
 * http://projecteuler.net/problem=14
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>

int collatz_se_chain_length(unsigned int n,int count);

int main(int argc, char *argv[]){
	//int a = collatz_se_chain_length(50001,1);
	unsigned int i = 1,max = 1,maxn = 1,a = 0;
	for(i; i<1000000; i++){
		a = collatz_se_chain_length(i,1);
		if(a > max){
			max = a;
			maxn = i;
		}
	}
	printf("i is:%d\nlongest collatz sequence length is %d",maxn,max);
	return 0;
}

int collatz_se_chain_length(unsigned int n,int count){
	if(n == 1){
		return count;
	}
	if(n%2 == 0){
		return collatz_se_chain_length(n/2,1+count);
	}
	if(n%2 != 0){
		return collatz_se_chain_length(3*n+1,1+count);
	}
}
