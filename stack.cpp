#include<iostream>
#include<stack>
#include<queue>
#define THOUSAND 1000
using namespace std;

bool checkBalanced(char *exp) {
  /* Given a string expression, check if brackets present in the expression are
   * balanced or not. Brackets are balanced if the bracket which opens last,
   * closes first. You need to return true if it is balanced, false otherwise.
   * For eg: { a + [ b+ (c + d)] + (e + f) } => true
   * and { a + [ b - c } ] => false */
  if(exp==nullptr) return true;
  stack<char> s;
  char top;
  while(*exp!='\0')
  {
    switch(*exp)
    {
      case '(': case '{': case '[':
        s.push(*exp);
        break;
      case ')':
        if(s.empty() || s.top()!='(') return false;
        s.pop();
        break;
      case '}':
        if(s.empty() || s.top()!='{') return false;
        s.pop();
        break;
      case ']':
        if(s.empty() || s.top()!='[') return false;
        s.pop();
        break;
    }
    exp++;
  }
  if(s.empty()) return true;
  return false;
}

void reverseStack(stack<int> &input, stack<int> &extra) {
  /* Reverse a given Stack with the help of another empty stack. Two stacks
   * will be given. Out of which first contains some integers and second one is
   * empty. You need to reverse the first one using second stack. Change in the
   * given first stack itself.*/
  if(input.empty()) return;
  int top=input.top();
  input.pop();
  reverseStack(input,extra);
  while(!input.empty())
  {
    extra.push(input.top());
    input.pop();
  }
  input.push(top);
  while(!extra.empty())
  {
    input.push(extra.top());
    extra.pop();
  }
}

void reverseQueue(queue<int> &q) {
  /* Given a queue of integers, reverse it without help of any explicit stack
   * or queue. You need to change in the given queue itself. */
  if(q.empty()) return;
  int front = q.front();
  q.pop();
  reverseQueue(q);
  q.push(front);
}

bool checkRedundantBrackets(char *input) {
  /* Given a string mathematical expression, return true if redundant brackets
   * are present in the expression. Brackets are redundant if there is nothing
   * inside the bracket or more than one pair of brackets are present.
   * Assume the given string expression is balanced and contains only one type
   * of bracket i.e. ().
   * Solution: Push brackets as well as operators. Whenever the bracket closes,
   * we must have operators on the stack */
  if(input==nullptr) return false;
  stack<char> s;
  char top;
  while(*input!='\0')
  {
    switch(*input)
    {
      case '(':
        s.push(*input);
        break;
      case ')':
        if(s.empty() || s.top()!='o') return true;
        s.pop(); // pop 'o'
        if(s.empty() || s.top()!='(') return true;
        s.pop(); // pop '('
        break;
      case '+': case '-': case '/': case '*':
        if(s.empty() || s.top()!='o') s.push('o');
        break;
    }
    input++;
  }
  //if(s.empty()) return true;
  return false;
}

int* stockSpan(int *price, int size) {
  /* The span si of a stock’s price on a certain day i is the minimum number of
   * consecutive days (up to the current day) the price of the stock has been
   * less than its price on that ith day. If for a particular day, if no stock
   * price is greater then just count the number of days till 0th day including
   * current day. 
   * For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which
   * has price 2) is 2 because minimum count of consecutive days (including 4th
   * day itself) from current day which has price less than 4th day is 2 (i.e.
   * day 3 & 4). Similarly, span for 2nd day is 3 because no stock price in
   * left is greater than 2nd day's price. So count is 3 till 0th day.
   * Given an input array with all stock prices, you need to return the array
   * with corresponding spans of each day.
   * Return an array that contain span for each day. For eg for size 8 array:
   * input: 60 70 80 100 90 75 80 120
   * output: 1 2 3 4 1 1 2 8 */
  if(price==nullptr || size<=0) return nullptr;
  stack<int> s;
  int *result = new int[size];
  result[0] = 1;
  for(int i=1; i<size; i++)
  {
    if(price[i]<=price[i-1]) 
    {
      result[i] = 1;
      s.push(price[i]);
      continue;
    }
    result[i] = result[i-1]+1;
  }
  return result;
}

int main()
{
  char exp[THOUSAND];
  //cin.getline(exp, THOUSAND); cout << checkRedundantBrackets(exp) <<endl;
}
