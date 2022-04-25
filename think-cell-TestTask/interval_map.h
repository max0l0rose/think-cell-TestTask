#pragma once
#include <map>

class MyKey {
protected:
	int val;
public:
	MyKey(int v) {
		val = v;
	}

	int operator=(int v) {
		val = v;
		return v;
	}

	const bool operator<(const MyKey k2) const {
		return val < k2.val;
	}


	int getVal() const {
		return val;
	}
};


class MyVal {
protected:
	char val;
public:
	MyVal(char v) {
		val = v;
	}

	int operator=(char v) {
		val = v;
		return v;
	}

	const bool operator==(const MyVal v2) const {
		return val == v2.val;
	}


	int getVal() const {
		return val;
	}
};


template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
public:
	std::map<K, V> m_map;


	// constructor associates whole range of K with val
	interval_map(V const& val)
		: m_valBegin(val)
	{}


	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
		if (!(keyBegin<keyEnd))
			return;

		const V tmpRV = (*this)[keyEnd];

		auto itBeforeBegin = m_map.lower_bound(keyBegin);
		if (itBeforeBegin != m_map.end())
			itBeforeBegin--;

		auto itL = m_map.upper_bound(keyBegin);
		auto itR = m_map.upper_bound(keyEnd);
		for (auto itA = itL; itA != itR;)
			itA = m_map.erase(itA);

		if (itBeforeBegin == m_map.end() || !(itBeforeBegin->second->getVal() == val->getVal()))
			m_map[keyBegin] = val;

		if (itBeforeBegin == m_map.end() || !(itBeforeBegin->second->getVal() == tmpRV->getVal()))
			m_map[keyEnd] = tmpRV;
	}

	//Type requirements are met : You must adhere to the specification of the keyand value type given above.
	//For example, many solutions we receive use operations other than those that are explicitly stated in the task description.
	//We have to reject many solutions because they assume that V is default - constructible, e.g., by using std::map::operator[].


	// look-up of the value associated with key
	V const& operator[](K const& key) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		}
		else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.
