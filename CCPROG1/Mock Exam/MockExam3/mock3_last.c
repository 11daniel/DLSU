
int findLargestDigit(int nNum){
	int large = 0;
	int rem = 0;

	while (nNum > 0) {
		rem = nNum % 10;

		if (rem > large) 
		{
			large = rem;
		}
		nNum = nNum /10;
	}
	return large;
}

int firstPowOver(int nNum){
	int nRes = 1;
	while (nRes < nNum) {
		nRes *= 2;
	}
	return nRes;
}

int reverseDigits(int nNum){
	int remainder;
	int reverse = 0;

	while (nNum != 0) {
		remainder = nNum  % 10;
		reverse = reverse * 10 + remainder;
		nNum /= 10;
	}
	return reverse;
}

int isPallindrome(int nNum){
	int nResult;
	int remainder;
	int reversed = 0;
	int original;

	original = nNum;

	while (nNum != 0) {
		remainder = nNum  % 10;
		reversed = reversed * 10 + remainder;
		nNum /= 10;
	}

    if (original == reversed) {
		nResult = 1;
	}
	else {
		nResult = 0;
	}
	return nResult;
}

void displayChart(int nNum){
	int nMax;
	while (nNum > 0) {
		for (nMax = 9 - nNum % 10; nMax > 0; nMax--){
			printf(" ");
		}
		for (nMax = nNum % 10; nMax > 0; nMax--){
			printf("*");
		}
		printf("\n");
	}
}

