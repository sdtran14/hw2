#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author):
Product(category, name, price, qty), ISBN_(ISBN), author_(author) {};

std::set<std::string> Book::keywords() const 
{
	set<string> sName = parseStringToWords(name_);
	set<string> sAuth = parseStringToWords(author_);
	//cout<<"Author::"<<author_<<endl;

	set<string> sRes = setUnion(sAuth, sName);
	sRes.insert(ISBN_);
	return sRes;
}
std::string Book::displayString() const
{
	string res = "";
	res+= name_ + "\n";
	res+="Author: "+author_+" ISBN: "+ISBN_+"\n"  + to_string(price_) + " "  + to_string(qty_) +" left.";
	
	return res;
}
void Book::dump(std::ostream& os) const
{
	Product::dump(os);
	os << ISBN_ << "\n" << author_ << endl;
}