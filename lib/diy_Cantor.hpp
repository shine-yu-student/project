#include<iostream>
#include<cstring>
#include<assert.h>
namespace diy{
	struct UpdatingStatus{
		size_t modifyCount;
		std::string errorMessage;
	};
	auto lowbit=[](size_t sz)->size_t{return sz&-sz;};
	template<typename _Tp>
	class TreeArray{
		private:
		_Tp *__tree,*__src;
		size_t __max_size;
		public:
		TreeArray():__max_size(1e4){
			__tree=new _Tp[__max_size+1];
			__src=new _Tp[__max_size+1];
		}
		TreeArray(const size_t& _sz):__max_size(_sz){
			__tree=new _Tp[__max_size+1];
			__src=new _Tp[__max_size+1];
		}
		TreeArray(const TreeArray& _tmp){
			__max_size=_tmp.__max_size;
			memcpy(__tree,_tmp.__tree,__max_size);
			memcpy(__src,_tmp.__src,__max_size);
		}
		~TreeArray(){
			delete[] __tree;
			__tree=nullptr;
		}
		/**
		 * @brief Add _val to _src[_pos] and _tree. This function requires the operator+= in _Tp.
		 * 
		 * @param _val The element to add.
		 * @param _pos The position to add.
		 * @return UpdatingStatus Contains modifyCount and errorMessage. modifyCount will be 2^64-1 if 
		 * some error occured. Otherwise you know what it contains.
		 */
		UpdatingStatus update(const _Tp& _val,const size_t& _pos){
			__src[_pos]+=_val;
			size_t pos=_pos,cnt=0;
			if(_pos>__max_size){
				return UpdatingStatus({-1,"parameter _pos out of range"});
			}
			while(pos<=__max_size){
				__tree[pos]+=_val;
				pos+=lowbit(pos),cnt++;
			}
			return UpdatingStatus({cnt,""});
		}
		/**
		 * @brief Add _val to _src[_pos] and _tree. 
		 * This function requires the operator+= and operator- in _Tp.
		 * 
		 * @param _val The element to change.
		 * @param _pos The position to change.
		 * @return UpdatingStatus Contains modifyCount and errorMessage. modifyCount will be 2^64-1 if 
		 * some error occured. Otherwise you know what it contains.
		 */
		UpdatingStatus modify(const _Tp& _val,const size_t& _pos){
			return update(_val-__src[_pos],_pos);
		}
		/**
		 * @brief Query the sum from tree[1] to tree[_pos].
		 * This function requires default constructor and operator+= in _Tp.
		 * 
		 * @param _pos The position to query.
		 * @return _Tp The sum from tree[1] to tree[_pos].
		 */
		_Tp querySum(const size_t& _pos){
			_Tp tmp=_Tp();
			size_t pos=_pos;
			while(pos){
				tmp+=__tree[pos];
				pos-=lowbit(pos);
			}
			return tmp;
		}
	};
}