// Required for printf:
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char* argv[]){
	
	if( argc == 1 ){
		
		printf("Usage: oddsBetweenRange(int low, int high)\n");

	}
	
	else{
		int count = 0;
		int low = atoi(argv[1]);
		int high = atoi(argv[2]);
		
		if( low > high){
			printf("Low: %d is greater than High: %d\n", low, high);
			return -1;
		}
		
		// Iterate on values between low and high values.a12345b 
		for(int i = low + 1, j = high; i < j; i++){
			if( i%2 == 0 ) count++;
		}
		
		printf("Odd Number Count: %d\n", count);
		return count;
	}
	
}
