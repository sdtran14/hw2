
#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "util.h"
#include "user.h"


class MyDataStore : public DataStore {
	public:
		MyDataStore();
		~MyDataStore();	
		//void printMap();
		virtual void addProduct(Product* p);
		void buyCart(std::string un);
		void addCart(std::string un, Product* p);
		void viewCart(std::string un);
		virtual void addUser(User* u);
		virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
		virtual void dump(std::ostream& ofile);

		std::set<Product*> pset;
		std::map<std::string, User*> uset;
		std::map<User*, std::queue<Product*>> carts;
		std::map<std::string, std::set<Product*>> m;
	
		

};
#endif