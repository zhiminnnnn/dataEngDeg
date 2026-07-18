template <class T>
class Rectangle
{
	private:
	 	T width;
	 	T length;
	public:
	 	void setData(T w, T l)
	 		{ width = w; length = l;}
	 	T getWidth()
	 		{ return width; }
	 	T getLength()
	 		{ return length; }
	 	T getArea()
	 		{ return width * length; }
};