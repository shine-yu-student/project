#include<iostream>
#include<vector>
namespace diy{
	/**
	 * @brief It does what you think.
	 * 
	 * @tparam _Tp 
	 * @param list the list to find.
	 * @param val the value to find.
	 * @return int who represents the index start from 1,-1 if does not exists.
	 */
	template<typename _Tp>
	int linearSearch(std::vector<_Tp> list,_Tp val){
		size_t pos=0;
		for(auto &i:list){
			if(i==val)return pos+1;
			pos++;
		}
		return -1;
	}
	//TODO: make the binary function complete 2022-6-6
	template<typename _Tp>
	int binarySearch(std::vector<_Tp> list,_Tp val){

	}
}