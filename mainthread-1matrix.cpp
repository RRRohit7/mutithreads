#include<iostream>
#include<fstream>

using namespace std;

double** dynamic_array(int rows,int cols){
	double** array = (double**) malloc(rows * sizeof(double*));
	for(size_t i = 0; i < rows; i++){
		array[i] = (double*) malloc(cols * sizeof(double));
	}
	return array;
}

void free_memory(double** array, int rows){
	for(int i = 0; i < rows; i++){
		free(array[i]);	
	}
	free(array);
}

void matmul(double** mat1, double** mat2, double** res){
	double sum;
	for(int i=0; i<1000; i++){
		for(int j=0; j<1000; j++){
			for(int k=0; k<1000; k++){
				sum  = sum + mat1[i][k] * mat2[k][j];
			}
			res[i][j] = sum;
			sum = 0;
		}
	}
}

int main(){
	int rows = 1000;
	int cols = 1000;
	double** mat1 = dynamic_array(rows, cols);
	double** mat2 = dynamic_array(rows, cols);
	double** res = dynamic_array(rows, cols);

	ifstream file1("data1", std::ios::binary);
	ifstream file2("data2", std::ios::binary);

	if(!file1 || !file2){
		std::cerr << "Files are corrupt!!" <<endl;
		free_memory(mat1, rows);
		free_memory(mat2, rows);
		free_memory(res, rows);
	}
	for(int i = 0; i< rows; i++){
		file1.read(reinterpret_cast<char*>(mat1[i]), cols*sizeof(double));
		file2.read(reinterpret_cast<char*>(mat2[i]), cols*sizeof(double));
	}
	
	file1.close();
	file2.close();

	matmul(mat1, mat2, res);
	
	/*for(int i = 0; i< rows; i++){
		for(int j=0; j<cols; j++){
			cout << mat2[i][j] << endl;
		}
	} */
	cout << fixed;
	cout << res[6][0] << " " << res[5][3] << " " << res[5][4] << " " << res[901][7] << endl;
	
	free_memory(mat1, rows);
	free_memory(mat2, rows);
	free_memory(res, rows);

	return 0;
}
