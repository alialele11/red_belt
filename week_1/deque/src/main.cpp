#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Deque{
public:
	Deque(){}
	bool Empty() const{
		if(vec_front.empty() && vec_back.empty()){
			return true;
		}
		else{
			return false;
		}
	}
	size_t Size() const{
		return vec_front.size() + vec_back.size();
	}
	T& operator [](size_t index){
		if(index < vec_front.size()){
			return vec_front[vec_front.size() - 1 - index];
		}
		else{
			return vec_back[index - vec_front.size()];
		}
	}
	const T& operator [](size_t index) const{
		if(index < vec_front.size()){
			return vec_front[vec_front.size() - 1 - index];
		}
		else{
			return vec_back[index - vec_front.size()];
		}
	}
	T& At(size_t index){
		if(index >= Size()){
			throw out_of_range("");
		}
		else{
			if(index < vec_front.size()){
				return vec_front[vec_front.size() - 1 - index];
			}
			else{
				return vec_back[index - vec_front.size()];
			}
		}
	}
	const T& At(size_t index) const{
		if(index >= Size()){
			throw out_of_range("");
		}
		else{
			if(index < vec_front.size()){
				return vec_front[vec_front.size() - 1 - index];
			}
			else{
				return vec_back[index - vec_front.size()];
			}
		}
	}
	T& Front(){
		if(vec_front.empty()){
			return vec_back.front();
		}
		else{
			return vec_front.back();
		}
	}
	const T& Front() const{
		if(vec_front.empty()){
			return vec_back.front();
		}
		else{
			return vec_front.back();
		}
	}
	T& Back(){
		if(vec_back.empty()){
			return vec_front.front();
		}
		else{
			return vec_back.back();
		}
	}
	const T& Back() const{
		if(vec_front.empty()){
					return vec_front.front();
				}
				else{
					return vec_back.back();
				}
	}
	void PushFront(T item){
		vec_front.push_back(item);
	}
	void PushBack(T item){
		vec_back.push_back(item);
	}
private:
	vector<T> vec_front;
	vector<T> vec_back;
};

int main() {

    return 0;
}


