#include<iostream>
using std::cout;
using std::cerr;
namespace diy{
	template<typename _Tp>
	class SingleLinkedElement{
		private:
		_Tp _val;
		SingleLinkedElement* _next;
		SingleLinkedElement(){}
		SingleLinkedElement(_Tp val,SingleLinkedElement next=nullptr):_val(val),_next(next){}
	};
	#define _SLE SingleLinkedElement
	template<typename _Tp>
	class SingleLinkedList{
		_SLE<_Tp> _dummy;
		
	};
}