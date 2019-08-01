#include "ArrayStack.h"

//이거 쓰지마 ㅋㅋ
bool passSingleQuote(ArrayStack& stack, char ch) {	//3장의 1번 문제.

	if (!stack.isEmpty())																//스택이 비어있지 않을 때,
	{
		char isq = stack.peek();														//스택에서 한 문자 peek 한다
		if (isq == '\'')
			if(ch == '\'')//peek한 문자가 '이면서 ch가 '일때 
				stack.pop();																//pop한다
			else if(ch == '{'||ch == '}'||ch=='['||ch==']'||ch=='('||ch==')')					//peek한 문자가 따옴표이면서 ch가 괄호일때
				return 0;																	//0을 반환한다(=괄호를 무시한다)
		else if (isq != '\'' && ch == '\'')												//peek한 문자가 '이 아니면서 ch가 '일때 
			stack.push(ch);																//ch를 push한다
	return 1;
	}
	//if (ch == '\'')stack.push(ch);	
	//if (stack.peek() == '\'')stack.pop();
}

//스택이 비어있지 않을 때
//스택에서 한 문자 peek 한다
//peek한 문자가 따옴표이면
//ch가 괄호일 때 0을 반환한다
//ch가 따옴표이면 pop한다
//peek한 문자가 따옴표가 아니면
//ch가 따옴표이면 push한다

bool checkMatching(const char* filename) {
	FILE* fp; 
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
		error("Error: 파일이 존재하지 않습니다.\n");

	int nLine = 1;	//파일의 줄 수
	int nChar = 0;	//파일의 문자 수
	ArrayStack stack;
	char ch;		//파일에서 읽은 단어
	
	while ((ch = getc(fp)) != EOF) {	//파일의 끝이 아니라면 이하 반복한다
		if (ch == '\n') nLine++;		//ch가 개행문자라면 줄 수를 하나 추가한다.
		nChar++;

		if (ch == '\'') {
			if (stack.peek() == ch)stack.pop();
			else stack.push(ch);
		}
		passSingleQuote(stack, ch);
		if (ch == '[' || ch == '(' || ch == '{')
			stack.push(ch);
		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = stack.pop();
			if ((ch == ']' && prev != '[') ||
				(ch == ')' && prev != '(') ||
				(ch == '}' && prev != '{')) break;
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("Error: 문제 발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf("OK: 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}
int main() {
	checkMatching("ArrayStack.h");
	checkMatching("CheckMatching.cpp");
}