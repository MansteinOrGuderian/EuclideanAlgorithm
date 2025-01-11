#pragma once
#include <iostream>
#include <vector>

long long int Euclidean_Algorithm(long long int& first_number, long long int& second_number) {
	// Input: a, b, a,b > 0
	// Output: gcd(a, b)
	// r_0 = a, r_1 = b
	// r_0 = r_1 * q_1 + r_2
	// r_1 = r_2 * q_2 + r_3
	// ...
	// r_(i-1) = r_i * q_i + r_(i+1)
	// ...
	// r_(n-2) = r_(n-1) * q_(n-1) + r_n
	// r_(n-1) = r_n * q_n  -> gcd(a, b) = r_n 
	long long int r_i_minus_one = first_number, r_i = second_number, q(0), r_i_plus_one(1);
	std::vector<long long int> r_i_minus_one_vector, r_i_vector, q_vector, r_i_plus_one_vector;
	
	while (r_i_plus_one != 0) {
		q = r_i_minus_one / r_i;
		r_i_plus_one = r_i_minus_one % r_i;
		q_vector.push_back(q), r_i_plus_one_vector.push_back(r_i_plus_one);
		r_i_minus_one_vector.push_back(r_i_minus_one), r_i_vector.push_back(r_i);
		r_i_minus_one = r_i;
		r_i = r_i_plus_one;
	}
	for (long long int i = 0; i < q_vector.size(); i++)
		std::cout << r_i_minus_one_vector[i] << " = " << r_i_vector[i] << " * " << q_vector[i] << " + " << r_i_plus_one_vector[i] << '\n';
	return r_i_vector.back();
}