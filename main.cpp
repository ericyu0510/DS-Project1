#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct value {
	int x, y, value;
	bool check;
};

struct peak {
	int col, row;
};

class testcase {
public:
	std::ifstream input_file;
	std::ofstream output_file;
	testcase();
	void getsize(std::ifstream & input);
	void store_num(int, std::ifstream & input);
	void peaktest(int);
	int row = 1;
	int peak_num = 0;
	void set_peak(int, int);
	value* array;
	std::vector<peak> peak_list;
	int row_num, col_num;
};

int main(int argc, char * argv[]) {

	std::ifstream input_file;
	std::ofstream output_file;
	input_file.open("matrix1.data");
	output_file.open("final.peak");

	testcase map;
	map.getsize(input_file);
	map.store_num(1, input_file);
	for (int countrow = 2; countrow <= map.row_num; countrow++) {
		map.store_num(countrow, input_file);
		map.peaktest(countrow - 1);
	}
	map.peaktest(map.row_num);
	output_file << map.peak_num << '\n';
	for (int count = 0; count < map.peak_num; count++) {
		output_file << map.peak_list[count].row << " " << map.peak_list[count].col << "\n";
	}
	return 0;
}

testcase::testcase() :array(nullptr) {

}

void testcase::getsize(std::ifstream & input_file) {

	delete[] array;
	input_file >> row_num >> col_num;
	array = new value[3 * col_num];
}

void testcase::store_num(int row, std::ifstream & input_file) {
	if (row == 1 || row == 2 || row == 3) {
		for (int count = 0; count < col_num; count++) {
			input_file >> (array + (row - 1)*col_num + count)->value;
			(array + (row - 1)*col_num + count)->check = true;
			if (count > 0) {
				if ((array + (row - 1)*col_num + count)->value >
					(array + (row - 1)*col_num + count - 1)->value) {
					(array + (row - 1)*col_num + count - 1)->check = false;
				}
				else if ((array + (row - 1)*col_num + count)->value <
					(array + (row - 1)*col_num + count - 1)->value) {
					(array + (row - 1)*col_num + count)->check = false;
				}
			}
			if (row > 1) {
				if ((array + (row - 1)*col_num + count)->value >
					(array + (row - 2)*col_num + count)->value) {
					(array + (row - 2)*col_num + count)->check = false;
				}
				else if ((array + (row - 1)*col_num + count)->value < (array + (row - 2)*col_num + count)->value) {
					(array + (row - 1)*col_num + count)->check = false;
				}
			}
		}
	}
	else {
		for (int count = 0; count < col_num; count++) {
			input_file >> (array + ((row - 1) % 3)*col_num + count)->value;
			(array + ((row - 1) % 3)*col_num + count)->check = true;
			if (count > 0) {
				if ((array + ((row - 1) % 3)*col_num + count)->value >
					(array + ((row - 1) % 3)*col_num + count - 1)->value) {
					(array + ((row - 1) % 3)*col_num + count - 1)->check = false;
				}
				else if ((array + ((row - 1) % 3)*col_num + count)->value <
					(array + ((row - 1) % 3)*col_num + count - 1)->value) {
					(array + ((row - 1) % 3)*col_num + count)->check = false;
				}
			}
			if ((array + ((row - 1) % 3)*col_num + count)->value >
				(array + ((row + 1) % 3)*col_num + count)->value)
				(array + ((row + 1) % 3)*col_num + count)->check = false;
			else if ((array + ((row - 1) % 3)*col_num + count)->value <
				(array + ((row + 1) % 3)*col_num + count)->value)
				(array + ((row - 1) % 3)*col_num + count)->check = false;
		}
	}
}

void testcase::peaktest(int row) {
	for (int col = 1; col <= col_num; col++) {
		if ((array + ((row - 1) % 3)*row_num + (col - 1))->check == true)
			set_peak(row, col);
	}
}

void testcase::set_peak(int row, int col) {
	peak temp;
	temp.row = row;
	temp.col = col;
	peak_list.push_back(temp);
	peak_num++;
}