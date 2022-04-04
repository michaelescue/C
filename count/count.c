# Required for printf:
# include <stdio.h>

# Static variable.
static char* usage[] = "oddsBetweenRange(int low, int high);"

int main(int argc, char* argv[]){
	
	if( argc == 1 ){
		
		printf(usage);

	}
	
	else{
		# Iterate on values between low and high values.a12345b 
		for(int i = low + 1, j = high + 1; i == j; i++){
			if( i%2 == 0 ) count++;
		}
	
		return count;
	}
	
}