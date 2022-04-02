#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>
using namespace sol1794;
using namespace std;

/*takeaways
  - for the j-a to be minimum we need to make the j as small
    as possible and a as big as possible. don't forget j-a
    can be a negative number and -5 < -4 for example.

  - you want the substring from the first string to be as close
    as possible to the left and the substring from the second
    to be as close as possible to the right - we are looking
    for the max distance between them

  - and you also want the substring as small as possible
    as substring from the first will grow to the right
    , when you look at it from the left to right, and
    the substring will grow from right to left, when
    you look at it from right to left - this will reduce
    the distance
    first   ...xxx........
    second  .........xxx...
  - so in the end you want the substring to be just one
    char. And the distance between the substring from
    the first string and the one from the second string
    need to be the largest

*/

int Solution::count(string first, string second)
{
  const int m = first.size(), n = second.size();
  /* store the rightmost index among the same chars
     from the second string
  */
  auto ridx = unordered_map<char, int>();
  for (auto i = 0; i < n; i++)
    ridx[second[i]] = i;

  int min = INT_MAX, count = 0;

  for (auto i = 0; i < m; i++)
  {
    auto c = first[i];
    if (ridx.count(c))
    {
      /* max distance in a sense means it produces
         the smallest j-a value with "j" being the
         index of the last char of the substring
         from the first string and "a" being the
         first char of the substring from the
         second string
      */
      auto distance = i - ridx[c];
      if (distance < min)
        min = distance, count = 1;
      else if (distance == min)
        count++;
    }
  }

  return count;
}