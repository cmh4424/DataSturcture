#include "ArrayStack.h"

//�̰� ������ ����
bool passSingleQuote(ArrayStack& stack, char ch) {	//3���� 1�� ����.

	if (!stack.isEmpty())																//������ ������� ���� ��,
	{
		char isq = stack.peek();														//���ÿ��� �� ���� peek �Ѵ�
		if (isq == '\'')
			if(ch == '\'')//peek�� ���ڰ� '�̸鼭 ch�� '�϶� 
				stack.pop();																//pop�Ѵ�
			else if(ch == '{'||ch == '}'||ch=='['||ch==']'||ch=='('||ch==')')					//peek�� ���ڰ� ����ǥ�̸鼭 ch�� ��ȣ�϶�
				return 0;																	//0�� ��ȯ�Ѵ�(=��ȣ�� �����Ѵ�)
		else if (isq != '\'' && ch == '\'')												//peek�� ���ڰ� '�� �ƴϸ鼭 ch�� '�϶� 
			stack.push(ch);																//ch�� push�Ѵ�
	return 1;
	}
	//if (ch == '\'')stack.push(ch);	
	//if (stack.peek() == '\'')stack.pop();
}

//������ ������� ���� ��
//���ÿ��� �� ���� peek �Ѵ�
//peek�� ���ڰ� ����ǥ�̸�
//ch�� ��ȣ�� �� 0�� ��ȯ�Ѵ�
//ch�� ����ǥ�̸� pop�Ѵ�
//peek�� ���ڰ� ����ǥ�� �ƴϸ�
//ch�� ����ǥ�̸� push�Ѵ�

bool checkMatching(const char* filename) {
	FILE* fp; 
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
		error("Error: ������ �������� �ʽ��ϴ�.\n");

	int nLine = 1;	//������ �� ��
	int nChar = 0;	//������ ���� ��
	ArrayStack stack;
	char ch;		//���Ͽ��� ���� �ܾ�
	
	while ((ch = getc(fp)) != EOF) {	//������ ���� �ƴ϶�� ���� �ݺ��Ѵ�
		if (ch == '\n') nLine++;		//ch�� ���๮�ڶ�� �� ���� �ϳ� �߰��Ѵ�.
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
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("Error: ���� �߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("OK: ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}
int main() {
	checkMatching("ArrayStack.h");
	checkMatching("CheckMatching.cpp");
}