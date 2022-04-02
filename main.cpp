#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1794;

/*
Input: firstString = "abcd", secondString = "bccda"
Output: 1
Explanation: The quadruple (0,0,4,4) is the only one that satisfies all the conditions and minimizes j - a.
*/
tuple<string, string, int>
testFixture1()
{
  return make_tuple("abcd", "bccda", 1);
}

/*
Input: firstString = "ab", secondString = "cd"
Output: 0
Explanation: There are no quadruples satisfying all the conditions.
*/
tuple<string, string, int>
testFixture2()
{
  return make_tuple("ab", "cd", 0);
}

void test1()
{
  auto f = testFixture1();

  cout << "Test 1 exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::count(get<0>(f), get<1>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();

  cout << "Test 2 exepct to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::count(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}