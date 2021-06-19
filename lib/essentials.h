#ifndef __CPPTOOLS
#define __CPPTOOLS

#include <string>
#include <fstream>
using namespace std;

namespace essent {

	class File{
	public:
		ofstream out;
		ifstream in;
		string filename;

		File(string filename){
			File::filename = filename;
		}

		void write(string text){
			out.open(filename, ios::out);
			out << text;
			out.close();
		}

		void append(string text){
			out.open(filename, ios::app);
			out << text;
			out.close();
		}

		string read(){
			in.open(filename);
			string buffer, text;
			while(!in.eof()){
				getline(in, buffer);
				text += buffer+"\n";
			}
			in.close();
			return text;
		}
	};



	class StringTool{
	public:
		string content;
		int length;

		StringTool(string content){
			StringTool::content = content;
			StringTool::length = content.size();
		}

		string append(string thing){
			return StringTool::content + thing;
		}

		string remove(string thing){
			string newtext;
			StringTool text = StringTool(StringTool::content);
			if(text.includes(thing)){
				int textLooper = 0;
				int i = 0;
				while(i < text.length){
					if(text.content[i] == thing[textLooper]){
						textLooper++;
					}
					else{
						newtext += text.content[i];
						textLooper = 0;
					}
					i++;
				}
			}
			return newtext;
		}
 
		bool startsWith(string thing){
			bool isStart;
			if(thing.size() <= StringTool::length){
				for(int i = 0; i < thing.size(); i++){
					if(thing[i] == StringTool::content[i]){
						isStart = true;
					}
					else{
						isStart = false;
					}
				}
			}
			else{
				isStart = false;
			}
			return isStart;
		}

		bool includes(string theText){
			// int tLength = text.size();
			StringTool text = StringTool(theText);
			bool isInclude = false;
			if(text.length > StringTool::length){
				cout << 1;
			}
			else if(text.content == StringTool::content){
				isInclude = true;
			}
			else{
				int textLooper = 0;
				for(int i = 0; i < StringTool::length; i++){
					if(StringTool::content[i] == text.content[textLooper]){
						isInclude = true;
						if(textLooper < text.length){
							textLooper++;
						}
					}
					else if(textLooper >= text.length){
						break;
					}
					else{
						isInclude = false;
						textLooper = 0;
					}
				}
			}
			return isInclude;
		}
};

}

#endif