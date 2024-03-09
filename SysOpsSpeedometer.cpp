#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

// Function to measure the execution time of addition operations
template <typename T>
double measure_addition() {
    const int num_iterations = 1000000;
    T a = 5, b = 10;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        T sum = a + b;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    double operations_per_second = (static_cast<double>(num_iterations) * 1000000) / elapsed_time;
    return operations_per_second;
}

// A function to measure the execution time of subtraction operations
template <typename T>
double measure_subtraction() {
    const int num_iterations = 1000000;
    T x = 3.5, y = 2.0;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        T diff = x - y;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    double operations_per_second = (static_cast<double>(num_iterations) * 1000000) / elapsed_time;
    return operations_per_second;
}

// Function for measuring the time of execution of multiplication operations
template <typename T>
double measure_multiplication() {
    const int num_iterations = 1000000;
    T p = 2.5, q = 1.5;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        T product = p * q;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    double operations_per_second = (static_cast<double>(num_iterations) * 1000000) / elapsed_time;
    return operations_per_second;
}

// A function for measuring the execution time of division operations
template <typename T>
double measure_division() {
    const int num_iterations = 1000000;
    T c = 20, d = 4;
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_iterations; ++i) {
        T quotient = c / d;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    double operations_per_second = (static_cast<double>(num_iterations) * 1000000) / elapsed_time;
    return operations_per_second;
}

int main() {

    double max_ops_per_sec = 0.0;

    // Measurement of the result and the maximum to add
    double addition_ops_per_sec_int = measure_addition<int>();
    max_ops_per_sec = std::max(max_ops_per_sec, addition_ops_per_sec_int);

    double addition_ops_per_sec_long = measure_addition<long>();
    max_ops_per_sec = std::max(max_ops_per_sec, addition_ops_per_sec_long);

    double addition_ops_per_sec_float = measure_addition<float>();
    max_ops_per_sec = std::max(max_ops_per_sec, addition_ops_per_sec_float);

    double addition_ops_per_sec_double = measure_addition<double>();
    max_ops_per_sec = std::max(max_ops_per_sec, addition_ops_per_sec_double);


    // Measure the result and the maximum to subtract
    double subtraction_ops_per_sec_int = measure_subtraction<int>();
    max_ops_per_sec = std::max(max_ops_per_sec, subtraction_ops_per_sec_int);

    double subtraction_ops_per_sec_long = measure_subtraction<long>();
    max_ops_per_sec = std::max(max_ops_per_sec, subtraction_ops_per_sec_long);

    double subtraction_ops_per_sec_float = measure_subtraction<float>();
    max_ops_per_sec = std::max(max_ops_per_sec, subtraction_ops_per_sec_float);

    double subtraction_ops_per_sec_double = measure_subtraction<double>();
    max_ops_per_sec = std::max(max_ops_per_sec, subtraction_ops_per_sec_double);


    // Measurement of the result and the maximum for multiplication
    double multiplication_ops_per_sec_int = measure_multiplication<int>();
    max_ops_per_sec = std::max(max_ops_per_sec, multiplication_ops_per_sec_int);

    double multiplication_ops_per_sec_long = measure_multiplication<long>();
    max_ops_per_sec = std::max(max_ops_per_sec, multiplication_ops_per_sec_long);

    double multiplication_ops_per_sec_float = measure_multiplication<float>();
    max_ops_per_sec = std::max(max_ops_per_sec, multiplication_ops_per_sec_float);

    double multiplication_ops_per_sec_double = measure_multiplication<double>();
    max_ops_per_sec = std::max(max_ops_per_sec, multiplication_ops_per_sec_double);


    // Measurement of the result and maximum for division
    double division_ops_per_sec_int = measure_division<int>();
    max_ops_per_sec = std::max(max_ops_per_sec, division_ops_per_sec_int);

    double division_ops_per_sec_long = measure_division<long>();
    max_ops_per_sec = std::max(max_ops_per_sec, division_ops_per_sec_long);

    double division_ops_per_sec_float = measure_division<float>();
    max_ops_per_sec = std::max(max_ops_per_sec, division_ops_per_sec_float);

    double division_ops_per_sec_double = measure_division<double>();
    max_ops_per_sec = std::max(max_ops_per_sec, division_ops_per_sec_double);


    // Output information to the console
    std::cout << "\n Determination of the speed of the computing system:\n";

    // Lists for output to the table
    std::vector<std::string> names = { "+ int", "+ long", "+ float", "+ double", "- int", "- long", "- float", "- double", "* ine", "* long", "* float", "* double", "/ int", "/ long", "/ float", "/ double" };

    std::vector<double> speeds = { addition_ops_per_sec_int, addition_ops_per_sec_long, addition_ops_per_sec_float, addition_ops_per_sec_double,
                                   subtraction_ops_per_sec_int, subtraction_ops_per_sec_long, subtraction_ops_per_sec_float, subtraction_ops_per_sec_double,
                                   multiplication_ops_per_sec_int, multiplication_ops_per_sec_long, multiplication_ops_per_sec_float, multiplication_ops_per_sec_double,
                                   division_ops_per_sec_int, division_ops_per_sec_long, division_ops_per_sec_float, division_ops_per_sec_double };

    // Percent calculation for the table

    std::vector<int> rounded_speed_percentages;

    for (const auto& speed : speeds) {
        double speed_percent = (speed / max_ops_per_sec) * 100;
        int rounded_speed_percent = static_cast<int>(speed_percent);
        rounded_speed_percentages.push_back(rounded_speed_percent);
    }

    // Output to the console
    std::cout << std::left << std::setw(30) << "Operation and Data Type" << std::setw(20) << "Operations/Second" << std::setw(30) << "Graphic demonstration" << std::setw(3) << "Speed (%)" << std::endl;
    for (int i = 0; i < 16; i++) {
        std::cout << std::setw(30) << names[i] << std::setw(20) << speeds[i] << std::setw(30) << std::string(rounded_speed_percentages[i] / 5, 'X') << std::setw(3) << rounded_speed_percentages[i] << "%" << std::endl;
    }
    return 0;
}