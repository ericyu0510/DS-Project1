#include <iostream>

typedef struct value {
	int x, y, value;
	bool check;
}value;

typedef struct peak {
	int col, row;
}peak;

class test_case {
public:
	void getsize();
	void store_num();
	bool peaktest(int,int);
	int row = 3, col = 0;
	int peak_num = 0;
	void set_peak(int,int);

private:
	int row_num, col_num;
	value array[3][col_num];
	peal[][]

};

int main() {
	test_case::getsize();
	for (int countrow = 3; countrow <= row_num; countrow++) {
		test_case::store_num();
		row++;
	}
	for (int countrow = 1; countrow < row_num- 1; countrow++) {
		for (int countcol = 1; countcol < row_ num - 1; countcol++) {
			if ((array + countrow * col_num + countcol)->check!=false){
				if(test_case::peaktest(countrow, countcol)) {
					test_case::set_peak(countrow, countcol);
				}
			}
		}
	}
	
	return 0;
}

void test_case::getsize() {
	std::cin << row_num << col_num;
}

void test_case::store_num() {
	if (row = 3){
		for (int count = 0; count < 3 * col_num; count++) {
			switch (count%col_num) {
			case 0:
				std::cin << array->value;
				array->check = true;
				break;
			case col_num-1:
				std::cin << (array+count)->value;
				if ((array + count)->value > (array + count - 1)->value
					&& (array + count - 1)->check = true) {
					(array + count - 1)->check = false;
					(array + count)->check = true;
				}
				break;
			default:
				std::cin << (array + count)->value;
				if ((array + count)->value > (array + count - 1)->value
					&& (array + count - 1)->check = true) {
					(array + count - 1)->check = false;
					(array + count)->check = true;
				}
				else if ((array + count)->value < (array + count - 1)->value) {
					(array + count)->check = false;
				}
				else {
					(array + count)->check = false;
				}
			}
		}
	}
	else {
		for (int count = 0; count < col_num; count++) {
			std::cin << (array + ((row - 1) % 3) + count)->value; //只需要3個row的array空間 每次要覆蓋掉
		}
		switch (count%col_num) {
		case 0:
			std::cin << array->value;
			array->check = true;
			break;
		case col_num - 1:
			std::cin << (array + count)->value;
			if ((array + count)->value > (array + count - 1)->value
				&& (array + count - 1)->check = true) {
				(array + count - 1)->check = false;
				(array + count)->check = true;
			}
			break;
		default:
			std::cin << (array + count)->value;
			if ((array + count)->value > (array + count - 1)->value
				&& (array + count - 1)->check = true) {
				(array + count - 1)->check = false;
				(array + count)->check = true;
			}
			else if ((array + count)->value < (array + count - 1)->value) {
				(array + count)->check = false;
			}
			else {
				(array + count)->check = false;
			}
		}
		return (row%3);
	}
}

bool test_case::peaktest(int col,int row) {
	if((array+row*col_num+col)->value>=)
	

}

void set_peak(int row, int col) {

	peak_num++;
}