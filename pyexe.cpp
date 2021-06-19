#include <iostream>
#include "lib/essentials.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	system("mkdir result\\dist");
	string filename = argv[1];
	ifstream pythonfile("src/"+filename+".py");
	if(pythonfile.fail()){
		cout << "File "+filename+".py is not found in PyExe/src"<<endl;
	}
	else{
		essent::File file1 = essent::File("lib/__firstToLoad.cpp");
		essent::File file2 = essent::File("lib/__secondToLoad.cpp");

		// Concatenates the templates with gotten name

		string codes = file1.read() + "\tsystem(\"python "+filename+".py\");"+ file2.read();
		essent::File file = essent::File("cppsource/"+filename+".cpp");

		file.write(codes);
		string cmd ="g++ cppsource/"+filename+".cpp -B result/dist -o"+filename+".exe";
		system(cmd.c_str());
		cmd = "move "+ filename+".exe result\\dist";
		system(cmd.c_str());

		essent::File src_file("src/"+filename+".py");
		essent::File des_file("result/dist/"+filename+".py");
		des_file.write(src_file.read());
	}
	return 0;
}