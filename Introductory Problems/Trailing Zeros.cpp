#include <bits/stdc++.h>

using namespace std;

/*
 * How many trailing zeros does N! have ? In other words, how many times
 * can we divide N! by 10 until it's no longer dividible by 10.
 *
 * One way of finding this out is by looking at the prme factorization of N!.
 * If 10 divides N! then the prime factorization of 10 must be contained in
 * the prime factorization of N! and since 10 = 2 * 5 then the question 
 * become how many pairs {2,5} are in N! prime factorization.
 *
 * N! = 1 * 2 * 3 * 4 * 5 * 6
 *
 * Since 2 is a much more common factor and the pair requeres both numbers to
 * be present the answer becomes the number of times 5 appears in N! prime
 * factorization. Given that N! is the product of all positive integers less
 * than or equal to N we can conclude that the answer is the number of times 5
 * come up in the prime factorization of all integers belonging to the 
 * interval [1,N].
 *
 * One might guess that the answer is N/5 since that's the number of multiples
 * of 5 in the interval but this would be wrong since 25 has tow 5's in its
 * prime factorization and 125 has threee and so on. To solve this problem
 * we must take into account every multiple of every power of five less 
 * than N. So if N = 50 tha answer would be 50 / 5 + 50 / 25.
 * The  folloing expression shows a generalization for any given N
 * (where M is largest integer such that 5^M <= N)
 *
 * M = low[log5]N
 * answer = sum += (k = 1) to M low[n / 5^k]
 * */

int main(){
	int n; 
	cin >> n;
	int b = 5, count = 0;
	while(n / b > 0) {
		count += n / b;
		b *= 5;
	}
	cout << count;
	return 0;
}
