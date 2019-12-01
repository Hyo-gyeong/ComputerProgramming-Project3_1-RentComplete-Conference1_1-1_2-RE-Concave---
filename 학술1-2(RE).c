#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 두개의 문자들 연속을 표현한 단축문자열을 출력하고 그 길이를 반환한다. 
int solution(char *s)
{
	char tmp[1001] = "";
	char ch1[100];
	int count = 1;
	int i = 0;
	int slen = strlen(s);
	int LEN = 1;
	int shortest = 0;
	int tmpLEN = 1000;
	
	while (LEN < slen){
	strncpy(ch1, s, LEN); //우선 첫 묶음 넣어놓음.
	ch1[LEN] = '\0';
	while (i < slen){
		char ch2[100];
		s += LEN;
		strncpy(ch2, s, LEN); //다음묶음 들어감
		ch2[LEN] = '\0';
		if (strcmp(ch1, ch2) == 0)
			count++;
		else {
			if (count > 1){
				char numString[10];
				sprintf(numString, "%d", count);
				strcat(tmp, numString);
			}
			strcat(tmp, ch1);
			count = 1;
			strcpy(ch1, ch2);
		}
		i += LEN;
	}
	if (strlen(tmp) < tmpLEN)
		tmpLEN = strlen(tmp);
	LEN++;
	}
	printf("%s", tmp);
	return strlen(tmp);
}

int main(void)
{
    char s[1001];
    scanf("%s", s);
    printf("\n%d\n", solution(s));
}
