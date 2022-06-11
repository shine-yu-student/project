#include<iostream>
#include<string>
namespace diy{
	class UnsignedInteger{
		private:
		std::string val;
		public:
		UnsignedInteger(){}
		UnsignedInteger(const size_t &x){
			size_t __x=x;
			while(__x){
				val=char(x%10+'0')+val;
				__x/=10;
			}
		}
		UnsignedInteger(const UnsignedInteger &x){
			val=x.val;
		}
		friend std::ostream& operator<<(std::ostream& out,UnsignedInteger &_val){
			out<<_val.val;
			return out;
		}
		UnsignedInteger operator+(UnsignedInteger &x){
			UnsignedInteger ans;
			auto& i3=ans.val;
			auto i1=val.end()-1,i2=x.val.end()-1;
			while(i1>=val.begin() and i2>=x.val.begin()){
				i3=char(*i1+*i2-'0')+i3;
				i1--,i2--;
			}
			return ans;
		}
		UnsignedInteger operator-(const size_t &x){
			UnsignedInteger tmp(*this);
			size_t __x=x;
			auto i1=tmp.val.end()-1;
			while(__x){
				*i1-=__x%10;
				if(*i1<'0')*(i1-1)--;
				__x/=10,i1--;
			}
			return tmp;
		}
		//TODO: manipulate operator-,operator*,operator/
	};
}