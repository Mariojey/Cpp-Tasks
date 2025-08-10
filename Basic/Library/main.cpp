#include <iostream>
#include <vector>

using namespace std;

class Book {

private:
    string Author;
    int Year;
protected:
    string Title;
    string ISBN;
public:

    void setTitle(string title){
        Title = title;
    }

    string getTitle() {
        return Title;
    }

    void setAuthor(string author) {
        Author = author;
    }

    string getAuthor(){
        return Author;
    }

    void setYear(int year){
        Year = year;
    }

    int getYear(){
        return Year;
    }

    void setISBN(string nr_isbn){
        ISBN = nr_isbn;
    }

    string getISBN(){
        return ISBN;
    }

    Book(string title, string author, int year, string nr_isbn){
        
        Title = title;
        Author = author;
        Year = year;
        ISBN = nr_isbn;
    
    }

    void printInfo(){
        cout<<"Title: "<<Title<<endl;
        cout<<"Author: "<<Author<<endl;
        cout<<"Release: "<<Year<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
    }
};

class Library {

private:
    vector<Book> books;
public:
    void addBook(const Book& book){
        books.push_back(book);
    }
    
    void removeBookByISBN(const string& nr_isbn){
        int position = 0;
        for(Book &book: books){
            if (book.getISBN() == nr_isbn)
            {
                break;
            }else{
                position ++;
            }
        }
        if(position < books.size()){
            books.erase(books.begin() + position);
        }
    }

    Book* findBookByTitle(const string& title){
        for(Book &book: books){
            if(book.getTitle() == title){
                return &book;
            }
        }
        return nullptr;
    }

    void printAllBooks(){
        cout<<"BOOKS: "<<endl;
        for(Book &book: books){
            cout<<book.getAuthor()<<" - '"<<book.getTitle()<<"'"<<endl;
        }
    }
};

int main(){

    Book Lotr = Book("Lord Of The Rings","J.R.R Tolkien",1949,"0001");
    cout<<Lotr.getAuthor()<<endl;
    Lotr.printInfo();

    Library lib;
    lib.addBook(Book("Władca Pierścieni", "J.R.R. Tolkien", 1954, "12345"));
    lib.addBook(Book("Hobbit", "J.R.R. Tolkien", 1937, "67890"));

    lib.printAllBooks();

    Book* found = lib.findBookByTitle("Hobbit");
    if(found){
        cout<<"\nZnaleziono ksiązkę:\n";
        found->printInfo();
    }
    return 0;
}