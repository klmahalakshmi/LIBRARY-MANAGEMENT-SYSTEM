// import section

#include<bits/stdc++.h>
#include"Book.h"

using namespace std;


// Declaring the functions
void addBookToLibrary(string bname);
Book searchBook(string bname);
void deleteFromLibrary(string bname);
void modifyBook(Book book,string sname,bool flag);


// Method to create a book and add the book to library.
void addBook() {

		Book book;
		string bookName1;
		string publisherName1;
		string temp;
		
		getline(cin,temp);
		cout<<"Enter the Book Name :\n";
		getline(cin,bookName1);
		cout<<"Enter the Publisher name :\n";
		getline(cin, publisherName1);
		
		book.setBookName("\n"+bookName1);
		book.setPublisherName(publisherName1);

		string bookName = book.getBookName();
		string publisherName = book.getPublisherName();

		string bookDetails=bookName+","+publisherName;

		string bookFile("Book.txt");
		fstream file2;
		file2.open(bookFile,ios_base::app);
		if(file2.is_open())
		{
			file2.write(bookDetails.data(),bookDetails.size());
		}
		file2.close();
		addBookToLibrary(bookName); // after creating book, book is added to library.
}

// method for adding book to the Library.
void addBookToLibrary(string bname){
	bname="\n"+bname;
	string libraryFile("Library.txt");
	fstream file1;
	file1.open(libraryFile, ios_base::app);
    if (file1.is_open())
    {
       	file1.write(bname.data(), bname.size());
   	}
   	file1.close();
}


// method to find a book by name
void findBook(){
	string bookName;
	string temp;

	cout<<"Enter the book name you want to search: ";
	getline(cin,temp);
	getline(cin,bookName);

	searchBook(bookName);		// calling search method to search for a book.
}


Book searchBook(string bname){

	ifstream inFile("Book.txt");
	Book newbook;
    if (inFile.is_open())
    {
        string line;
        int count=0;
        while( getline(inFile,line) )
        {
            stringstream ss(line);

            string bookName, pages, publisherName;
            getline(ss,bookName,',');    
            getline(ss,publisherName,','); 

            vector<string> Students;
            string studentName;

            while(getline(ss,studentName,',') )
            {
                 Students.push_back(studentName); 
            }
         	
            if(bookName==bname)
            {
            	newbook.setBookName(bookName);
           		
            	newbook.setPublisherName(publisherName);
            	newbook.setStudentList(Students);
            	count++;

            	cout<<"Name of the Book : "<<bookName<<endl;
				cout<<"Publisher Name : "<<publisherName<<endl;
            	return newbook;

            }

        }
        if(count==0){
        	cout<<"Book does not exist with the given name."<<endl;
        }

    }
    return newbook;
}


void deleteBook(){

	string bname, temp;
	cout<<"Enter the book name you want to delete: ";
	getline(cin,temp);
	getline(cin,bname);

	string tempFile("temp.txt");
	fstream tFile;

	ifstream inFile("Book.txt");
    if (inFile.is_open())
    {
        string line;
        int count=0;
        while( getline(inFile,line) )
        {
            stringstream ss(line);

            string bookName, pages, publisherName;
            getline(ss,bookName,',');    
         
            getline(ss,publisherName,','); 

            vector<string> Students;
            string studentName;

            while(getline(ss,studentName,',') )
            {
                 Students.push_back(studentName); 
            }
         	
            if(bookName==bname)
            {
            	line.replace(0,line.length(),"");
            }
           	tFile.open(tempFile, ios_base::app);
        	if(tFile.is_open())
    		{	
    			string nline="\n";
        		tFile.write(line.data(), line.size());
        		tFile.write(nline.data(),nline.size());

    		}
    		tFile.close();

        }
        
    }
    remove("Book.txt");
    rename("temp.txt","Book.txt");
    cout<<bname <<" is deleted!!"<<endl;

    deleteFromLibrary(bname);
}

void listAllBooksInLibrary() {
	ifstream inFile("Library.txt");
	Book newbook;
    if (inFile.is_open())
    {
        string line;
        while( getline(inFile,line) )
        {
            stringstream ss(line);

            string bookName, pages, publisherName;
            getline(ss,bookName,',');    
            getline(ss,publisherName,','); 

            vector<string> Students;
            string studentName;

            while(getline(ss,studentName,',') )
            {
                 Students.push_back(studentName); 
            }
         	
            if(bookName != "")
            {
            	cout << bookName << endl;
            }
        }
    }
}

