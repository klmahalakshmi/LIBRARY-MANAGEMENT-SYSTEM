#include<iostream>
using namespace std;

class Book{

	private:
	string bookName;
	string pages;
	string publisherName;
	vector<string>students;

	public:
	void setBookName(string bName){
		bookName=bName;
	}
	string getBookName(){
		return bookName;
	}
	void setPages(string pages){
		pages=pages;
	}
	string getPages(){
		return pages;
	}
	void setPublisherName(string pName){
		publisherName=pName;
	}
	string getPublisherName() {
		return publisherName;
	}
	void setStudentList(vector<string>studentList) {
		students=studentList;
	}
	vector<string> getStudentList(){
		return students;
	}


};
