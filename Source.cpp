#include<conio.h>
#include<iostream>
using namespace std;
#include<math.h>
#include<string>
class stack
{
public:
	string s;
	int top;
	stack(){
		top = -1;
	}

	bool isFull(int size){
		return top == (size - 1);

	}
	bool isEmpty(){
		return top < 0;
	}
	void push(char a[], char c, int size){//we insert the characters of the string in the dynamic array using the pointer we created in the main function...
		if (isFull(size) == false){
			top++;
			a[top] = c;
		}
		else{
			cout << "stack overflow!" << endl;//if the size increases the count1 value it means our stack is full...
		}

	}
	char pop(char *a){
		char element = -1;
		if (!isEmpty()){
			element = a[top];
			a[top--] = -1;
			return element;//the element char is compared with the opening brace and we match it..
		}
		else{
			cout << "stack empty" << endl;
			return 0;
		}
	}
};


int checker(){

	stack one;
	char *array1;
	int count = 0, count1 = 0;

	cout << "Enter your string" << endl;
	cin >> one.s;
	bool validity = true;
	for (int i = 0; i < one.s.size(); i++){
		if (one.s[i] == '(' || one.s[i] == '[' || one.s[i] == '{'){
			count++;//to check the number of opening brackets..
			count1++;//to create an array for camparison..
		}
		else
		if (one.s[i] == ')' || one.s[i] == ']' || one.s[i] == '}'){
			count--;//to check the number of closing brackets..
		}
	}
	array1 = new char[count1];


	if (count != 0){
		cout << "error, check braces!" << endl;
		return 0;
	}


	for (int i = 0; i < one.s.size(); i++) {  //now it compares whether the closing or opening braces are of same type or not..
		if (one.s[i] == '(' || one.s[i] == '[' || one.s[i] == '{'){
			one.push(array1, one.s[i], count1);
		}
		else if (one.s[i] == ')' || one.s[i] == ']' || one.s[i] == '}'){

			char temp = one.pop(array1);

			if (temp == '(' && one.s[i] == ')'){
				validity = true;//mathches the round brackets...
			}

			else if (temp == '{' && one.s[i] == '}'){
				validity = true;//matches the curly brackets..
			}

			else if (temp == '[' && one.s[i] == ']'){
				validity = true;//matches the square brackets...
			}

			else{
				validity = false;
			}
		}
	}
	if (validity == true){
		cout << "Braces Match! Valid string!" << endl;
		return 1;
	}
	else{
		cout << "invalid string! check braces type!" << endl;
		return 0;
	}




}



void linear(int a, int b)
{
	float sol = -b / a;
	cout << "solution of linear equation = " << sol;


}
void quadratic(int a, int b,int c)
{
	float x1, x2, determinant, realPart, imaginaryPart;

	determinant = b*b - 4 * a*c;
    x1 = (-b + sqrt(determinant)) / (2 * a);
	x2 = (-b - sqrt(determinant)) / (2 * a);
	cout << "the root of the equation are" << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
}





void main(){
    string eq;
	cout << "enter the string for expression" << endl;
	cin >> eq;

	bool check;
	check = checker();



	quadratic(1, 5, 6);


	_getch();

}