#include <iostream>
using namespace std;
class B{
	private:
		int m;
	protected:
		int n;
	public:
		void setM(int _m){
			m = _m;
		}
		int getM(){
			return m;
		}
		void setN(int _n){
			n = _n;
		}
		int getN(){
			return n;
		}
		int calc(){
			return m * n;
		}
};
class D : public B{
	private:
		double q;
	protected:
		double r;
	public:
		void setQ(int _q){
			q = _q;
		}
		int getQ(){
			return q;
		}
		void setR(int _r){
			r = _r;
		}
		int getR(){
			return r;
		}
		int calc(){
			return q * r;
		}
};
int main(){
	B *b = new B;
	b->setM(10);
	b->setN(20);
	cout << b->getM() << endl;
	cout << b->getN() << endl;
	cout << b->calc() << endl << endl;
	D *d = new D;
	d->setQ(30);
	d->setR(40);
	cout << d->getQ() << endl;
	cout << d->getR() << endl;
	cout << d->calc() << endl;
}