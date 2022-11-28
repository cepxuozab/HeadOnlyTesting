#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T>
void Serialize(T pod, std::ostream& out) {
	out.write(reinterpret_cast<const char*>(&pod), sizeof(pod));
}

void Serialize(const std::string& str, std::ostream& out) {
	Serialize(str.size(), out);
	out.write(reinterpret_cast<const char*>(str.data()), str.size());
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out);

template <typename T>
void Serialize(const std::vector<T>& data, std::ostream& out) {
	Serialize(data.size(), out);
	for (const auto& elem : data) {
		Serialize(elem, out);
	}
}

template <typename T1, typename T2>
void Serialize(const std::map<T1, T2>& data, std::ostream& out) {
	Serialize(data.size(), out);
	for (const auto& [key, value] : data) {
		Serialize(key, out);
		Serialize(value, out);
	}
}

template <typename T>
void Deserialize(std::istream& in, T& pod) {
	in.read(reinterpret_cast<char*>(&pod), sizeof(pod));
}

void Deserialize(std::istream& in, std::string& str) {
	size_t size;
	Deserialize(in, size);
	str.resize(size);
	in.read(reinterpret_cast<char*>(str.data()), size);
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data);

template <typename T>
void Deserialize(std::istream& in, std::vector<T>& data) {
	size_t size;
	Deserialize(in, size);
	data.resize(size);
	for (auto& v : data) {
		Deserialize(in, v);
	}
}

template <typename T1, typename T2>
void Deserialize(std::istream& in, std::map<T1, T2>& data) {
	size_t size;
	Deserialize(in, size);
	for (size_t i = 0; i != size; ++i) {
		T1 first;
		Deserialize(in, first);
		T2 second;
		Deserialize(in, second);
		data[std::move(first)] = std::move(second);
	}
}








