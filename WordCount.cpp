// WordCount.cpp

#include "WordCount.h"
#include <sstream>
#include <unordered_map>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}


int WordCount::getTotalWords() const {
	int ret = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(const auto &pair : table[i]){
			ret += pair.second;
		}
	}
	return ret;
}



int WordCount::getNumUniqueWords() const {
	// STUB
	//return -1;
	int ret = 0;
	for(size_t i =0; i < CAPACITY; i++){
		ret += table[i].size();
	}
	return ret;
}

// int WordCount::getWordCount(std::string word) const {
// 	// STUB - your solution from Lab06 goes here
// 	return -1;
// }
	
// int WordCount::incrWordCount(std::string word) {
// 	// STUB - your solution from Lab06 goes here
// 	return -1;
// }

// int WordCount::decrWordCount(std::string word) {
// 	// STUB - your solution from Lab06 goes here
// 	return -2;
// }


// bool WordCount::isWordChar(char c) {
// 	// STUB - your solution from Lab06 goes here
// 	return false;
// }

// std::string WordCount::makeValidWord(std::string word) {
// 	// STUB - your solution from Lab06 goes here
// 	return "";
// }


int WordCount::getWordCount(std::string word) const {
	// STUB
	// return -1;
	word = makeValidWord(word);
	if(word.empty()){
		return 0;
	}
	size_t index = hash(word);
	for(const auto &pair : table[index]){
		if(pair.first == word){
			return pair.second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	// STUB
	// return -1;
	word = makeValidWord(word);
	if(word.empty()){
		return 0;
	}
	size_t index = hash(word);
	for(auto&pair : table[index]){
		if(pair.first == word){
			++pair.second;
			return pair.second;
		}
	}
	table[index].push_back(std::make_pair(word,1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
		word = makeValidWord(word);
	if (word.empty()){
		return -1;
	}

	size_t index = hash(word);
	for (auto i = table[index].begin(); i != table[index].end(); ++i) {
		if (i->first == word) {
			if (i->second > 1) {
				--i->second;
				return i->second;
			} 
			else {
				table[index].erase(i);
				return 0;
			}
		}
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	string ret;
	for (size_t i = 0; i < word.size(); ++i) {
        if (isalpha(word[i])) {
            ret += tolower(word[i]);
        } 
		else if ((word[i] == '-' || word[i] == '\'') && i > 0 && i < word.size() - 1) {
			 if (isalpha(word[i - 1]) && isalpha(word[i + 1])) {
                ret += word[i];
            }
        }
    }
    return ret;;
}


void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// // STUB
	// return "";
	vector<pair<string, int>> Word;

	
    for (size_t i = 0;i < CAPACITY; ++i) {
        for (const auto &pair :table[i]) {
            Word.push_back(pair);
        }
    }
    sort(Word.begin(),Word.end(),[](const pair<string, int> &a,const pair<string,int> &b) {
		return a.first> b.first;
		} 
	);

    for (const auto &entry : Word) {
        out << entry.first << "," << entry.second <<"\n";
    }
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// // STUB
	// return "";
	vector<pair<string, int>> Occurence;
	for (size_t i =0; i< CAPACITY; ++i) {
        for (const auto &pair : table[i]) {
            Occurence.push_back(pair);
        }
	}
	sort(Occurence.begin(), Occurence.end(),[](const pair<string, int> &a,const pair<string,int> &b) {
        if (a.second!= b.second) {
        	return a.second <b.second; 
        }
        return a.first< b.first;
		}
	);
	for (const auto &entry :Occurence) {
        out << entry.first << ","<< entry.second << "\n";
    }
}

void WordCount::addAllWords(std::string text) {
	// // STUB
	// return;
	istringstream iss(text);
	string word;
	while(iss>>word){
		word = makeValidWord(word);
		if(!word.empty()){
			incrWordCount(word);
		}
	}
}
