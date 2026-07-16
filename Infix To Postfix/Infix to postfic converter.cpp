#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;
int getPrecedence(char p) {
	if (p == '+' || p == '-') return 1;
	if (p == '*' || p == '/') return 2;
	return 0;
}
string InfixtoPostfix(string exp) {
	stack<char>s;
	string result="";
	for (char c : exp) {
		if (isalnum(c)) { result += c; }
		else if (c == '(') { s.push(c); }
		else if (c == ')') {
			while (!s.empty() && s.top() != '(')
			{
				result += s.top();
				s.pop();
			}s.pop();
		}
		else {
			while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)){
				result += s.top();
			s.pop();
		}s.push(c);
		}
}
while (!s.empty()) {
	result += s.top();
	s.pop();}
return result;}
int main() {
	string inf = "(A+B)*C";
	cout << "Infix:" << inf << endl;
	cout << "Postfix:" << InfixtoPostfix(inf)<<endl;
	return  0;
}