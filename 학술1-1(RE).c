#include <stdio.h>
#include <string.h>//**함수 자유롭게 사용가능해야함.
#include <stdlib.h>

int solution(char *s)
{
	char ch1 = s[0];
	char tmp[1001];
	char tmp2[1001];
	int i = 0;
	int count = 1;
	int tmpCount = 0;
	int len = strlen(s);

	while (i < len) {
		char ch2 = s[i+1];
		if (ch1 == ch2)
			count++;
		else{
			if (count == 1){
				sprintf(tmp,"%c", ch1);
				printf("%s", tmp);
			}
			else {
				sprintf(tmp,"%d%c", count, ch1);
				printf("%s", tmp);
			}
			tmpCount += strlen(tmp);
			count = 1;
			ch1 = ch2;
		}
		i++;
	}
	return tmpCount;
}
int main(void)
{
   char s[1001];
   scanf("%s", s);
   printf("\n%d\n", solution(s));
}