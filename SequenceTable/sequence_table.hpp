#pragma once

#ifndef _SEQUENCE_TABLE_
#define _SEQUENCE_TABLE_

#include<utility>
#include<cstdlib>
#include<exception>
#include<iostream>
#include<functional>


template<class T>
class SequenceTable
{
public:
	SequenceTable<T>():size_(0),data_(nullptr),capacity_(0) {
	}

	/// <summary>
	/// move constructor
	/// </summary>
	/// <param name="source"></param>
	/// <returns></returns>
	SequenceTable<T>(SequenceTable<T>&& source) noexcept {
		size_ = source.size_;
		capacity_ = source.capacity_;
		data_ = std::move(source.data_);
	}

	/// <summary>
	/// copy constructor
	/// </summary>
	/// <param name="source"></param>
	/// <returns></returns>
	SequenceTable<T>(SequenceTable<T>& source) noexcept {

	}

	~SequenceTable<T>() {
		delete[] data_;
	}

	/// <summary>
	/// Insert to array's front
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void unshift(const T& val) {
		if (size_ == 0 && this->allocator()) {
			data_[0] = val;
			size_++;			
			return;
		}

		if (size_ == capacity_ && this->allocator(this->size_)) {
			for (int i = 0; i < size_; i++) {
				data_[i + 1] = data_[i];
			}
			data_[0] = val;
			size_++;
			return;
		}
	}

	/// <summary>
	/// Insert to array's tail
	/// </summary>
	/// <typeparam name="T"></typeparam>
	void push_back(const T& val) {
		if (size_ == 0 && this->allocator()) {
			unshift(val);
		}
		else if (size_ < capacity_ || allocator(size_)) {
			data_[size_] = val;
		}
		size_++;
	}

	T pop() {
		if (size_ == 0) 
			throw std::out_of_range("no element in array !");
		T& e = data_[size_];
		size_--;
		return e;
	}

	/// <summary>
	/// Get element by index
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	T& at(int index) const {
		if (index < size_ && index>= 0) {
			return data_[index];
		}		
		throw std::out_of_range("argument:location out of range!");
	}

	/// <summary>
	/// overload operator[] 
	/// which allows client access  
	/// element like an C/C++ style array
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	T& operator[](int index) const {
		return at(index);
	}

	size_t get_capacity() const {
		return capacity_ * sizeof(T);
	}

	int get_size() const {
		return size_;
	}

	void Sort(std::function<bool(T,T)>& predict) {
		for (unsigned int i = 0; i <= size_; i++) {
			if (predict(data_[i], data_[i + 1])) {

			}
		}
	}
	
private:
	/// <summary>
	/// pointer for dynamic array
	/// </summary>
	T* data_;

	/// <summary>
	/// memory claimed from system
	/// </summary>
	size_t capacity_;

	/// <summary>
	/// element count
	/// </summary>
	size_t size_;

	/// <summary>
	/// claim memory from system
	/// </summary>
	/// <param name="capacity"></param>
	/// <returns></returns>
	bool allocator(size_t size = 0) {
		try {
			//brand new dynamic array
			if (size == 0) {
				data_ = new T[1];
				capacity_ = 1;
				return true;
			}
			// dynamic array is full, 
			// need allocate more memory
			else {
				int temp = (size + 1) * 2;
				T* temp_array = std::move(data_);

				data_ = nullptr;
				data_ = new T[temp];

				if (data_ != nullptr) {
					//copy element to new array
					for (unsigned int i = 0; i < size_; i++) {						
						data_[i] = temp_array[i];
					}
					capacity_ = temp;
					return true;
				}
				else {
					return false;
				}				
			}			
		}
		catch (const std::exception& e) {
			std::cout << "Exception rised£¡ Deatils:: " << e.what() << std::endl;
			return false;
		}
	}
};
#endif // !_SEQUENCE_TABLE_
