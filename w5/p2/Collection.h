/*
******************************************************
Full Name  : Ankita Chandel
Student ID#: 161317219
Email      : achandel1@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
******************************************************
*/
#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
	template <typename T>
	class Collection {
		std::string collecName{};
		T* items{ nullptr };
		size_t arrSize{ 0 };
		void (*m_observer)(const Collection<T>&, const T&) { nullptr };

	public:
		Collection() {}
		Collection(const std::string& name) {
			if (!name.empty()) {
				collecName = name;
			}
		}

		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		Collection(Collection&& src) = delete;
		Collection& operator=(Collection&& src) = delete;
		~Collection() {
			if (items != nullptr)
			{
				delete[]items;
				items = nullptr;
			}
		}

		const std::string& name()const {
			return collecName;
		}

		size_t size()const {
			return arrSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool isExist = false;
			for (size_t i = 0; i < arrSize && !isExist; i++)
			{
				if (items[i].title() == item.title())
					isExist = true;
			}
			if (!isExist)
			{
				Collection temp;
				temp.arrSize = arrSize + 1;
				temp.items = new T[temp.arrSize];
				for (size_t i = 0; i < arrSize; i++)
				{
					temp.items[i] = items[i];
				}
				temp.items[arrSize] = item;

				if (items != nullptr)
				{
					delete[] items;
					items = nullptr;
				}
				arrSize++;
				items = new T[arrSize];
				for (size_t i = 0; i < arrSize; i++)
				{
					items[i] = temp.items[i];
				}
				delete[] temp.items;
				temp.items = nullptr;

				//call back the obsever function if item addtion is successful and the observation registered
				if (m_observer != nullptr)
				{
					m_observer(*this, item);
				}
			}

			return *this;
		}

		T& operator[](size_t idx)const {
			//if idx out of range, throw an out_of_range exception with msg
			if (idx >= arrSize)
			{
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(arrSize);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return items[idx];
		}

		T* operator[](const std::string& title)const {
			size_t i = 0;
			bool found = false;
			for (; i < arrSize && !found; i++)
			{
				if (items[i].title() == title)
				{
					found = true;
				}
			}
			return found ? &items[i - 1] : nullptr;
		}

	};
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
		for (size_t i = 0; i < collection.size(); i++)
		{
			os << collection[i];
		}
		return os;
	}
}
#endif // !COLLECTION_H