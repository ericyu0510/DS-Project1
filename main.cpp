#include <iostream>
#include <fstream>

typedef struct value {
	int x, y, value;
	bool check;
}value;

typedef struct peak {
	int col, row;
}peak;

class testcase {
public:
	void getsize(value*);
	void store_num(int, value*);
	void peaktest(int);
	int row = 1;
	int peak_num = 0;
	void set_peak(int, int);
	value* array;
	peak peak_list[10];
	int row_num, col_num;
};

int main(int argc, char * argv[]) {
	std::fstream myfile("matrix.data", std::ios_base::in);


	testcase* map;
	map->getsize(map->array);
	map->store_num(1, map->array);
	for (int countrow = 2; countrow <= map->row_num; countrow++) {
		map->store_num(countrow,map->array);
		map->peaktest(countrow - 1);
	}
	map->peaktest(map->row_num);


	return 0;
}

void testcase::getsize(value* array) {

	//std::cin >> row_num >> col_num;
	myfile >> row_num >> col_num;
	array = new value[row_num*col_num];
}

void testcase::store_num(int row, value* array) {
	if (row == 1 || row == 2 || row == 3) {
		for (int count = 0; count < col_num; count++) {
			/*std::cin*/ myfile >> (array + (row - 1)*col_num + count)->value;
			(array + (row - 1)*col_num + count)->check = true;
			if (count > 0) {
				if ((array + (row - 1)*col_num + count)->value >
					(array + (row - 1)*col_num + count - 1)->value) {
					(array + (row - 1)*col_num + count - 1)->check = false;
				}
				else if ((array + (row - 1)*col_num + count)->value <(array + (row - 1)*col_num + count - 1)->value){
					(array + (row - 1)*col_num + count)->check = false;
				}
			}
			if (row > 1) {
				if ((array + (row - 1)*col_num + count)->value >
					(array + (row - 2)*col_num + count)->value) {
					(array + (row - 2)*col_num + count)->check = false;
				}
				else if ((array + (row - 1)*col_num + count)->value <(array + (row - 2)*col_num + count)->value) {
					(array + (row - 1)*col_num + count)->check = false;
				}
			}
		}
	}
	else {
		for (int count = 0; count < col_num; count++) {
			/*std::cin*/myfile >> (array + ((row - 1) % 3) + count)->value;
			(array + ((row - 1) % 3) + count)->check = true;
			if (count > 1) {
				if ((array + ((row - 1) % 3) + count)->value > (array + ((row - 1) % 3) + count - 1)->value) {
					(array + ((row - 1) % 3) + count - 1)->check = false;
				}
				else if ((array + ((row - 1) % 3) + count)->value < (array + ((row - 1) % 3) + count - 1)->value) {
					(array + ((row - 1) % 3) + count)->check = false;
				}
			}
			if ((array + ((row - 1) % 3) + count)->value > (array + ((row + 1) % 3) + count)->value)
				(array + ((row + 1) % 3) + count)->check = false;
			else if ((array + ((row - 1) % 3) + count)->value < (array + ((row + 1) % 3) + count)->value)
				(array + ((row - 1) % 3) + count)->check = false;
		}
	}
}

void testcase::peaktest(int row) {
	for (int col = 1; col <= col_num; col++) {
		if ((array + (row - 1)*row_num + (col - 1))->check == true)
			set_peak(row, col);
	}
}

void testcase::set_peak(int row ,int col) {
	peak_list[peak_num].row = row;
	peak_list[peak_num].col = col;
	peak_num++;
}