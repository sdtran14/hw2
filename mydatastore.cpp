#include <string>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include "util.h"
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "mydatastore.h"

using namespace std;

	MyDataStore::MyDataStore() 
	{

	}
	MyDataStore::~MyDataStore() 
	{

	}
	void MyDataStore::viewCart(std::string un) 
	{
		
	}
	void MyDataStore::buyCart(string un) 
	{
		User* cu = uset[un];
		Product* curr = carts[cu].front();
		while(!carts[cu].empty())
		{
			if(curr->getQty() > 0 && cu->getBalance() >= curr->getPrice()) 
			{
				//cout<<"Before: "<<curr->getQty()<<endl;
				//cout<<"Before: "<<cu->getBalance()<<endl;
				curr->subtractQty(1);
				cu->deductAmount(curr->getPrice());
				carts[cu].pop();
				//cout<<"After: "<<curr->getQty()<<endl;
				//cout<<"After: "<<cu->getBalance()<<endl;
				curr = carts[cu].front();
			} else break;
		}
		
	}
	void MyDataStore::addCart(string un, Product* p) 
	{
		carts[uset[un]].push(p);
	}	
	void MyDataStore::addProduct(Product* p) 
	{
			set<string> s = p->keywords();
			set<string>::iterator i;
			for(i = s.begin(); i!=s.end(); i++) 
			{
				m[*i].insert(p);
				//cout<<"put "<< p->getName()<<" in "<<*i<<endl;
			}
			pset.insert(p);
			//cout<<"inserted: "<<p->getName()<<endl;

	}
	void MyDataStore::addUser(User* u) 
	{
			uset[u->getName()] = u;
	}
	/*
	void MyDataStore::printMap()
	{
		for(auto i: m) 
		{
			
			cout<<"key"<<i.first<<endl;
			cout<<"vals:";
			for(auto k : i.second) 
			{
				cout<<k->getName()<<endl;
			}


		}
	}
	*/
	std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) 
	{

		
		vector<set<Product*>> slist;
		set<Product*> res;
		vector<Product*> result;
		if(terms.size() != 0) {
		for(int i = 0; i<(signed)terms.size(); i++) {
			slist.push_back(m[terms[i]]);
		}

		
		res = slist[0];
		set<Product*>::iterator i;
		
		cout<<endl;
		//cout<<"sls:"<<slist.size()<<endl;
		for(int in = 1; in<(signed)slist.size(); in++) 
		{
			if(type) res = setUnion(res, slist[in]);
			else res = setIntersection(res, slist[in]);
			
		
		}
		//set<Product*>::iterator i;
		for(i = res.begin(); i!=res.end(); i++) 
		{
			result.push_back(*i);
		}
		}
		
		return result;
		
	}
void MyDataStore::dump(std::ostream& ofile) 
{
	set<Product*>::iterator i;
	ofile << "<products>"<<endl;
	for(i = pset.begin(); i!=pset.end(); i++) 
			{
				(*i)->dump(ofile);
				delete (*i);
			}
	ofile << "</products>"<<endl;
	ofile << "<users>"<<endl;
	std::map<std::string, User*>::iterator it;
	for(it = uset.begin(); it!=uset.end(); it++) 
			{
				((*it).second)->dump(ofile);
				delete (*it).second;
			}
	ofile << "</users>"<<endl;
	
}

