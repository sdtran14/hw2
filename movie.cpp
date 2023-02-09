#include <sstream>
#include <iomanip>
#include <string>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string rating, std::string genre):
Product(category, name, price, qty), genre_(genre), rating_(rating) {};

std::set<std::string> Movie::keywords() const 
{
	set<string> sName = parseStringToWords(name_);
	//sName.insert(genre_);
	set<string> sGenre = parseStringToWords(genre_);
	set<string> sRes = setUnion(sGenre, sName);
	sRes.insert(genre_);
	return sRes;
}
std::string Movie::displayString() const
{
	string res = "";
	res+= name_ + "\n";
	res+="Genre: "+genre_+ " Rating: "+rating_+ "\n"  + to_string(price_) + " "  + to_string(qty_) +" left.";
	
	return res;
}
void Movie::dump(std::ostream& os) const
{
	Product::dump(os);
	os << genre_ << "\n" << rating_ << endl;
}