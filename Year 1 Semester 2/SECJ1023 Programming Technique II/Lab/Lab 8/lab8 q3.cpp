class B{
	private:
		int m;
	protected:
		int n;
	public:
		void setM(int m){
			this->m = m;
		}
		int getM(){
			return m;
		}
		void setN(int n){
			this->n = n;
		}
		int getN(){
			return n;
		}
		int calc(){
			return m * n;
		}
};

class D : public B{
	protected:
		float q, r;
	public:
		void setQ(int q){
			this->q = q;
		}
		int getQ(){
			return q;
		}
		void setR(int r){
			this->r = r;
		}
		int getR(){
			return r;
		}
		int calc(){
			return q * r;
		}
};