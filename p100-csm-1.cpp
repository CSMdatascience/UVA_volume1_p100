/*	This problem is from the UVA Online Judge problem set volume 1 (100-199)
	URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
	
	From the assignment sheet:
   "Input
	The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers
	will be less than 10,000 and greater than 0.
	You should process all pairs of integers and for each pair determine the maximum cycle length over
	all integers between and including i and j.
	You can assume that no operation overflows a 32-bit integer.

	Output
	For each pair of input integers i and j you should output i, j, and the maximum cycle length for
	integers between and including i and j. These three numbers should be separated by at least one space
	with all three numbers on one line and with one line of output for each line of input. The integers i
	and j must appear in the output in the same order in which they appeared in the input and should be
	followed by the maximum cycle length (on the same line)."
*/


#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	//i is lower bound; j is upper bound
	int i, j;
	
	//holds user's decision to run again or terminate program
	char ans;
	
	do
	{
		//holds cycle length of i, j, and all integers in between
		vector<int> cycles;

		//user enters i and j
		cin >> i >> j;

		//print input
		cout << i << " " << j << " ";

		//calculate cycle length of each integer beginning with i, ending with j
		for (i; i < (j + 1); i++)
		{
			//temporary holder for integer currently operating on
			int h = i;

			//holds cycle length of current integer h
				//resets to 1 for each new integer h
			int cycle = 1;

			//calculate cycle length of h
			while (h != 1)
			{
				cycle++;

				if ((h % 2) != 0)
					h = 3 * h + 1;
				else
					h = h / 2;
			}
			//store cycle length of h in cycles
			cycles.push_back(cycle);
		}
		//print max cycle length in cycles
		cout << *max_element(cycles.begin(), cycles.end());

		//reset cycles to an empty vector
		cycles.clear();

		//ask user to repeat program
		cout << "\nAgain? (enter 'Y' or 'y')\n";

		cin >> ans;
		ans = tolower(ans);
	} while (ans == 'y');
	
	
	return 0;
}

/* Sample Execution:
1 10
1 10 20
Again? (enter 'Y' or 'y')
y
100 200
100 200 125
Again? (enter 'Y' or 'y')
y
201 210
201 210 89
Again? (enter 'Y' or 'y')
y
900 1000
900 1000 174
Again? (enter 'Y' or 'y')
n
Press any key to continue . . .
*/