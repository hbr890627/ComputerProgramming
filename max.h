template <class T>
 
T max(T a, T b, T c){
	T maxValue=a;
	if(b>maxValue)
		maxValue=b;
	if(c>maxValue)
		maxValue=c;
	return maxValue;
}