void deleteFromLibrary(string bname){

	string temp2File("temp2.txt");
	fstream tFile2;

	ifstream inFile2("Library.txt");
    if (inFile2.is_open())
    {
        string line2;
        while( getline(inFile2,line2) )
        {
            stringstream ss(line2);

            string bookName2;
            getline(ss,bookName2,',');    
         	
            if(bookName2==bname)
            {
            	line2.replace(0,line2.length(),"");
            	cout<<line2;
            }
           	tFile2.open(temp2File, ios_base::app);
        	if(tFile2.is_open())
    		{	
    			string nline2="\n";
        		tFile2.write(line2.data(), line2.size());
        		tFile2.write(nline2.data(),nline2.size());

    		}
    		tFile2.close();

        }
        
    }
    remove("Library.txt");
    rename("temp2.txt","Library.txt");
    cout<<bname <<" is deleted from Library!!"<<endl;

}

void modifyExistingBook() {
	string bookName,publisherName,temp;
	
	getline(cin,temp);
	cout<<"Enter Book Name : ";
	getline(cin,bookName);
	cout<<"Enter New Publisher Name : ";
	getline(cin,publisherName);
	Book book = searchBook(bookName);
	book.setBookName(bookName);
	book.setPublisherName(publisherName);
	modifyBook(book, "", false);
}


void modifyBook(Book book,string sname,bool flag){
	string tempFile("temp.txt");
	fstream tFile;

	ifstream inFile("Book.txt");
	if (inFile.is_open())
    {
        string line;
        int count=0;
        while( getline(inFile,line) )
        {
            stringstream ss(line);

            string bookName, pages, publisherName;
            getline(ss,bookName,',');    
            //getline(ss,pages,','); 
            getline(ss,publisherName,','); 

            vector<string> Students;
            string studentName;

            while(getline(ss,studentName,',') )
            {
        
                Students.push_back(studentName); 
            }
         	
            if(bookName==book.getBookName())
            {
            	string modifiedBookDetails=book.getBookName()+","+book.getPublisherName();

            	for(auto value:Students)
            	{
            		if(flag && value != sname){
   
            			modifiedBookDetails += (","+value);
            		}
            		else if(!flag)
            		{

            			modifiedBookDetails += (","+value);

            		}
            	}
            	if(!flag){
            		modifiedBookDetails += (","+sname);
            	}
      
            	line.replace(0,line.length(),modifiedBookDetails);
            	cout<<line;
            }
           	tFile.open(tempFile, ios_base::app);
        	if(tFile.is_open())
    		{	
    			string nline="\n";
        		tFile.write(line.data(), line.size());
        		tFile.write(nline.data(),nline.size());

    		}
    		tFile.close();

        }
        
    }
    remove("Book.txt");
    rename("temp.txt","Book.txt");
    cout<<"\n"<<book.getBookName()<<" is modified!!"<<endl;

}

//issue method

void issueBook()
{
	string studentName,bookName, temp;
	
	getline(cin,temp);
	cout<<"Enter Student Name : ";
	getline(cin,studentName);
	cout<<"Enter Book Name : ";
	getline(cin,bookName);

	Book book = searchBook(bookName);
	vector<string>studentList = book.getStudentList();

	studentList.push_back(studentName);
	book.setStudentList(studentList);
	modifyBook(book,studentName,false);

	deleteFromLibrary(bookName);
}

//return method

void returnBook(){

	string studentName,bookName,temp;
	getline(cin,temp);
	cout<<"Enter Student Name : ";
	getline(cin,studentName);
	cout<<"Enter Book Name : ";
	getline(cin,bookName);

	addBookToLibrary(bookName);


	Book b1 = searchBook(bookName);
	modifyBook(b1,studentName,true);


}

int main(){

	int value=1;
	
	while(value){

		cout<<"Select the option below!!!\n";
		cout<<"1) List all books in the library\n";
		cout<<"2) Find the details of the book\n";
		cout<<"3) Create a book\n";
		cout<<"4) Delete a book\n";
		cout<<"5) Issue a book to student\n";
		cout<<"6) Return a book back to library\n";
		cout<<"7) Modify the book details\n";
		cout<<"0) Quit the program\n";
		cout << "_________________________________________" << endl;
		cin>>value;

		switch(value) {
			case 1:
				listAllBooksInLibrary();
				break;

			case 2:
				findBook(); 
				break;

			case 3:
				addBook();
				break;

			case 4:
				deleteBook();
				break;
		
			case 5:
				issueBook();
				break;

			case 6:
				returnBook();
				break;

			case 7:
				modifyExistingBook();
				break;

			case 0:
				exit;
		}
	
	}

	return 0;
}