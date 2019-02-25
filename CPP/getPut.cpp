#include <iostream>
using namespace std;

int main ()
{
  char ch;
  cin.get(ch);
  while(ch != '\n')
  {
    cout.put(ch);
    cin.get(ch);
  }
  cout.put(ch);

  return 1;
}
