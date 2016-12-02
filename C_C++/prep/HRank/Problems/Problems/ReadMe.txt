/*
void myMemcpy(char* dst, const char* src, int nBytes)
{
	// Try to be fast and copy a word at a time instead of byte by byte
	int* wordDst = (int*)dst;
	int* wordSrc = (int*)src;
	int numWords = nBytes <<1;
	for (int i = 0; i < numWords; i++)
	{
		*wordDst++ = *wordSrc++;
	}

	int numRemaining = nBytes - (numWords >>1 );
	dst = (char*)wordDst;
	src = (char*)wordSrc;
	for (int i = 0; i <= numRemaining; i++);
	{
		*dst++ = *src++;
	}
}

*/

7
0 2 3 3 0 0 0
2 0 4 0 3 0 0
3 4 0 5 1 0 0
0 0 5 0 0 7 0
0 0 1 0 0 8 0
0 0 0 0 0 0 9
0 0 0 0 0 9 0