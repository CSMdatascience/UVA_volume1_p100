/*	This problem is from the UVA Online Judge problem set volume 1 (100-199)
	URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
	
	This program replicates the algorithm described in the first section of the assignment
	"Find the cycle length of a number"
	i.e. for a given number,
			if odd
				multiply by 3 and add 1
			if even
				divide by 2
			if = 1
				stop
*/

#include <iostream>

using namespace std;

int main()
{
	int n, cycle = 1;
	char ans;
	

	do
	{
		cin >> n;
		cout << n;

		while (n != 1)
		{
			cycle++;

			if ((n % 2) != 0)
			{
				n = 3 * n + 1;
				cout << " " << n;
			}
			else
			{
				n = n / 2;
				cout << " " << n;
			}
			
		}
		cout << "\nCycle Length = " << cycle;
		cycle = 1;
		cout << "\nAgain? (enter 'Y' or 'y')\n";
		cin >> ans;
		ans = tolower(ans);
	} while (ans == 'y');
	
	
	return 0;
}

/* Sample Execution:
22
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Cycle Length = 16
Again? (enter 'Y' or 'y')
y
1
1
Cycle Length = 1
Again? (enter 'Y' or 'y')
y
9
9 28 14 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
Cycle Length = 20
Again? (enter 'Y' or 'y')
y
21
21 64 32 16 8 4 2 1
Cycle Length = 8
Again? (enter 'Y' or 'y')
n
Press any key to continue . . .
*/