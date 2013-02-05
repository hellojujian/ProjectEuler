/**
 * @Copyright (c) 2012, JuJian
 * All rights reserved.
 * 
 * calculate sum of even fibonacci numbers which below 4000000
 * 
 * @filesource:		
 * @author			JuJian <hellojujian@gmail.com>
 * @package			
 * @version			v1.0
 */
#include <stdio.h>

int main(int argc, char *argv[]){
	int fibo_pre1 = 1,fibo_pre2 = 2,limit=4000000,fibo_now = 0,sum = 2;
		while(sum < limit){
			fibo_now = fibo_pre1+fibo_pre2;
			fibo_pre1 = fibo_pre2;
			fibo_pre2 = fibo_now;
			if(fibo_now%2 == 0){
				sum += fibo_now;
			}
		}
	printf("%d",sum);
	return 0;
}
