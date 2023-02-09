#include <sstream>
#include <iomanip>
#include <string.h>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
Product(category, name, price, qty), size_(size), brand_(brand) {};

std::set<std::string> Clothing::keywords() const 
{
	set<string> sName = parseStringToWords(name_);
	set<string> sBrand = parseStringToWords(brand_);
	set<string> sRes = setUnion(sBrand, sName);
	//sRes.insert(brand_);
	return sRes;
}
std::string Clothing::displayString() const
{
	string res = "";
	res+= name_ + "\n";
	res+="Size: "+size_+" Brand: "+brand_+"\n" + to_string(price_) + " "  + to_string(qty_) +" left.";
	return res;
}
void Clothing::dump(std::ostream& os) const
{
	Product::dump(os);
	os << size_ << "\n" << brand_ << endl;
}