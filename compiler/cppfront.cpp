// cppfront.cpp 第一版编译器使用的前端，将AloLang代码转换为C++代码
#include <iostream>
#include <sstream>
#include <fstream>

#include <regex>

std::ifstream fin;
std::ofstream fout;

using std::cout;
using std::cerr;
using std::endl;

std::string input_file_name;
std::string output_file_name;
std::string buff; //源码

//预处理
void preProcesse() {
	std::istringstream buffin(buff);
	std::stringstream preprocessoroutput;
	std::string temp;
	while (std::getline(buffin, temp)) {
		if(temp[0]=='%')
		{
			//是预编译指令
			if (temp.substr(0, 6) == "%import") { //处理引入AloLang库
				fin.open(temp.substr(8));
				std::getline(fin, temp, char(EOF));
				preprocessoroutput << temp;
				preprocessoroutput << '\n';
			}
		}else{
			preprocessoroutput << temp;
			preprocessoroutput << '\n';
		}
		temp.erase();
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) { //检测参数不足并报错退出
		cerr << argv[0]
				<< ": fatal error: no input files\ncompilation terminated\n";
		return 1;
	} else if (argc > 2) { //监测参数过多并报错退出
		cerr << argv[0]
				<< ": fatal error: too many arguments\ncompilation terminated\n";
		return 1;
	} else {
		std::string args[argc];
		for (char i = 1; i < argc; i++)
			args[i - 1] = argv[i];
		if (args[0] == "--help" || args[0] == "-h") { //显示帮助信息
			cout << "Usage: " << argv[0] << " file_name\n";
			return 0;
		} else { //确定源文件名
			input_file_name = args[1];
			output_file_name = input_file_name + ".ac";
		}
		fin.open(input_file_name);
		std::getline(fin, buff, char(EOF));
		fin.close();
		preProcesse();
		//todo: 编译用代码放下面

		//将编译结果输出到文件
	}
	return 0;
}
