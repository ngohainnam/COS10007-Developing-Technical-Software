struct reverse
{
	char letter;
	struct reverse *next;
};

typedef struct reverse Reverse;
typedef Reverse *reversePtr;

void pushPop(reversePtr topPtr, char str1[], char str2[], int len);