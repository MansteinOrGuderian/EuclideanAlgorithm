#pragma once
#include <iostream>
#include <vector>

void Euclidean_Algorithm_Info() {
	std::cout << "----- Euclidean Algorithm -----\n";
	std::cout << "Operating principle:\nInput: /forall a,b > 0\nOutput: gcd(a, b)\nInitial values:\nr_0 = a, r_1 = b\n";
	std::cout << "r_0 = r_1 * q_1 + r_2\nr_1 = r_2 * q_2 + r_3\n...\nr_{i-1} = r_i * q_i + r_{i+1}\n";
	std::cout << "...\nr_{n-2} = r_{n-1} * q_{n-1} + r_n\nr_{n-1} = r_n * q_n\ngcd(a, b) = r_n\n\n";
}

long long int Euclidean_Algorithm(long long int& first_number, long long int& second_number) {
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

void Extended_Euclidean_Algorithm_Info() {
	std::cout << "Extended Euclidean Algorithm include simple Euclidean Algorithm and small \"supplement\":\n";
	Euclidean_Algorithm_Info();
	std::cout << "----- Extended Euclidean Algorithm(\"supplement\") -----\n";
	std::cout << "Operating principle:\nInput: /forall a,b > 0\nOutput: if gcd(a, b) = 1	a^{-1} mod b = u, b^{-1} mod a = v\nOtherwise doesn't exist a^{-1} mod b, b^{-1} mod a\n";
	std::cout << "Initial values:\nu_0 = 1, u_1 = 0, v_0 = 0, v_1 = 1\nOn each step calculating u_{i+1}, v_{i+1} using formulas:\n";
	std::cout << "u_{i+1} = u_{i-1} - u_i * q_i\nv_{i+1} = v_{i-1} - v_i * q_i\n";
	std::cout << "When |u_{i+1}| = a and |v_{i+1}| = b, where || is absolute value, u = u_i, v = v_i\n";
}

void Extended_Euclidean_Algorithm(long long int& first_number, long long int& second_number) {
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
	
	long long int gcd = r_i_vector.back();
	std::vector<long long int> u_i_minus_one_vector, u_i_vector, u_i_plus_one_vector, v_i_minus_one_vector, v_i_vector, v_i_plus_one_vector;
	long long int u_i_minus_one = 1, u_i = 0, u_i_plus_one = 1, v_i_minus_one = 0, v_i = 1, v_i_plus_one = 0;
	for (long long int i = 0; i < q_vector.size(); i++) {
		u_i_plus_one = u_i_minus_one - u_i * q_vector[i];
		v_i_plus_one = v_i_minus_one - v_i * q_vector[i];
		u_i_minus_one_vector.push_back(u_i_minus_one), u_i_vector.push_back(u_i), u_i_plus_one_vector.push_back(u_i_plus_one);
		v_i_minus_one_vector.push_back(v_i_minus_one), v_i_vector.push_back(v_i), v_i_plus_one_vector.push_back(v_i_plus_one);
		u_i_minus_one = u_i, u_i = u_i_plus_one;
		v_i_minus_one = v_i, v_i = v_i_plus_one;
	}
	for (long long int i = 0; i < q_vector.size(); i++) {
		std::cout << '\n' << (i + 1) << ' ' << r_i_minus_one_vector[i] << ' ' << r_i_vector[i] << ' ' << r_i_plus_one_vector[i];
 		std::cout << " | " << q_vector[i] << ' ' << u_i_minus_one_vector[i] << ' ' << u_i_vector[i] << ' ' << u_i_plus_one_vector[i];
		std::cout << ' ' << v_i_minus_one_vector[i] << ' ' << v_i_vector[i] << ' ' << v_i_plus_one_vector[i] << '\n';
	}
	u_i = u_i_minus_one;
	v_i = v_i_minus_one;
	std::cout << '\n' << "Should fulfilled next equation:\na*u + b*v = gcd(a, b)\n";
	std::cout << (first_number * u_i + second_number * v_i == gcd ? "Correct\n" : "Incorrect\n");
	if (gcd == 1) {
		std::cout << "a and b numbers are coprime integers\n";
		std::cout << "u = a^{-1} mod b and v = b^{-1} mod a\n";
		std::cout << "a^{-1} mod b = " << u_i << '\n' << "b^{-1} mod a = " << v_i << '\n';
	}
	else {
		std::cout << "a and b numbers aren't coprime integers\n";
		std::cout << "u != a^{-1} mod b and v != b^{-1} mod a\n";
	}
}